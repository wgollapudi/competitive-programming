#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 3e5 + 10, LIM = 1e9;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    x--;
    y--;

    vector<ll> inside;
    for (ll i = x + 1; i <= y; i++) {
         inside.push_back(i);
    }
    inside.push_back(x);
    reverse(inside.begin(), inside.end());

    vector<ll> outside;
    outside.push_back(x);
    for (ll i = y; i < n + x; i++) {
        outside.push_back(i % n);
    }

    vector<ll> ans(n);

    auto solve_circle = [&](const vector<ll>& circle) {
        for (ll i = 0; i < (ll) circle.size(); i++) {
             ans[circle[i]] = i % 2;
        }

        if (circle.size() % 2 != 0) {
            ans[circle.back()] = 2;
        }
    };

    solve_circle(inside);
    solve_circle(outside);

    for (ll i : ans) {
        cout << i << ' ';
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
