#include <bits/stdc++.h>
using namespace std;
// Heap Sort
// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution
{
public:
    void maxHeapify(vector<int> &nums, int n, int i)
    {
        int largest = i;
        int left = (2 * i) + 1, right = (2 * i) + 2;
        if (left < n && nums[left] > nums[largest])
            largest = left;
        if (right < n && nums[right] > nums[largest])
            largest = right;
        if (largest != i)
        {
            swap(nums[largest], nums[i]);
            maxHeapify(nums, n, largest);
        }
    }

    void heapSort(vector<int> &nums, int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(nums, n, i);
        for (int i = n - 1; i >= 0; i--)
        {
            swap(nums[0], nums[i]);
            maxHeapify(nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        heapSort(nums, nums.size());
        return nums;
    }
};
// Merge Sort

// Time complexity : O(nlogn)
// Space complexity : O(n)
class Solution
{
public:
    void merge(int low, int mid, int high, vector<int> &nums)
    {
        if (low >= high)
            return;
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);
        while (l <= mid and r <= high)
            sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        while (l <= mid)
            sorted[k++] = nums[l++];
        while (r <= high)
            sorted[k++] = nums[r++];
        for (k = 0; k < size; k++)
            nums[k + low] = sorted[k];
    }

    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start < end)
        {
            int mid = start + (end - start) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(start, mid, end, nums);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

// Priority Queue

// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : nums)
            pq.push(i);
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = pq.top();
            pq.pop();
        }
        return nums;
    }
};
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums;
    }
};
