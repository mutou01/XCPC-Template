
#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int mu[N]; // 莫比乌斯函数
bool is_prime[N];
int prime[N];   
int cnt;
int sum[N];

void Init() {
    mu[1] = 1; is_prime[0] = is_prime[1] = true;
    for(int i = 2;i < N; i++) {
        if (!is_prime[i]) {
            mu[i] = -1;
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * prime[j] < N; j++) {
            is_prime[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }

    for(int i = 1;i < N; i++) {
        sum[i] = sum[i - 1] + mu[i];
    }
}