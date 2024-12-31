#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string s;
        getline(cin, s);

        int min_length = s.length();

        for (int l = 1; l <= s.length(); ++l) {
            string p = s.substr(0, l);
            int m = (s.length() + l - 1) / l;
            string t;

            for (int i = 0; i < m; ++i) {
                t += p;
            }

            if (t.compare(0, s.length(), s) == 0) {
                min_length = l;
                break;
            }
        }
        cout << min_length << '\n';
    }
    return 0;
}
