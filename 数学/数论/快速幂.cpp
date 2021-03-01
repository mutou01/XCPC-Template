
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// 快速幂
ll quick_pow(ll a, ll b, ll mod)
{
    ll ans = 1, base = a;
    while(b != 0)
    {
        if(b & 1)
        {
            ans = ans * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}


// 快速乘和中国剩余定理搭配更香哦
ll ksc(ll a, ll b, ll mod) // 转化成二进制一位一位对应乘 
{
    ll ans = 0;
    while(b > 0)
    {
        if(b & 1)
        {
            ans = (ans + a) % mod;
        }
        a = (a << 1) % mod;
        b >>= 1;
    }
    return ans;
}

ll quick_mul(ll a,ll b,ll c)
{
    return (a * b - (ll)((ld)a * b / c) * c + c) % c;
}


// 矩阵快速幂
#define maxn 105

const int mod = 9973;
int k, n; // k是幂，n是n*n的矩阵
ll a[maxn][maxn], temp[maxn][maxn], ans[maxn][maxn];

void Mul(ll *a,ll *b,int mod) // 矩阵乘法
{   
    memset(temp , 0 , sizeof(temp)); // 临时矩阵
    for(int i = 1;i <= n; i++)
        for(int j = 1;j <= n; j++)
            for(int k = 1;k <= n; k++)
            {
                temp[i][j] = (temp[i][j] + temp[i][k] * temp[k][j]) % mod;
            }
    for(int i = 1;i <= n; i++)
        for(int j = 1;j <= n; j++)
            a[i][j] = temp[i][j];
}

void matrix_quick_pow(ll *a,int x) // 矩阵快速幂
{
    memset(ans , 0 , sizeof(ans));
    // 记得初始化ans
    for(int i = 1;i <= n; i++)
    {
        ans[i][i] = 1; //单位矩阵初始化，要注意将对角线赋值成1
    }
    while(x)
    {
        if(x & 1)
        {
            Mul(ans , a , mod);
        }
        Mul(a , a , mod);
        x >>= 1;
    }
}
// 最后结果存储在ans里