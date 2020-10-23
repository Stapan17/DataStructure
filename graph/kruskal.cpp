#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
int nodes, edges, id[MAX];
pair<long long, pair<int, int>> p[MAX];

void init()
{
    for (int i = 0; i < MAX; i++)
        id[i] = i;
}

int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);

    id[p] = id[q];
}

int kruskal(int x)
{
    int x, y;
    long long int ans, weight;

    for (int i = 0; i < edges; i++)
    {
        x = p[i].second.first;
        y = p[i].second.second;

        weight = p[i].first;

        if (root(x) != root(y))
        {
            ans += weight;
            union1(x, y);
        }
    }

    return ans;
}

int main()
{
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int x, y;
        long long weight;

        cin >> x >> y >> weight;

        p[i] = make_pair(weight, make_pair(x, y));
    }

    sort(p, p + edges);

    int minimumCost = kruskal(1);
    cout << minimumCost << "\n";

    return 0;
}