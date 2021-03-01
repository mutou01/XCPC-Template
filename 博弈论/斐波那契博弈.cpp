// 有一堆石子，两个顶尖聪明的人玩游戏，先取者可以取走任意多个，但不能全取完，以后每人取的石子数不能超过上个人的两倍
 
// 定理：当且仅当石子数为斐波那契数时，先手必败
 
int fib[100001], n;
map<int, bool> p;
int main()
{
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3;i <= 50; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        p[fib[i]] = 1;
    }
    scanf("%d",&n);
    if(p[n])
        printf("second");
    else
        printf("first");
}
