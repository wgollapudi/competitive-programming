#include <bits/stdc++.h>
using namespace std;

long long comb(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

double calculate_probability(int R, int S) {
    double probability = 0.0;
    for (int k = S; k <= R; ++k) {
        long long combValue = comb(R, k);
        probability += combValue * pow(0.5, R);
    }
    return probability;
}

void solve() {
    int N, V1, V2, W;
    cin >> N >> V1 >> V2 >> W;
    int M = V1 + V2;
    int R = N - M;
    int required_votes = N / 2 + 1;
    int S = required_votes - V1;

    double P;
    if (V1 >= required_votes) {
        P = 1.0;
    } else if (V1 + R < required_votes) {
        P = 0.0;
    } else {
        P = calculate_probability(R, S);
    }

    double W_fraction = W / 100.0;
    if (P > W_fraction) {
        cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
    } else if (P == 0.0) {
        cout << "RECOUNT!\n";
    } else {
        cout << "PATIENCE, EVERYONE!\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--) solve();
}
