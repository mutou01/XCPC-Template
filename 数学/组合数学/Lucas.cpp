// p一定为质数
typedef long long ll;
const int N = 1e7 + 10;

ll p; // C(n,m) % p

ll f[N], inv[N], invF[N];

void Init()
{
    f[0] = f[1] = inv[0] = inv[1] = invF[0] = invF[1] = 1;
    for(int i = 2;i <= p; i++)
    {
        f[i] = f[i - 1] * i % p;
        inv[i] = p - (p / i) * inv[p % i] % p;
        invF[i] = invF[i - 1] * inv[i] % p;
    }
}

ll C(ll m, ll n) {
    if(m < 0 || n < 0 || n > m)
        return 0;
    ll ans = f[m];
    ans = ans * invF[n] % p;
    ans = ans * invF[m - n] % p;
    return ans;
}

ll Lucas(ll m, ll n) {
    return n ? Lucas(m / p, n / p) * C(m % p, n % p) % p : 1;
}

int main()
{
    ll m, n;
    cin >> m >> n >> p;
    Init();
    cout << Lucas(m, n) << endl;
}
