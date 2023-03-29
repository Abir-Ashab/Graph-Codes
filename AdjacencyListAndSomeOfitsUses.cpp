#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> g[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  //n = nodes, m = edges
  while (m--) {
    int u, v; cin >> u >> v;//(u,v) = edge....here u,v must be between 1-n
    g[u].push_back(v);
    g[v].push_back(u);
  }
  //x er shathe connected kongula
  int x;
  cin >> x;
  for (auto v: g[x]) {
    cout << v << '\n';
  }
  // degrees
  for (int i = 1; i <= n; i++) {
    cout << g[i].size() << ' ';
  }
  cout << '\n';
  return 0;
}