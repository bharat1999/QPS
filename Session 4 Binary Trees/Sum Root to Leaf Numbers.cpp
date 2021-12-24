// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int res = 0;
    void sumRootLeaf(TreeNode* root, int currSum)
    {
        if(root==NULL)
        {
            return;
        }
        currSum *= 10; 
        currSum += root->val;
        if(!root->left && !root->right)
        {
            res += currSum;
            return;
        }
        
        sumRootLeaf(root->left, currSum);
        sumRootLeaf(root->right, currSum);
        
    }
    
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        sumRootLeaf(root, 0);
        return res;
    }
};