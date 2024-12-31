#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll total = 3 * (a / (b + c + d));
    a = a % (b + c + d);

    if (a > 0) {
        total++;
        a -= b;
    }

    if (a > 0) {
        total++;
        a -= c;
    }

    if (a > 0) {
        total++;
    }

    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}
