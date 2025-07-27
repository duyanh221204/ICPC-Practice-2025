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
        int n, k;
        while (cin >> n >> k)
        {
            int p[502] = {};

            for (int i = n - k + 1; i <= n; ++i)
            {
                int val = i;
                for (int j = 2; j <= sqrt(val); ++j)
                {
                    while (val % j == 0)
                    {
                        ++p[j];
                        val /= j;
                    }
                }

                if (val > 1)
                    ++p[val];
            }

            for (int i = 2; i <= k; ++i)
            {
                int val = i;
                for (int j = 2; j <= sqrt(val); ++j)
                {
                    while (val % j == 0)
                    {
                        --p[j];
                        val /= j;
                    }
                }

                if (val > 1)
                    --p[val];
            }

            long long ans = p[2] + 1;
            for (int i = 3; i <= 500; i += 2)
            {
                if (p[i])
                    ans *= p[i] + 1;
            }

            cout << ans << "\n";
        }
    }

    return 0;
}