#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long lastmne = 0, lastmxe = 0;
        long long mne = INT_MAX, mxe = -1;
        long long xe = 0;
        long long anse = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == minK)
                lastmne = i + 1;
            if (nums[i] == maxK)
                lastmxe = i + 1;
            if (nums[i] < minK || nums[i] > maxK)
            {
                lastmne = 0, lastmxe = 0;
                xe = i + 1;
            }
            if (lastmne && lastmxe)
                anse += min(lastmne - xe, lastmxe - xe);
        }

        return anse;
    }
};