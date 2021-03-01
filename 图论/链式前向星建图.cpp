inline void add(int u, int v, int w) {
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}