#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* child[26] = {};
    bool isEnd;

    Node()
    {
        for (Node*& i : child)
            i = nullptr;
        isEnd = false;
    }
};

void insert(Node* root, string& s)
{
    Node* cur = root;
    for (char& i : s)
    {
        int id = i - 'a';

        if (!cur->child[id])
            cur->child[id] = new Node();
        cur = cur->child[id];
    }
    cur->isEnd = true;
}

long long dp[5002], mod = 1e9 + 7;

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
        int k;
        cin >> s >> k;

        Node* root = new Node();
        while (k--)
        {
            string word;
            cin >> word;
            insert(root, word);
        }

        int len = (int)s.size();
        dp[0] = 1;
        for (int i = 0; i < len; ++i)
        {
            if (dp[i])
            {
                //cout << dp[i] << "\n";
                Node* cur = root;
                for (int j = i; j < len; ++j)
                {
                    int id = s[j] - 'a';

                    if (cur->child[id])
                    {
                        cur = cur->child[id];
                        if (cur->isEnd)
                            (dp[j + 1] += dp[i]) %= mod;
                    }
                    else
                        break;
                }
            }
        }

        cout << dp[len];
    }

    return 0;
}