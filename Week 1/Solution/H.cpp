#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test = 1;
    cin >> test;
    while (test--)
    {
        long long a, b;
        cin >> a >> b;

        if (a == b)
            cout << "0";
        else
        {
            long long diff = abs(a - b);
            long long n = (long long)ceil((-1 + sqrtl(1 + 8 * diff)) / 2.0);
            long long sum = n * (n + 1) >> 1;

            while ((sum & 1) != (diff & 1))
            {
                ++n;
                sum += n;
            }

            cout << n;
        }

        cout << "\n";
    }

    return 0;
}