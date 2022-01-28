//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* buildBST(vector<int>& nums,int s,int e)
    {
        if(s>e)
        {
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums,s,mid-1);
        root->right = buildBST(nums,mid+1,e);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = buildBST(nums,0,nums.size()-1);
        return root;
    
    }
};