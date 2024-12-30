#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int p_loc = n;
    int s_loc = -1;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'p') {
            p_loc = i;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        if (s[i] == 's') {
            s_loc = i;
        }
    }

    cout << (p_loc == n || s_loc == -1 ? "YES" : "NO") << "\n";
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
