const int maxn = 5e5 + 10;

int n, m, k;
int f[maxn], cnt[maxn];

int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int u, int v) {
    int x = find(u);
    int y = find(v);
    if(x != y) {
        f[x] = y;
    }
}

void init(int n) {
    for(int i = 1;i <= n; i++) {
        f[i] = i;
        cnt[i] = 0;
    }
}

void solve() {
    cin >> n >> m;
    init(n);
    int u, v;
    for(int i = 1;i <= m; i++) {
        cin >> u >> v;
        merge(u, v);
    }
    
    int ans = 0;
    // first
    for(int i = 1;i <= n; i++) {
        cnt[find(i)]++;
    }
    for(int i = 1;i <= n; i++) {
        if(cnt[i])
            ans++;
    }
    
    //second
    for(int i = 1;i <= n; i++) {
        int s = find(i);
        if(cnt[s] == 0) {
            cnt[s]++;
            ans++;
        }
    }
    
    //third
    for(int i = 1;i <= n; i++) {
        if(pre[i] == i)
            ans++;
    }
    cout << ans << endl;
}
