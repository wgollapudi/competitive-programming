#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1000000007;

ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X, Y;
    cin >> N >> X >> Y;
    int K = min(N / X, N / Y);
    vector<ll> F(N + 2);
    F[0] = F[1] = 1;

    for (int i = 2; i <= N + 1; i++) {
        F[i] = F[i - 1] * i % M;
    }

    vector<ll> invF(N + 2);
    for (int i = 0; i <= N + 1; i++) {
        invF[i] = modpow(F[i], M - 2, M);
    }

    ll S = 0;
    for (int k = 0; k < K; k++) {
        ll t1_idx1 = N - k * X + k - X;
        ll t1_idx2 = N - k * X - X;
        ll t2_idx1 = N - k * Y + k - Y;
        ll t2_idx2 = N - k * Y - Y;

        if (t1_idx1 < 0 || t1_idx2 < 0 || t2_idx1 < 0 || t2_idx2 < 0)
            continue;
        if (t1_idx1 > N + 1 || t1_idx2 > N + 1 || t2_idx1 > N + 1 || t2_idx2 > N + 1)
            continue;

        ll t1 = F[t1_idx1] * invF[t1_idx2] % M;
        ll t2 = F[t2_idx1] * invF[t2_idx2] % M;
        ll t3 = modpow(invF[k], 2, M);

        S = (S + t1 * t2 % M * t3 % M) % M;
    }
    cout << S << '\n';
}


