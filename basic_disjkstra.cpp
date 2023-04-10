#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e5 + 123;
vector<pair<int, int>> adj[mx];
ll dist[mx];

void dijkstra(int s, int n)
{
    for (int i = 0; i <= n; i++)
        dist[i] = INT_MAX;
    dist[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        ll curD = pq.top().first;
        pq.pop();

        if (dist[u] < curD)
            continue;

        for (auto p : adj[u])
        {
            int v = p.first;
            ll w = p.second;
            if (curD + w < dist[v])
            { // relax operation
                dist[v] = curD + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(0, n);

    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";
    cout << '\n';

    return 0;
}