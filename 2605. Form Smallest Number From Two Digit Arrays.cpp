
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
            ans.push_back(nums1[i]);
        for (int i = 0; i < nums2.size(); i++)
            ans.push_back(nums2[i]);
        sort(ans.begin(), ans.end());
        int n = ans.size();
        for (int i = 1; i < n; i++)
        {
            if (ans[i - 1] == ans[i])
                return ans[i];
        }
        sort(nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        if (nums1[0] > nums2[0])
            return 10 * nums2[0] + nums1[0];

        int a = 10 * nums1[0] + nums2[0];
        return a;
    }
};
