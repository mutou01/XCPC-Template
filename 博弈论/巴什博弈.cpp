// 有n个石子，每人可以拿1～m个石子，不能拿的人为败者
/*面临m + 1的人必输，设n = k * (m + 1) + r,先手拿r个，后手比输 || 设n = k * (m + 1),先手比输*/


#include <bits/stdc++.h>
using namespace std;

void BaShe() {
    int n, m;
    cin >> n >> m;
    if(n % (m + 1))
        cout << "first" << endl;
    else 
        cout << "second" << endl;
}