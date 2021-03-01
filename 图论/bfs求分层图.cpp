

void Bfs(){
    memset(d,0,sizeof(d));
    d[root]=1;
    queue<int> que;
    que.push(root);//π„∂»”≈œ»±È¿˙…˙≥…“ª∏ˆ∑÷≤„Õº
    while(!que.empty()){
        int x=que.front();que.pop();
        search(i,x){
            int y=edge[i].v;
            if(d[y])continue;
            d[y]=d[x]+1;
            que.push(y);
        }
    }
}
