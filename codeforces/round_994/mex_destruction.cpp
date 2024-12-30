#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
         cin >> a[i];
    }

    int blocks = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && (i == 0 || a[i - 1] == 0)) {
            blocks++;
        }
    }

    cout << min(blocks, 2) << "\n";
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
