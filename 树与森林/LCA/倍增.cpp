
#include <iostream>

using namespace std;

const int N = 500005;

struct Edge{
    int v, next;
}e[N];

int head[N], cnt;

inline void add(int u, int v)
{
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

int fa[N][55]; // 倍增数组
int depth[N]; // 各节点的深度
int lg[N]; // 跳跃区度

int n, m, root; // 知道根节点是谁这样写，有的不给根节点就要自己找

void Get_Data()
{
    cin >> n >> m >> root;
    for(int i = 1;i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        add(v, u);
        add(u, v);
    }
    for(int i = 1; i <= n; ++i)
        lg[i] = lg[i-1] + (1 << lg[i-1] == i);
}

void LCA_DFS(int u, int v) // DFS求各点深度，并记录各节点的祖先（倍增）！！！
{
    fa[u][0] = v; // v是u的父亲
    depth[u] = depth[v] + 1;

    for(int i = 1;i <= lg[depth[u]]; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1]; // u的爷爷是u的父亲的父亲

    for(int i = head[u]; i ; i = e[i].next) {
        if(e[i].v != v)
            LCA_DFS(e[i].v, u);
    }
}

int LCA(int u1, int u2) // 寻找u和v的最近公共祖先
{
    if(depth[u1] < depth[u2]) swap(u1, u2); // 使u1的深度更深

    while(depth[u1] > depth[u2])
        u1 = fa[u1][lg[depth[u1] - depth[u2]] - 1]; // 调整u1的深度，使u1和u2的深度相同

    if(u1 == u2) return u1; // 刚好是祖宗

    for(int j = lg[depth[u1]] - 1;j >= 0; j--) // 倍增：两个重重孙子一起往上爬找祖宗
    {
        if(fa[u1][j] != fa[u2][j])
        {
            u1 = fa[u1][j];
            u2 = fa[u2][j];
        }
    }

    return fa[u1][0];
}