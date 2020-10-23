#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> PII;
const int MAX = 1e4 + 5;
vector<PII> adj[MAX];
bool visited[MAX];

int prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII>> q;
    int ans = 0;

    q.push(make_pair(0, x));

    while (q.size())
    {
        PII p = q.top();
        q.pop();

        x = p.second;

        if (visited[x])
            continue;

        visited[x] = true;
        ans += p.first;

        for (int i = 0; i < adj[x].size(); i++)
        {
            int y = adj[x][i].second;

            if (!visited[y])
            {
                q.push(adj[x][i]);
            }
        }
    }
    return ans;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int x, y, weight;
        cin >> x >> y >> weight;

        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }

    int minimumCost = prim(1);
    cout << minimumCost << "\n";

    return 0;
}