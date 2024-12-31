#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename Container>
void read_vector(Container& v) {
    for (auto& elem : v) {
         cin >> elem;
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);
    read_vector(a);
    read_vector(b);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> unique_values;
    unique_values.reserve(2 * n);
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(unique_values));
    unique_values.erase(unique(unique_values.begin(), unique_values.end()), unique_values.end());

    if (unique_values.empty() || unique_values[0] > 1) {
        unique_values.insert(unique_values.begin(), 1ll);
    }

    ll best = 0;
    for (ll value : unique_values) {
        ll x = upper_bound(a.begin(), a.end(), value - 1) - a.begin();
        ll y = upper_bound(b.begin(), b.end(), value - 1) - b.begin();

        if (x - y <= k) {
            best = max(best, value * (n - y));
        }
    }
    cout << best << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}
