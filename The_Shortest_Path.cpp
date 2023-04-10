#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e5 + 123;
vector<pair<int, int>> adj[mx];
ll dist[mx];

void dijkstra(int s, int n)
{
    for (int i = 0; i <= n; i++)
        dist[i] = INT_MAX; /// initilization
    dist[s] = 0;           /// initilizing source distance
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s}); /// pushing source in queue

    while (!pq.empty())
    {
        int u = pq.top().second;
        ll curD = pq.top().first;
        pq.pop();

        if (dist[u] < curD)
            continue; // important

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
    int test;
    cin >> test;
    while (test--)
    {
        int t;
        cin >> t;
        map<string, int> mp;
        int ind = 1;
        while (t--)
        {
            string s;
            cin >> s;
            mp[s] = ind;
            int n;
            cin >> n;
            while (n--)
            {
                int u = ind, v, w;
                cin >> v >> w;
                adj[u].push_back({v, w});
                //adj[v].push_back({u, w});
            }
            ind++;
        }
        int x;
        cin >> x;
        for (int i = 0; i < x; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            dijkstra(mp[s1], ind);
            cout << dist[mp[s2]] << "\n";
        }
        adj->clear();
    }
    return 0;
}