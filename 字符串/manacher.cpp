//马拉车算法,用于处理字符串中回文串问题
//事先在现存字符串中间隔插入非出现字符#
//接下来d中以每个字符为中心的回文串长度
int d[MAXN];
void Manacher(string s_now){
    string s = "$#";
    for(int i = 0;i<s_now.size();i++)
        s+=s_now[i],s+='#';
    s+='^';
    int mid = 0,r = 0;
    for(int i = 0 ;i < s.size()-1;i++){
        if(i<r){
            d[i] = min(d[2 * mid - i],r - i);
        }else
            d[i]=1;
        while(s[i+d[i]]==s[i-d[i]])d[i]++;
        if(i+d[i]>r)
            r=i+d[i],mid = i;
        
    }
} 
