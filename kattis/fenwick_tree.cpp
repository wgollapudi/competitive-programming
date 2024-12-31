#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    private:
        vector<long long> tree;
        int n;

    public:
        FenwickTree(int n) : n(n){
            tree.resize(n + 1, 0);
        }

        void increment(int index, int delta) {
            for (++index; index <= n; index += index & -index) {
                tree[index] += delta;
            }
        }

        long long query(int index) const {
            long long sum = 0;
            for (; index > 0; index -= index & -index) {
                sum += tree[index];
            }
            return sum;
        }

        long long prefixSum(int index) const {
            return query(index + 1);
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    FenwickTree fenwick_tree(n);

    for (int i = 0; i < q; i++) {
        char operation;
        int index, delta;
        cin >> operation;

        if (operation == '+') {
            cin >> index >> delta;
            fenwick_tree.increment(index, delta);
        } else if (operation == '?') {
            cin >> index;
            cout << fenwick_tree.prefixSum(index - 1) << '\n';
        }
    }
}
