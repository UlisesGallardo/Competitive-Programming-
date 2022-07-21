
class Tree {
public:
    vector<vector<int> > adj, dp;
    vector<int> pre, post, depth;
    int cntr;
    void dfs (int curNode, int prevNode) {
        dp[curNode][0] = prevNode;
        for (int i = 1; i < dp[curNode].size(); i++) {
            dp[curNode][i] = dp[dp[curNode][i - 1]][i - 1];
        }
        depth[curNode] = depth[prevNode] + 1;
        pre[curNode] = cntr++;
        for (int i: adj[curNode]) {
            if (i != prevNode) {
                dfs (i, curNode);
            }
        }
        post[curNode] = cntr++;
    }
    int dist (int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
    int lca (int u, int v) {
        if (isAncestor(u, v)) {
            return u;
        } 
        if (isAncestor(v, u)) {
            return v;
        }
        for (int i = (int)dp[0].size() - 1; i >= 0; i--) {
            if (!isAncestor(dp[u][i], v)) {
                u = dp[u][i];
            }
        }
        return dp[u][0];
    }
    bool isAncestor (int u, int v) {
        return (pre[u] <= pre[v] && post[u] >= post[v]);
    }
    void add_edge (int u, int v) {
        adj[u].push_back(v), adj[v].push_back(u);
    }
    bool onPath (int u, int v, int w) {
        int l = lca(u, v);
        return isAncestor(l, w) && (isAncestor(w, u) || isAncestor(w, v));
    }
    Tree (int n) {
        adj.resize(n), pre.resize(n), post.resize(n), cntr = 0, depth.assign(n, -1);
        dp.resize(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(32);
        }
    }
    void read() {
        dfs(0, 0);
    }
};