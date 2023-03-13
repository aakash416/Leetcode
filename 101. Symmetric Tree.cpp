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
    bool isSymmetric(TreeNode *root)
    {
        stack<TreeNode *> s1, s2;
        s1.push(root);
        s2.push(root);
        TreeNode *A = root->left, *B = root->right;
        while (1)
        {
            while (A && B)
            {
                if (A->val != B->val)
                    return false;
                s1.push(A);
                s2.push(B);
                A = A->left;
                B = B->right;
            }
            if (!A && !B)
            {
                A = s1.top();
                B = s2.top();
                if (A == root && B == root)
                    return true;
                s1.pop();
                s2.pop();
                A = A->right;
                B = B->left;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};

class Solution
{
public:
    bool isSymmetricHelper(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (leftNode == NULL && rightNode == NULL)
            return true;
        if (leftNode == NULL || rightNode == NULL || leftNode->val != rightNode->val)
            return false;

        return isSymmetricHelper(leftNode->left, rightNode->right) && isSymmetricHelper(leftNode->right, rightNode->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return isSymmetricHelper(root->left, root->right);
    }
};