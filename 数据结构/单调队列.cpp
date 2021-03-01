#include <bits/stdc++.h>
using namespace std;



struct Monotone_queue{
    static const int maxn = 10000005;
    int n, k, a[maxn]; // 个数、窗口大小、值
    int q[maxn], p[maxn], head, tail; // q是单调队列，p是对应y序号，头节点、尾节点
    void read() 
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }
    
    void Monotone_min()
    {
        head = 1; tail = 0; 
        for(int i = 1;i <= n; i++) {
            while(head <= tail && q[tail] >= a[i]) {
                tail--;
            }
            q[++tail] = a[i];
            p[tail] = i;
            while(p[head] <= i - k) head++;
            if(i >= k)
                cout << q[head] << " ";
        }
            cout << endl;
    }
        
    void Monotone_max()
    {
        head = 1; tail = 0;
        for(int i = 1;i <= n; i++) {
            while(head <= tail && q[tail] <= a[i]) {
                tail--;
            }
            q[++tail] = a[i];
            p[tail] = i;
            while(p[head] <= i - k) head++;
            if(i >= k)
                cout << q[head] << " ";
        }
            cout << endl;
    }
}Worker;
