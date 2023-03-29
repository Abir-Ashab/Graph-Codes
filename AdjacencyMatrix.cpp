//check is there any edge between a and b
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int g[N][N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    //for undirected graph
    g[u][v] = 1;
    g[v][u] = 1;
  }
  int a, b;
  cin >> a >> b;
  if (g[a][b]) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
  return 0;
}