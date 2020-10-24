#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int>>> adj;
int dist[1000];

void bellman(int node, int edge)
{
    for (int i = 0; i < node; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[0] = 0;

    for (int i = 0; i < node - 1; i++)
    {
        for (int j = 0; j < edge; j++)
        {
            int u = adj[j].second.first;
            int v = adj[j].second.second;
            int weight = adj[j].first;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < edge; i++)
    {
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        int weight = adj[i].first;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }
}

int main()
{
    int node, edges;
    cin >> node >> edges;

    for (int i = 0; i < edges; i++)
    {
        int x, y, weight;
        cin >> x >> y >> weight;

        adj.push_back(make_pair(weight, make_pair(x, y)));
    }

    for (int i = 0; i < node; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}