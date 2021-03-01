//用于解决图中两点间多条路中最大/小边权最小/大值问题
//u, v为原图上的点, 则val[lca(u, v)]为u->v间多条路中...
//由于u, v可能在原图中不连通, 所以需要find(u)和find(v)判断一下是不是在一棵树中
const int N = 1e5 + 10, M = 1e6 + 10;
int n, m;
struct edge {
    int u, v, w;
    bool operator < (const edge& rhs) const {
        return w > rhs.w;
        //升序为(u, v)间多条路中最大边权最小值
        //降序为(u, v)间多条路中最小边权最大值
    }
}E[M];
vector<int> g[N];
int f[N], val[N], cnt; //cnt为kruskal重构树的点数, 点数最多为2N - 1
int son[N], siz[N], fa[N], dep[N], top[N];

void dfs1(int u, int par) {
    dep[u] = dep[fa[u] = par] + (siz[u] = 1);
    for(auto v : g[u]) {
        if(v == par) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if(!son[u] || siz[v] > siz[son[u]]) {
            son[u] = v;
        }
    }
}

void dfs2(int u, int topf) {
    top[u] = topf;
    if(!son[u]) return ;
    dfs2(son[u], topf);
    for(auto v : g[u]) {
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

int lca(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void EX_Kruskal() {
    cnt = n;
    for(int i = 1;i < (n << 1); i++) f[i] = i;
    sort(E + 1, E + m + 1);
    for(int i = 1;i <= m; i++) {
        int u = find(E[i].u);
        int v = find(E[i].v);
        if(u == v) continue;
        val[++cnt] = E[i].w;
        f[u] = f[v] = cnt;
        g[u].push_back(cnt); g[cnt].push_back(u);
        g[v].push_back(cnt); g[cnt].push_back(v);
        if(cnt == (n << 1) - 1) break;
    }
    //原图不连通的情况, 那形成的就是森林
    for(int i = 1;i <= cnt; i++) {
        if(!siz[i]) {
            int u = find(i);
            dfs1(u, 0);
            dfs2(u, u);
        }
    }
}