const int maxn = 10000005;
int Next[maxn];
int slen, tlen;
char S[maxn], T[maxn];
void GetNext() {
    int j, k;
    j = 0;
    k = -1;
    Next[0] = -1;
    while(j < tlen) {
        if(k == -1 || T[j] == T[k]) {
            Next[++j] = ++k;
        }
        else
            k = Next[k];
        }
}
 
int KMP_Index() /*返回模式串T在主串S中c首次出现的位置 , 返回的位置是从0开始的*/
{
    int i = 0, j = 0;
    GetNext();
    while(i < slen && j < tlen)
    {
        if(j == -1 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
            j = Next[j];
    }
    if(j == tlen)
        return i - tlen;
    else
        return -1;
}
 
int KMP_Count() /*返回模式串T在字串中出现的次数*/
{
    int ans = 0;
    if(slen == 1 && tlen == 1) {
        if(S[0] == T[0])
            return 1;
        else 
            return 0;
    }
    GetNext();
    int j = 0;
    for(int i = 0;i < slen; i++) {
        while(j > 0 && S[i] != T[j]) {
            j = Next[j];
        }
        if(S[i] == T[j]) j++;
        if(j == tlen) {
            ans++;
            j = Next[j];
            }
        /*if(j ==tlen)
        {
            printf("%d ",i - j);
        }
        模式串在主串中所有的位置*/
        }
    return ans;
}
int main()
{
    cin >> S >> T;
    slen = strlen(S);
    tlen = strlen(T);
    cout << "返回模式串T在主串S中c首次出现的位置是: " << KMP_Index() << endl;
    cout << "返回模式串T在字串中出现的次数是: "<< KMP_Count() << endl;
    return 0;
}