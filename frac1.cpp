/*
ID: akhilen1
TASK: frac1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i <= j; i++)
        {
            if (__gcd(i, j) == 1)
            {
                v.push_back({i, j});
            }
        }
    }

    sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) -> bool
         { return ((double)a.first) / ((double)a.second) < ((double)b.first) / ((double)b.second); });

    for (auto [a, b] : v)
    {
        cout << a << "/" << b << "\n";
    }
}

int32_t main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // freopen("frac1.in", "r", stdin);
    // freopen("frac1.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
