#include <bits/stdc++.h>
using namespace std;

int n, m, a[300002];

bool isValid(int val)
{
    int p = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] + val < m)
        {
            if (p > a[i] + val)
                return false;
            p = max(p, a[i]);
        }
        else
        {
            int x = (a[i] + val) % m;
            if (p > x)
                p = max(p, a[i]);
        }
        //cout << p << " ";
    }
    //cout << "\n";
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test = 1;
    //cin >> test;
    while (test--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int l = 0, r = m - 1, ans = INT_MAX;
        while (l <= r)
        {
            int mid = l + r >> 1;

            if (isValid(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        cout << ans;
    }

    return 0;
}