#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int N;
int initial[MAXN];
int desired[MAXN];
int desired_pos[MAXN];
int A[MAXN];
int BIT[MAXN];

void update(int index) {
    while (index <= N) {
        BIT[index] += 1;
        index += index & -index;
    }
}

int query(int index) {
    int result = 0;
    while (index > 0) {
        result += BIT[index];
        index -= index & -index;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> initial[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> desired[i];
    }
    for (int i = 0; i < N; ++i) {
        desired_pos[desired[i]] = i + 1;
    }
    for (int i = 0; i < N; ++i) {
        A[i] = desired_pos[initial[i]];
    }
    long long inversion_count = 0;
    for (int i = N - 1; i >= 0; --i) {
        inversion_count += query(A[i] - 1);
        update(A[i]);
    }
    if (inversion_count % 2 == 0) {
        cout << "Possible\n";
        return 0;
    }
    cout << "Impossible\n";
}
