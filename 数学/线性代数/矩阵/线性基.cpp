
// 每个异或值都相同，个数都为2^n-r,所以不同的异或值有2^r个. 
#include <bits/stdc++.h>
using namespace  std;

typedef long long ll;
const int maxl = 60;
ll quick_pow(ll a, ll b) ;
struct LinearBasis {
    ll a[maxl + 1];
    int size;
    vector<int> v;

    LinearBasis() {
        memset(a, 0, sizeof(a));
        size = 0;
        v.clear();
    }

    void insert(ll t) {
        for (int i = maxl; i >= 0; --i) {
            if (!(t >> i & 1)) continue;
            if (a[i]) t ^= a[i];
            else {
                ++size;
                for (int j = 0; j < i; ++j) if (t >> j & 1) t ^= a[j];
                for (int j = i + 1; j <= maxl; ++j) if (a[j] >> i & 1) a[j] ^= t;
                a[i] = t;
                return;
            }
        }
    }

    void basis() {
        for (int i = 0; i <= maxl; ++i) if (a[i]) v.push_back(i);
    }

    ll rank(ll x) {
        ll ret = 0;
        for (int i = 0; i < v.size(); ++i) if (x >> v[i] & 1) ret += 1LL << i;
        return ret;
    }
};


void solve() {
    int n, x, q;
    scanf("%d", &n);
    LinearBasis lb;
    for (int i = 0; i < n; ++i) scanf("%d", &x), lb.insert(x);
    lb.basis();
    scanf("%d", &q);
    ll num = quick_pow(2, n - lb.size);
    printf("%lld\n", (lb.rank(q) * num + 1));
}