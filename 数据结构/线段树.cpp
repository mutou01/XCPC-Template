

// 线段树（二叉树）
 
const int MAX = 1e5 + 10; // 结点数
/*u为当前结点*/
#define lc u << 1 // 当前点的左儿子
#define rc u << 1 | 1 // 当前点的右儿子
#define m (l + r) / 2 // 区间端点分开值 [l , r] = [l , m] + [m + 1 , r]
#define mid (t[u].l + t[u].r) / 2 // 选择进入左子树还是右子树的标记
 
/*--------------单点修改和查询问题---------------*/
 
struct SegmentTree
{
    int l, r, sum; // 左结点，右结点，和
}t[MAX << 2]; // 位运算，开的空间是结点数*4，位运算
 
int a[MAX]; // 题目给的数据，用数组保存
 
/*---建树---*/
 
void build(int u,int l,int r) // u为当前结点，当前区间为[l , r]
{
    t[u].l = l;
    t[u].r = r;
    if(l == r) // 到达了最后的叶结点
    {
        t[u].sum = a[l]; // 当前区间端点l表示数组中的位置，所以当前结点的值就为a[l]
        return ;
    }
    build(lc , l , m); // 建立左子树，lc为当前结点，当前区间[l , m]
    build(rc , m + 1 , r); // 建立右子树，rc为当前结点，当前区间[m + 1 , r]
    t[u].sum = t[lc].sum + t[rc].sum; // 更新当前点的和
    
    /*--当前区间[l , r]的和可由它的子区间[l , m]和[m + 1 , r]的和得到--*/
}
 
/*---单点修改---*/
 
void update(int u, int p,int v)
{
    if(t[u].l == t[u].r) // 当前点为叶结点
    {
        t[u].sum += v;
        return ;
    }
    /*int mid = (t[u].l + t[u].r) / 2;*/ // 左子树为[l , mid]，右子树为[mid + 1 , r]
    if(p <= mid)
        update(lc , p , v); // 如果当前点在左子树中，就进入左子树
    else
        update(rc , p , v); // 如果当前点在右子树中，就进入右子树
    t[u].sum = t[lc].sum + t[rc].sum; // 更新完值之后要更新区间和
}
 
/*---区间查询---*/
 
int query(int u,int ql,int qr) // 当前点u，需查询区间[ql , qr]
{
    if(ql <= t[u].l && t[u].r <= qr) // 若需查询区间包含当前区间
        return t[u].sum; // 则直接返回当前区间和
    /*int mid = (t[u].l + t[u].r) / 2;*/ // 左子树为[l , mid]，右子树为[mid + 1 , r]
    int res = 0; // 记录查询答案
    if(ql <= mid)
        res += query(lc , ql , qr); // 左子树[l , mid]和[ql , qr]有交集，进入左子树
    if(qr > mid)
        res += query(rc , ql , qr); // 右子树[mid + 1,r]和[ql , qr]有交集，进入右子树
    /*--因为没有更新结点的值，所以不用加t[u].sum = t[lc].sum + t[rc].sum;--*/
    return res; // 返回答案
}
 
/*-----------------区间修改和查询问题-------------------*/
 
/*--记录--*/
 
struct SegmentTree
{
    int l ,r;
    ll sum, tag;
    void upd(ll v)
    {
        sum += 1ll * (r - l + 1) * v; // 若是乘->sum *= v; v是区间需要增加的值，当前区间元素个数*v
        tag += v; // 标记该点(若是乘tag *= v)
    } // tag就是延时标记
/*延时标记就是，你不用查的时候我就不下传，只有要往下查的时候，我才会更新，用就传递，不用就放那里。这样大大减少了我们的修改次数。*/
}t[MAX << 2];
ll a[MAX];
 
/*---很简单的更新当前结点的值---*/
 
void push_up(int u) // 有的时候要多次使用，所以写成函数更简洁
{
    t[u].sum = t[lc].sum + t[rc].sum;
}
 
/*---建树---*/
 
