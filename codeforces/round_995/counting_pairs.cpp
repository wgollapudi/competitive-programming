#include <bits/stdc++.h>
using namespace std;

// arr a, of n ints, where i-th element = a_i
//
// (i, j) is interesting iif
// - 1 <= i < j <= n;
// - if remove a[i] and a[j], the sum of remaining elements is at least x and most y

typedef long long ll;
const int N = 1e6 + 5;

void solve() {
    ll n, x, y, ans = 0, total_sum = 0;
    ll a[N];

    cin >> n >> x >> y;

    for (int i = 1; i <= n; i++) {
         cin >> a[i];
         total_sum += a[i];
    }

    if (x > y) {
        cout << "0\n";
        return;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        ll left = total_sum - a[i] - y;
        ll right = total_sum - a[i] - x;

        int left_idx = lower_bound(a + 1, a + n + 1, left) - a;
        int right_idx = upper_bound(a + 1, a + n + 1, right) - a - 1;

        if (left_idx > right_idx) continue;

        int count = right_idx - left_idx + 1;
        if (i >= left_idx && i <= right_idx) count--;

        ans += count;
    }
    cout << ans/2 << '\n';
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
