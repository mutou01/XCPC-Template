#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

// 两次DFS回朔法

struct Edge {
    int v, w, next;
}e[N * 2];

int cnt, head[N * 2];
int ans;
int D1, D2;
int Dis;

inline void add(int u, int v, int w) {
    e[++cnt].v = v;
    e[++cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void DFS(int u, int fa, int t) {
    if(Dis < t) {
        D1 = u;
        Dis = t;
    }
    for(int i = head[u]; i ; i = e[i].next) {
        int v = e[i].v;
        if(v == fa) continue;
        DFS(v, u, t + e[i].w);
    }
}

void solve1() {
    int n, M;
    cin >> n >> M;
    for(int i = 1;i <= M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    Dis = 0; DFS(1, -1, 0);
    D2 = D1;
    Dis = 0; DFS(D1, -1, 0);
    cout << D1 << " " << D2 << endl;
    cout << Dis << endl;
}

void solve2() {

}