void build(int u,int l,int r)
{
    t[u].l = l;
    t[u].r = r;
    t[u].tag = 0; // 加上v的时候赋为0，乘上v的时候赋为1
    if(l == r)
    {
        t[u].sum = a[l];
        return ;
    }
    build(lc , l , m);
    build(rc , m + 1, r);
    push_up(u);
}
 
/*---区间修改---*/
 
void push_down(int u) // 标记下传
{
    if(t[u].tag) // 如果有标记就下传
    {
        t[lc].upd(t[u].tag); // 传给左子树
        t[rc].upd(t[u].tag); // 传给右子树
        t[u].tag = 0; // 标记清空
    }
}
 
void update(int u,int ql,int qr,ll v) // 当前结点u，修改的区间[ql , qr], 修改的值v
{
    if(ql <= t[u].l && t[u].r <= qr)
    {
        t[u].upd(v);
        return ;
    }
    // 若能到达这一步，说明区间没有完全包含，需要访问左子树或右子树
    push_down(u); // 有标记将标记下传
    if(ql <= mid)
        update(lc , ql , qr , v);
    if(qr > mid)
        update(rc , ql , qr , v);
    push_up(u); // 更新当前点
}
 
 
 
/*---区间查询---*/
 
ll query(int u,int ql,int qr)
{
    if(ql <= t[u].l && t[u].r <= qr)
    {
        return t[u].sum;
    }
    push_down(u);
    ll res = 0;
    if(ql <= mid)
        res += query(lc , ql , qr);
    if(qr > mid)
        res += query(rc , ql , qr);
    return res;
}
 
/*--------------------------------------------*/
 
// 线段树的相加和相乘的结合
 
const int maxn = 100005;
#define lc u << 1
#define rc u << 1 | 1
#define m (l + r) / 2
#define mid (t[u].l + t[u].r) / 2
 
ll f[maxn];
int N, M;
ll mod;
 
struct SegMentTrie
{
    int l, r;
    ll add_, mul_;
    ll sum;
}t[maxn << 2];
 
void push_up(int u) {
    t[u].sum = (t[lc].sum + t[rc].sum) % mod;
} 
 
void push_down(int u) {
    t[lc].sum = (t[lc].sum * t[u].mul_ + (mid - t[u].l + 1) * t[u].add_) % mod;
    t[rc].sum = (t[rc].sum * t[u].mul_ + (t[u].r - mid) * t[u].add_) % mod;
    t[lc].add_ = (t[lc].add_ * t[u].mul_ + t[u].add_) % mod;
    t[rc].add_ = (t[rc].add_ * t[u].mul_ + t[u].add_) % mod;
    t[lc].mul_ = (t[lc].mul_ * t[u].mul_) % mod;
    t[rc].mul_ = (t[rc].mul_ * t[u].mul_) % mod;
    t[u].add_ = 0;
    t[u].mul_ = 1;
}
 
void build(int u,int l,int r)
{
    t[u].l = l;
    t[u].r = r;
    t[u].add_ = 0;
    t[u].mul_ = 1;
    if(l == r)
    {
        t[u].sum = f[l] % mod;
        return ;
    }
    build(lc , l , m);
    build(rc , m + 1 , r);
    push_up(u);
}
 
void add_update(int u,int ql,int qr,ll v)
{
    if(ql <= t[u].l && t[u].r <= qr)
    {
        t[u].sum = (t[u].sum + (t[u].r - t[u].l + 1) * v) % mod;
        t[u].add_ = (t[u].add_ + v) % mod;
        return ;
    }
    push_down(u);
    if(ql <= mid)
        add_update(lc , ql , qr , v);
    if(qr > mid)
        add_update(rc , ql , qr , v);
    push_up(u);
}
 
void mul_update(int u,int ql,int qr,ll v)
{
    if(ql <= t[u].l && t[u].r <= qr)
    {
        t[u].sum = (t[u].sum * v) % mod;
        t[u].mul_ = (t[u].mul_ * v) % mod;
        t[u].add_ = (t[u].add_ * v) % mod;
        return ;
    }
    push_down(u);
    if(ql <= mid)
        mul_update(lc , ql , qr , v);
    if(qr > mid)
        mul_update(rc , ql , qr , v);
    push_up(u);
}
 
