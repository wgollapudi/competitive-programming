#include <bits/stdc++.h>
using namespace std;

int n;
int ways = 0;
vector<int> best;
vector<int> avalible;
vector<bool> used;
vector<string> colors;
vector<vector<bool>> ajacent_ok;

void add_colors() {
    if (avalible.size() == n) {
        if (best.size() == 0) {
            for (int i : avalible) {
                best.push_back(i);
            }
        }
        ways++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (avalible.size() > 0) {
                if (!ajacent_ok[avalible.back()][i]) {
                    continue;
                }
            }
            used[i] = true;
            avalible.push_back(i);
            add_colors();
            avalible.pop_back();
            used[i] = false;
        }
    }
}

void read_colors(map<string, int>* color_ptr) {
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        (*color_ptr)[s] = i;
        colors.push_back(s);
    }
}

void read_bad_color_pairs(int m, map<string, int>* color_ptr) {
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int i1 = (*color_ptr)[s1];
        int i2 = (*color_ptr)[s2];
        ajacent_ok[i1][i2] = false;
        ajacent_ok[i2][i1] = false;
    }
}

void solve() {
    cin >> n;
    used.clear();
    used.resize(n, false);

    colors.clear();
    map<string, int> color;

    read_colors(&color);

    ajacent_ok.clear();
    ajacent_ok.resize(n, vector<bool>(n, true));

    int m;
    cin >> m;
    read_bad_color_pairs(m, &color);

    add_colors();

    cout << ways << '\n';
    for (int i : best) {
        cout << colors[i] << " ";
    }
    cout << '\n';

    ways = 0;
    best.clear();
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        solve();
    }
}


