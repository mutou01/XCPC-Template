#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 10;
int idx, trie[N][2];
int a[N];

void insert(int x) {
    int root = 0;
    for(int i = 30;i >= 0; i--) {
        int v = x >> i & 1;
        if(!trie[root][v]) trie[root][v] = ++idx;
        root = trie[root][v];
    }
}

int query(int x) {
    int ans = 0;
    int root = 0;
    for(int i = 30;i >= 0; i--) {
        int v = x >> i & 1;
        if(trie[root][!v]) {
            ans += 1 << i;
            root = trie[root][!v];
        }
        else root = trie[root][v];
    }
    return ans;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        insert(a[i]);
    }
    int ans = -1;
    for(int i = 1;i <= n; i++) {
        ans = max(ans, query(a[i]));
    }
    printf("%d\n",ans);
}