#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int codewith(vector<int> &a, int n)
    {
        int m = INT_MIN, e = 0;

        for (int i = 0; i < n; i++)
        {
            e = e + a[i];
            if (m < e)
                m = e;

            if (e < 0)
                e = 0;
        }
        return m;
    }
    int maximumCostSubstring(string s, string chars, vector<int> &vals)
    {
        map<char, int> m;
        vector<int> v;
        char ccount = 'a';
        int n1 = chars.size();
        m[ccount] = 1;
        for (int i = 1; i < 26; i++)
        {
            ccount++;
            m[ccount] = i + 1;
        }
        for (int i = 0; i < n1; i++)
            m[chars[i]] = vals[i];
        for (int i = 0; i < s.length(); i++)
            v.push_back(m[s[i]]);
        int ans = codewith(v, v.size());
        if (0 > ans)
            return 0;
        else
            return ans;
    }
};