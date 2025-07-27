#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test = 1;
    //cin >> test;
    while (test--)
    {
        int n;
        cin >> n;

        pair<int, int> p[n];
        for (auto& [i, j] : p)
            cin >> i >> j;

        int ans = 0;
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                long long a = p[j].first - p[i].first;
                long long b = p[j].second - p[i].second;

                for (int k = j + 1; k < n; ++k)
                {
                    long long c = p[k].first - p[i].first;
                    long long d = p[k].second - p[i].second;

                    ans += a * d != b * c;
                }
            }
        }

        cout << ans;
    }

    return 0;
}