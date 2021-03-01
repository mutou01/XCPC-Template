struct  Heap{//堆
    int data[MAXN];
    int p=0;
    bool empty(){
        return p==0;
    }
    void init(){
        p=0;
    }
    int size(){
        return p;
    }
    bool judge(int x,int y){
        return x<y;
    }
    void push(int x){
        data[++p]=x;
        int tt=p;
        while(tt>1&&judge(data[tt],data[tt/2])){
            swap(data[tt],data[tt/2]);
            tt/=2;
        }
    }
    int top(){
        return data[1];

    }
    void pop(){
        data[1]=data[p];
        data[p--]=0;
        int t=1,tt=t*2;
        while(tt<=p){
            if(tt<p&&!judge(data[tt],data[tt+1]))
                tt++;
            if(!judge(data[t],data[tt])) {
                swap(data[t], data[tt]);

            }
            t=tt,tt=t*2;

        }
    }
}heap;
