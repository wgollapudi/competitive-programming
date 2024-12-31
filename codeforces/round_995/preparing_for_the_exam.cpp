#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
         cin >> a[i];
    }
    set<int> s;

    for (int i =1; i <= n; i++) {
        s.insert(i);
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        s.erase(x);
    }

    if (s.size() > 1) {
        cout << string(m, '0') << '\n';
        return;
    }
    if (!s.size()) {
        cout << string(m, '1') << '\n';
        return;
    }
    for (int i = 0; i < m; i++) {
        if (!s.count(a[i])) {
            cout << '0';
        } else {
            cout << '1';
        }
    }
    cout << '\n';
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
