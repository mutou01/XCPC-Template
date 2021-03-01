//  尼姆博弈是巴什博弈的进化版
// 有n堆石子，两个人可以从任意一堆石子中拿任意多个石子(不能不拿)，没法拿的人失败

// 定理：当n堆石子的数量异或和等于0时，先手必胜，否则先手必败


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

void Nim() {
    int n, ans = 0;
    cin >> n;
    for(int i = 1;i <= n; i++) {
        cin >> a[i];
        ans ^= a[i];
    }
    if(ans == 0)
        cout << "second" << endl;
    else 
        cout << "first" << endl;
}