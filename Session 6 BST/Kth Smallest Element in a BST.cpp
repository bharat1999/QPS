// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res;
    void solve(TreeNode* root,int &k)
    {
        if(!root)
            return;
        solve(root->left,k);
        k--;
        if(k==0)
        {
            res = root->val;
            return;
        }
        solve(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return res;
    }
};