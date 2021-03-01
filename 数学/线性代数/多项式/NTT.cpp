#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll mod = 998244353, g = 3;
const int N = 1e5 + 10;
ll A[N], B[N];


ll quick_pow(ll a, ll b) ;

int rev[N];

void NTT(ll *a, int len, int opt) {
    for(int i = 0;i < len; i++) {
        if(i < rev[i]) 
            swap(a[i], a[rev[i]]);
    }
    for(int dep = 1;dep <= log2(len); dep++) {
        int m = 1 << dep;
        ll wn = quick_pow(g, (mod - 1) / m) % mod;
        if(opt == -1)
            wn = quick_pow(wn, mod - 2);
        for(int k = 0;k < len; k += m) {
            ll w = 1;
            for(int j = 0;j < m / 2; j++) {
                ll t = w * a[k + j + m / 2] % mod;
                ll u = a[k + j];
                a[k + j] = (u + t) % mod;
                a[k + j + m / 2] = (u - t + mod) % mod;
                w = w * wn % mod;
            }
        }
    }
    if(opt == -1) { // 逆变换
        int inv = quick_pow(len, mod - 2);
        for(int i = 0;i < len; i++) a[i] = a[i] * inv % mod;
    }
}

void mul(ll *a, ll *b, int n) {
    int len = 1; while(len <= n) len <<= 1;
    for(int i = 0;i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
    NTT(a, len, 1); NTT(b, len, 1);
    for(int i = 0;i < len; i++) a[i] = a[i] * b[i] % mod;
    NTT(a, len, -1);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0;i < n; i++) cin >> A[i];
    for(int i = 0;i < m; i++) cin >> B[i];
    
    mul(A, B, n + m);

    for(int i = 0;i < n + m; i++) 
        cout << A[i] << " ";
}