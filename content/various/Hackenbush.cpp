/**
 * Author: Simon Lindholm, chilli
 * Date: 2018-07-23
 * License: CC0
 * Source: http://codeforces.com/blog/entry/60737
 * Description: Green Hackenbush on undirected graph/tree
 * Time : O(V + E)
 */
vector<int> g[N];
int n, T, low[N], dis[N];
int dfs (int u, int pre = 0) {
  dis[u] = low[u] = ++T;
  int ans = 0;
  for (auto v : g[u]) {
    if (v == pre) {
      pre += 2 * n;
      continue;
    }
    if (dis[v] == 0) {
      int res = dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dis[u])
        ans ^= (1 + res) ^ 1; /// bridge
      else
        ans ^= res;           /// non bridge
    } else low[u] = min(low[u], dis[v]);
  }
  if (pre > n) pre -= 2 * n;
  for (auto v : g[u]) if (v != pre && dis[u] <= dis[v]) ans ^= 1;
  return ans;
}
int ground[N];///set 1 for the ground nodes
for(int i = 1; i <= n; i++) ground[i] = 0;
    int root = 1; ///if there are multiple ground nodes set any ground node as a root
    ground[root] = 1;
    int ans = 0;
    T = 0;
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      if (ground[u]) u = root;
      if (ground[v]) v = root;
      int dummy;
      if (u == v) ans ^= 1;
      else {
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
    ans ^= dfs(root);
    if(ans) puts("Alice");
    else puts("Bob");
    for(int i = 1; i <= n; i++) g[i].clear(), low[i] = dis[i] = 0;
