namespace Fast_IO
{
    const int MAXL((1 << 18) + 1);int iof, iotp;
    char ioif[MAXL], *ioiS, *ioiT, ioof[MAXL],*iooS=ioof,*iooT=ioof+MAXL-1,ioc,iost[55];
    inline char Getchar(){if(ioiS == ioiT){ioiS = ioif;ioiT = ioiS + fread(ioif,1,MAXL,stdin);return (ioiS == ioiT ? EOF : *ioiS++);}else return (*ioiS++);}
    inline int read()
    {
        int x = 0;for(iof = 1,ioc = Getchar();(ioc < '0' || ioc > '9') && ioc != EOF;)iof = ioc == '-' ? -1 : 1,ioc = Getchar();
        if(ioc == EOF)exit(0);
        for(x = 0;ioc <= '9' && ioc >= '0';ioc = Getchar())x = (x << 3) + (x << 1) + (ioc ^ 48);
        return x * iof;
    }
    inline long long read_ll()
    {
        long long x = 0;
        for(iof = 1,ioc = Getchar();(ioc < '0' || ioc > '9') && ioc != EOF;)iof = ioc == '-' ? -1 : 1,ioc = Getchar();
        if(ioc == EOF)exit(0);
        for(x = 0;ioc <= '9' && ioc >= '0';ioc = Getchar())x = (x << 3) + (x << 1) + (ioc ^ 48);
        return x * iof;
    }
}
using namespace Fast_IO;