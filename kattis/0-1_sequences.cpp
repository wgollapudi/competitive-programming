#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1e9 + 7;

ll modinv(ll x, ll M) {
    ll res = 1;
    ll y = M - 2;
    x %= M;
    while (y) {
        if (y & 1) res = res * x % M;
        x = x * x % M;
        y >>= 1;
    }
    return res;
}

ll powmod(ll x, ll y, ll M) {
    x %= M;
    if (y < 0) {
        x = modinv(x, M);
        y = -y;
    }
    ll res = 1;
    while (y) {
        if (y & 1) res = res * x % M;
        x = x * x % M;
        y >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a = 0, k = 0, r = 0;
    char t = '1';
    string s;
    cin >> s;
    for (char i : s) {
        int s0 = i > t;
        k += (i == t);
        ll term1 = a * s0 % M;
        ll term2 = 0;
        if (i != t) {
            term2 = ((r + 2 * k) % M) * powmod(2, r - 1, M) % M;
        }
        a = (a + term1 + term2) % M;
        r += s0;
    }
    cout << a << '\n';
}
