#include <bits/stdc++.h>
using namespace std;

#define HAPPY_CODING              \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define Debug(x) cout << #x " = " << (x) << endl
#define SORT(a) sort(a.begin(), a.end())
#define SORTR(a) sort(a.rbegin(), a.rend())
#define mod 1000000007
#define pi 3.141592653589793238
#define ll long long int
#define ull unsigned long long
#define be begin()
#define en end()
#define FOR(i, a, b) for (long long int i = a; i < b; i++)
#define FORI(i, a, b) for (int i = a; i >= b; i--)

typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef vector<PI> VPI;

const int SIZE = 1e6 + 2;
vector<pair<int, int>> g[SIZE];
bool visited[SIZE];
int dist[SIZE];

void Dijkstra()
{
    multiset<pair<int, int>> s;
    s.insert(make_pair(0, 0));

    while (s.size())
    {
        pair<int, int> p = *s.begin();
        s.erase(s.begin());

        int x = p.second;
        int weight = p.first;

        if (visited[x])
            continue;

        visited[x] = true;

        for (int i = 0; i < g[x].size(); i++)
        {
            int vertex = g[x][i].second, distance = g[x][i].first;
            if (dist[x] + distance < dist[vertex])
            {
                dist[vertex] = dist[x] + distance;
                s.insert(make_pair(dist[vertex], vertex));
            }
        }
    }
}

int main()
{
    HAPPY_CODING;

    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < nodes; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    dist[0] = 0;

    for (int i = 0; i < edges; i++)
    {
        int x, y, weight;
        cin >> x >> y >> weight;
        x--;
        y--;

        g[x].push_back(make_pair(weight, y));
    }

    Dijkstra();

    for (int i = 1; i < nodes; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
