// 树状数组和二进制紧紧联系

int tree[100005];
int n;

int lowbit(int x) {
    return x & (-x); // 计算机中负数使用对应正数的补码表示
}

int getsum(int x) {
    int ans = 0;
    while(x > 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

void update(int x,int value) {
    while(x <= n) {
        tree[x] += value;
        x += lowbit(x);
    }
}