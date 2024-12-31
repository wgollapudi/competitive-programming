#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 10000005;

int mu[MAX];
bool is_prime[MAX];
int primes[MAX], prime_cnt;

void mobius_sieve(int n) { // If anyone finds this, look this shit up
                           //            its really freaking cool, see the codeforces blog post
    fill(mu, mu + n + 1, 1);
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes[prime_cnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; ((j < prime_cnt) && (i * primes[j] <= n)); j++) {
            int x = i * primes[j];
            is_prime[x] = false;
            if ((i % primes[j]) == 0) {
                mu[x] = 0;
                break;
            } else {
                mu[x] = -mu[i];
            }
        }
    }
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = max(b, d);
    mobius_sieve(n);
    ll result = 0;
    for (int k = 1; k <= n; k++) {
        if (mu[k] == 0) continue;
        ll count_x = b / k - (a - 1) / k;
        if (count_x == 0) continue;
        ll count_y = d / k - (c - 1) / k;
        if (count_y == 0) continue;
        result += mu[k] * count_x * count_y;
    }
    printf("%lld\n", result);
}


