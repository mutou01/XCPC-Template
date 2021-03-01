#include  <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

ll fac[N];
int a[N]; // 排列，康托展开求解
int n;
ll x; // 逆康托展开求解

void Get_F() {
    fac[0] = 1;
    for(int i = 1;i < N; i++)
        fac[i] = fac[i - 1] * i % mod;
}

ll CanTor() {
    ll ans = 0;
    for(int i = 1;i <= n; i++) {
        ll smaller = 0;
        for(int j = i + 1;j <= n; j++) {
            if(a[j] < a[i])
                smaller++;
        }
        ans = (ans + fac[n - i] * smaller % mod) % mod;
    }
    return ans + 1;
}

void DeCantor() {
    vector<int> v; // 存放当前可选数
    vector<int> a; // 所求的排列组合序
    for(int i = 1;i <= n; i++) {
        v.push_back(i);
    }
    for(int i = n;i >= 1; i--) {
        int r = x % fac[i - 1];
        int t = x / fac[i - 1];
        x = r;
        sort(v.begin(), v.end());
        a.push_back(v[t]);
        v.erase(v.begin() + t);
    }
    for(int i = 0;i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}