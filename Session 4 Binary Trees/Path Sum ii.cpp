// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> ans;
    vector<int> tmp;
    void solve(TreeNode* root,int t)
    {
        if(!root)
            return;
        if(!root->left and !root->right)
        {
            if(root->val==t)
            {
                tmp.push_back(root->val);
                ans.push_back(tmp);
                tmp.pop_back();
            }
        }
        tmp.push_back(root->val);
        solve(root->left,t-root->val);
        solve(root->right,t-root->val);
        tmp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum);
        return ans;
        
    }
};