// We will run a series of DFS in the graph. 
// Initially all vertices are colored white (0). 
// From each unvisited (white) vertex, start the DFS, mark it gray (1) while entering and 
// mark it black (2) on exit. If DFS moves to a gray vertex,
// then we have found a cycle (if the graph is undirected, 
// the edge to parent is not considered). 
// The cycle itself can be reconstructed using parent array.
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int col[N], par[N];
bool cycle;
void dfs(int u) {
  col[u] = 1;
  for (auto v: g[u]) {
    if (col[v] == 0) {
      par[v] = u;
      dfs(v);
    }
    else if (col[v] == 1) {//jekhan theke jatra korsi oitar moto color holei tw cycle paisi
      cycle = true;
      // you can track the cycle using par array
    }
  }
  col[u] = 2;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v); 
  }
  cycle = false;
  for (int i = 1; i <= n; i++) {
    if (col[i] == 0) dfs(i);
  }
  cout << (cycle ? "YES\n" : "NO\n") << '\n';
  return 0;
}