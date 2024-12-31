#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct SegmentTree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = n;
        tree.resize(4 * n);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int node, int l, int r, int idx) {
        if (l == r) {
            tree[node] = 0;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx);
        else
            update(2 * node + 1, mid + 1, r, idx);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) +
               query(2 * node + 1, mid + 1, r, ql, qr);
    }

    int query_up_to(int idx) {
        if (idx < 1) return 0;
        return query(1, 1, size, 1, idx);
    }

    void remove(int idx) {
        update(1, 1, size, idx);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N + 1);
    vector<int> pos(N + 1);
    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        arr[i] = num;
        pos[num] = i;
    }

    SegmentTree st;
    st.init(N);
    st.build(1, 1, N);

    int smallest = 1;
    int largest = N;
    int total_unchosen = N;

    for (int k = 1; k <= N; ++k) {
        int x;
        int swaps;
        if (k % 2 == 1) {
            x = smallest++;
            int rank = st.query_up_to(pos[x]);
            swaps = rank - 1;
        } else {
            x = largest--;
            int rank = st.query_up_to(pos[x]);
            swaps = total_unchosen - rank;
        }
        cout << swaps << '\n';

        st.remove(pos[x]);
        total_unchosen--;
    }
}
