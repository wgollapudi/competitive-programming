#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;

    ll a[n] = {0}, b[n] = {0};
    for (ll i = 0; i < n; i++) {
         cin >> a[i];
    }

    ll total = a[n - 1];
    for (int i = 0; i < n; i++) {
         cin >> b[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > b[i + 1]) {
            total += a[i] - b[i + 1];
        }
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
