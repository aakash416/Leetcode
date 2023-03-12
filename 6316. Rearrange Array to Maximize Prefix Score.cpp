#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        int ans = 0;
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        vector<long long> vec(n);
        vec[0] = nums[0];
        if (0 < vec[0])
            ans++;
        for (int i = 1; i < n; i++)
        {
            vec[i] = vec[i - 1] + nums[i];
            if (vec[i] > 0)
                ans++;
        }
        return ans;
    }
};