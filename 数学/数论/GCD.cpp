#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cout << gcd(2, 4) << endl;
}