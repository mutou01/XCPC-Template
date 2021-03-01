// 笛卡尔树是一种由数列构造的特殊二叉搜索树，每个节点都有两个键值，first为下标，second为权值
// 笛卡尔树满足两个性质，在下标递增的情况下就是一个大/小根堆

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int ls[N], rs[N], s[N];
int a[N];

void build() {
    int n;
    cin >> n;
    for(int i = 1, pos = 0, top = 0;i <= n; i++) { // 不维护左右儿子就是普通单调栈
        cin >> a[i];
        pos = top;
        while(pos && a[s[pos]] > a[i]) pos--;
        if(pos) rs[s[pos]] = i;
        if(pos < top) ls[i] = s[pos + 1];
        s[top = ++pos] = i;
    }
}