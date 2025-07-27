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
        string s;
        cin >> s;

        int idA = INT_MAX, idZ = INT_MIN;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'A')
                idA = min(idA, i);
            else if (s[i] == 'Z')
                idZ = max(idZ, i);
        }

        cout << idZ - idA + 1;
    }

    return 0;
}