
#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1);

struct Complex {
    double r, i;
    Complex() {r == 0; i = 0;};
    Complex(double real, double imag) : r(real), i(imag) {};
}A[N], B[N];

Complex operator + (Complex a, Complex b) { return Complex(a.r + b.r, a.i + b.i);}
Complex operator - (Complex a, Complex b) { return Complex(a.r - b.r, a.i - b.i);}
Complex operator * (Complex a, Complex b) { return Complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);}


// 递归
// void FFT(Complex *a, int lim) { 
//     if(lim == 1) return ;
//     Complex a0[lim >> 1], a1[lim >> 1];
//     for(int i = 0;i < lim; i += 2) {
//         a0[i >> 1] = a[i];
//         a1[i >> 1] = a[i + 1];   
//     }
//     FFT(a0, lim >> 1);
//     FFT(a1, lim >> 1);
//     Complex wn = Complex(cos(2.0 * PI / lim), sin(2.0 * PI / lim)); // 主n次单位根
//     Complex w = Complex(1, 0); // 旋转因子
//     for(int k = 0;k < (lim >> 1); k++) {
//         Complex t = w * a1[k]; // 蝴蝶操作
//         a[k] = a0[k] + t;
//         a[k + (lim >> 1)] += a0[k] - t;
//         w = w * wn;
//     } 
// }

// 高效FFT迭代

const int N = 1e5 + 10;

int rev[N], len, lim = 1;

void FFT(Complex *a, int len, int opt) {
    for(int i = 0;i < len; i++) {
        if(i < rev[i]) 
            swap(a[i], a[rev[i]]);
    }
    for(int dep = 1;dep <= log2(len); dep++) {
        int m = 1 << dep;
        Complex wn = Complex(cos(2.0 * PI / m), opt * sin(2.0 * PI / m));
        for(int k = 0;k < len; k += m) {
            Complex w = Complex(1, 0);
            for(int j = 0;j < m / 2; j++) {
                Complex t = w * a[k + j + m / 2];
                Complex u = a[k + j];
                a[k + j] = u + t;
                a[k + j + m / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if(opt == -1) { // 逆变换
        for(int i = 0;i < len; i++) a[i].r = (int)(a[i].r / len + 0.5);
    }
}

void mul(Complex *a, Complex *b, int n) {
    int len = 1; while(len <= n) len <<= 1;
    for(int i = 0;i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
    FFT(a, len, 1); FFT(b, len, 1);
    for(int i = 0;i < len; i++) a[i] = a[i] * b[i];
    FFT(a, len, -1);
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0;i <= n; i++) cin >> A[i].r;
    for(int i = 0;i <= m; i++) cin >> B[i].r;
    
    mul(A, B, n + m);

    for(int i = 0;i < 2 * n; i++) cout << A[i].r << endl;
}