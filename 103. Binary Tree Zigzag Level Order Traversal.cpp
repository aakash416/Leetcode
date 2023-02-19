#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> v;
        if (root == NULL)
            return v;

        queue<TreeNode *> q;
        bool dir = true;
        q.push(root);

        while (q.size() != 0)
        {
            int s = q.size();
            vector<int> val(s);

            for (int i = 0; i < s; i++)
            {
                TreeNode *fr = q.front();
                q.pop();

                int idx = dir ? i : (s - 1 - i);
                val[idx] = fr->val;

                if (fr->left)
                {
                    q.push(fr->left);
                }

                if (fr->right)
                {
                    q.push(fr->right);
                }
            }

            dir = !dir;
            v.push_back(val);
        }
        return v;
    }
};