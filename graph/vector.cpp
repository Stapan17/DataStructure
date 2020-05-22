#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX

int minimumDays(int N, int D1[], int D2[])
{
    int ans = -inf;

    vector<pair<int, int>> vect;

    for (int i = 0; i < N; i++)
        vect.push_back(make_pair(D1[i], D2[i]));

    sort(vect.begin(), vect.end());

    for (int i = 0; i < N; i++)
    {
        cout << vect[i].first << "  " << vect[i].second << endl;
    }

    for (int i = 0; i < N; i++)
    {
        if (vect[i].second >= ans)
            ans = vect[i].second;
        else
            ans = vect[i].first;
    }

    return ans;
}

int main()
{
    int N = 3;

    int D1[] = {6, 5, 4};

    int D2[] = {1, 2, 3};

    cout << minimumDays(N, D1, D2);

    return 0;
}
