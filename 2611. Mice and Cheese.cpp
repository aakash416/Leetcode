#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool static sortcomp(pair<int, int> &vec1, pair<int, int> &vec2)
    {
        return vec1.first > vec2.first;
    }
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        vector<pair<int, int>> vec;
        int ans = 0;
        for (int i = 0; i < reward1.size(); i++)
            vec.push_back({reward1[i] - reward2[i], i});
        sort(vec.begin(), vec.end(), sortcomp);
        for (int i = 0; i < reward1.size(); i++)
        {
            if (k > i)
                ans += reward1[vec[i].second];
            else
                ans += reward2[vec[i].second];
        }
        return ans;
    }
};