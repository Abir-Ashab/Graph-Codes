#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mx = 512;
ll dist[mx][mx];

int main()
{

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                dist[i][j] = INT_MAX;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], (ll)w);
        dist[v][u] = min(dist[v][u], (ll)w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] == INT_MAX)
            dist[u][v] = -1;
        cout << dist[u][v] << endl;
    }
    return 0;
}
/*
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2
*/
