#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;
const int LOG = 18;

vector<int> adj[MAXN];
int depth[MAXN];
int parent[MAXN][LOG];

void dfs(int node, int par) {
    for (int neighbor : adj[node]) {
        if (neighbor != par) {
            depth[neighbor] = depth[node] + 1;
            parent[neighbor][0] = node;
            dfs(neighbor, node);
        }
    }
}

void preprocess_lca(int n) {
    dfs(1, -1);
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) {
            u = parent[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int path_length(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)] + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < LOG; j++) {
            parent[i][j] = -1;
        }
    }

    preprocess_lca(n);

    long long total_sum = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 2 * x; y <= n; y += x) {
            if (y > x) {
                total_sum += path_length(x, y);
            }
        }
    }
    cout << total_sum << '\n';
}
