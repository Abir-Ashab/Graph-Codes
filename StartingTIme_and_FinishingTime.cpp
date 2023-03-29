#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 1e5;
vector<int> g[N];
bool vis[N]; int s = 1;
int start[N],finish[N]; 

void dfs(int u) {
  vis[u] = true;
  start[1] = 1;
  for (auto v: g[u]) {
    if (!vis[v]) {
      s++;
      start[v] = s;
      dfs(v);
      s++; finish[v] = s;
    }
  }
}
int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     ll x;
     cin >> x;
     ll t = x;
     while(t--) {
        ll y, n; cin >> y >> n;
        for(int i = 0; i < n; ++i) {
            ll m; cin >> m;
            g[y].push_back(m);
        }
     }
     dfs(1); s++;
     finish[1] = s;
     for (int i = 1; i <= x; i++) {
       if (!vis[i]) {
        s++;
        start[i] = s;
        dfs(i);
        s++;
        finish[i] = s;
       }
     }
     for(int i = 1; i <= x; ++i) cout << i << ' ' << start[i] << ' ' << finish[i] << '\n';
     return 0;
}