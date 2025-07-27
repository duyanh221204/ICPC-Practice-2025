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
        long long n;
        cin >> n;

        vector<long long> fibo = {1, 2};
        while (fibo.back() < n)
            fibo.emplace_back(fibo[fibo.size() - 2] + fibo[fibo.size() - 1]);

        long long ans = n, val = n;
        for (int i = fibo.size() - 1; ~i; --i)
        {
            if (fibo[i] <= val)
            {
                val -= fibo[i];
                ans = fibo[i];
            }

            if (!val)
                break;
        }

        cout << ans;
    }

    return 0;
}