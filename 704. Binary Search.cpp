#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
          int l = 0;
        int r = nums.size()-1;
        while(l !=r )
        {
            int mid = (r +l)/2;
            
            if(target == nums[mid])
                return mid;
            else if(target>nums[mid] && mid != nums.size()-1)
                l = mid+1;
            else if(target<nums[mid] && mid !=0)
                r = mid -1;
            else
                return -1;
        }
        if(nums[l] == target)
            return l;
        return -1; 
    }
};