ll query(int u,int ql,int qr)
{
    if(ql <= t[u].l && t[u].r <= qr)
    {
        return t[u].sum;
    }
    push_down(u);
    ll ans = 0;
    if(ql <= mid)
        ans = (ans + query(lc , ql , qr)) % mod;
    if(qr > mid)
        ans = (ans + query(rc , ql , qr)) % mod;
    return ans % mod;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef long long ll;

#define lc u << 1
#define rc u << 1 | 1
#define mid (t[u].l + t[u].r) >> 1

ll mod;

struct Tree {
    int l, r;
    ll sum, add_, mul_;
}t[N << 2];

ll a[N];

inline void push_up(int u) {
    t[u].sum = t[lc].sum + t[rc].sum;
}


inline void push_down(int u) {
    t[lc].sum = (t[lc].sum * t[u].mul_ + (mid - t[u].l + 1) * t[u].add_) % mod;
    t[rc].sum = (t[rc].sum * t[u].mul_ + (t[u].r - mid) * t[u].add_) % mod;
    t[lc].add_ = (t[lc].add_ * t[u].mul_ + t[u].add_) % mod;
    t[rc].add_ = (t[rc].add_ * t[u].mul_ + t[u].add_) % mod;
    t[lc].mul_ = (t[lc].mul_ * t[u].mul_) % mod;
    t[rc].mul_ = (t[rc].mul_ * t[u].mul_) % mod;
    t[u].add_ = 0;
    t[u].mul_ = 1;
}

void build(int u, int l, int r) {
    t[u].l = l; t[u].r = r;
    t[u].sum = t[u].add_ = 0; t[u].mul_ = 1;
    if(l == r) {
        t[u].sum = a[l] % mod;
        return ;
    }
    int m = (l + r) >> 1;
    build(lc, l, m);
    build(rc, m + 1, r);
    push_up(u);
}

void add_modify(int u, int ql, int qr, ll v) {
    if(ql <= t[u].l && t[u].r <= qr) {
        t[u].sum = (t[u].sum + (t[u].r - t[u].l + 1) * v) % mod;
        t[u].add_ = (t[u].add_ + v) % mod;
        return ;
    }
    push_down(u);
    if(ql <= mid) add_modify(lc, ql, qr, v);
    if(qr > mid)  add_modify(rc, ql, qr, v);
    push_up(u);
}

void mul_modify(int u, int ql, int qr, ll v) {
    if(ql <= t[u].l && t[u].r <= qr) {
        t[u].sum = (t[u].sum * v) % mod;
        t[u].mul_ = t[u].mul_ * v % mod;
        t[u].add_ = t[u].add_ * v % mod;
        return ;
    }
    push_down(u);
    if(ql <= mid) mul_modify(lc, ql, qr, v);
    if(qr > mid)  mul_modify(rc, ql, qr, v);
    push_up(u);
}

ll query(int u, int ql, int qr) {
    if(ql <= t[u].l && t[u].r <= qr) {
        return t[u].sum;
    }
    push_down(u);
    ll ans = 0;
    if(ql <= mid) ans = (ans + query(lc, ql, qr)) % mod;
    if(qr > mid)  ans = (ans + query(rc, ql, qr)) % mod;
    return ans % mod;
}

int main() {
    int n; cin >> n >> mod;
    for(int i = 1;i <= n; i++) cin >> a[i];
    build(1, 1, n);
    int m;
    cin >> m;
    while(m--) {
        int k, l, r; ll v;
        cin >> k >> l >> r;
        if(k == 1) {
            cin >> v;
            mul_modify(1, l, r, v);
        }
        else if(k == 2) {
            cin >> v;
            add_modify(1, l, r, v);
        }
        else cout << query(1, l, r) << endl;
    }
}
