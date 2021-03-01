//二维

int v[1005], w[1005];
int f[1005][1005];

void fsbag()
{
    int N, T;
    cin >> N >> T;
    for(int i = 1;i <= N; i++)
        cin >> v[i] >> w[i];
    for(int i = 1;i <= N; i++)
    {
        for(int j = 0;j <= T; j++)
        {
            f[i][j] = f[i - 1][j];
            if(j - v[i] >= 0)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << f[N][T] << endl;
}

//一维
int f[1005];

void fsbag()
{
    int n, V;
    cin >> n >> V;
    for(int i = 1;i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    
    for(int i = 1;i <= n; i++) {
        for(int j = V;j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    
    cout << f[V] << endl;
}