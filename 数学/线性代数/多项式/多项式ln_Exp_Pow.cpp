#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const int N = 1e5 + 10;

struct Complex {
    double x, y;
    Complex(double a = 0, double b = 0): x(a), y(b) {}
    Complex operator + (const Complex &rhs) { return Complex(x + rhs.x, y + rhs.y); }
    Complex operator - (const Complex &rhs) { return Complex(x - rhs.x, y - rhs.y); }
    Complex operator * (const Complex &rhs) { return Complex(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x); }
    Complex conj() { return Complex(x, -y); }
} w[N];

ll mod, inv2;
int tr[N];
ll F[N], G[N];

ll quick_pow(ll a, ll b) ;

int getLen(int n) ;

void FFT(Complex *A, int len) ;

inline void MTT(ll *x, ll *y, ll *z, int len) ;

void Get_Inv(ll *f, ll *g, int n) ;

void Get_Der(ll *f, ll *g, int len) { for(int i = 1;i < len; i++) g[i - 1] = f[i - 1] * i % mod; g[len - 1] = 0; }

void Get_Int(ll *f, ll *g, int len) { for(int i = 1;i < len; i++) g[i] = f[i - 1] * quick_pow(i, mod - 2) % mod; g[0] = 0; }

void Get_Ln(ll *f, ll *g, int n) {
    static ll a[N], b[N];
    Get_Der(f, a, n);
    Get_Inv(f, b, n);
    int len = getLen(n);
    MTT(a, b, a, len);
    Get_Int(a, g, len);
    for(int i = n;i < len; i++) g[0] = 0;
    for(int i = 0;i < len; i++) a[i] = b[i] = 0;
}

void Get_Exp(ll *f, ll *g, int n) {
    if(n == 1) return (void)(g[0] = 1);
    Get_Exp(f, g, (n + 1) >> 1);
    
    static ll a[N];
    Get_Ln(g, a, n);
    a[0] = (f[0] + 1 - a[0] + mod) % mod;
    for(int i = 1;i < n; i++) a[i] = (f[i] - a[i] + mod) % mod;
    int len = getLen(n);
    MTT(a, g, g, len);
    for(int i = n;i < len; i++) g[i] = 0;
    for(int i = 0;i < len; i++) a[i] = 0;
}

void Get_Pow(ll *f, ll *g, int n, ll k) {
    static ll a[N];
    Get_Ln(f, a, n);
    for(int i = 0;i < n; i++) a[i] = a[i] * k % mod;
    Get_Exp(a, g, n);
    int len = getLen(n);
    for(int i = n;i < len; i++) g[i] = 0;
    for(int i = 0;i < len; i++) a[i] = 0;
}