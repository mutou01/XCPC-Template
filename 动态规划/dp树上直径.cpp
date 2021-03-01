bool used[MAXN]={false};
int ans=-inf;
void dp(int x){
    used[x]=1;
    search(i,x){
        int y=edge[i].v;
        if(used[y])continue;
        dp(y);
        ans = max(ans,d[x]+d[y]+edge[i].c);
        d[x]=max(d[x],d[y]+edge[i].c);
    }
}
