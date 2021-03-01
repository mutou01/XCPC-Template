// ll x = FPM(x , mod - 2 , mod)

#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll FPM(ll x, ll power)
{
    ll ans = 1;
    while(power)
    {
        if(power & 1)
        {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        power >>= 1;
    }
    return ans % mod;
}

int main()
{
    cout << FPM(2, mod - 2) << endl;
}