#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        if (numOnes >= k)
            return k;
        if (numOnes + numZeros >= k)
            return numOnes;
        if (numOnes + numZeros + numNegOnes >= k)
            if (numOnes + numZeros >= k)
                return numOnes;
            else
                return numOnes - (k - (numOnes + numZeros));
        return 0;
    }
};