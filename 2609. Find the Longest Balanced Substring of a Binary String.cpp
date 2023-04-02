#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                string str = s.substr(j, i);
                int zero = count(str.begin(), str.end(), '0');
                int ones = count(str.begin(), str.end(), '1');
                if (zero == ones && all_of(str.begin(), str.begin() + zero, [](char c)
                                           { return c == '0'; }))
                {
                    ans = max(ans, i);
                }
            }
        }

        return ans;
    }
};
