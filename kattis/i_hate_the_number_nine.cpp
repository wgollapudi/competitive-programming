#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

ll modMul(ll a, ll b, ll mod) {
    return (a % mod) * (b % mod) % mod;
}

ll modExp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if ((exp % 2) == 1) {
            result = modMul(result, base, mod);
        }
    base = modMul(base, base, mod);
    exp /= 2;
    }
    return result;
}

void solve() {
    ll d;
    cin >> d;

    if (d == 1) {
        cout << 8 << '\n';
        return;
    }
    ll pow9 = modExp(9, d - 1, MOD);
    ll result = (8 * pow9) % MOD;
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) solve();
}
