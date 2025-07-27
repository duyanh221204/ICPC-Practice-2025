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

        int a[n + 2];
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            int val = -a[i];
            auto it = upper_bound(v.begin(), v.end(), val);

            if (it == v.end())
                v.emplace_back(val);
            else
                *it = val;
        }

        cout << (int)v.size();
    }

    return 0;
}