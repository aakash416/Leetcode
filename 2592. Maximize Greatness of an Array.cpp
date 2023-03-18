#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeGreatness(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0, i = 0, j = 1;
        while (j < nums.size())
        {
            if (nums[i] < nums[j])
            {
                ans++;
                i++;
                j++;
            }
            else
                j++;
        }
        return ans;
    }
};