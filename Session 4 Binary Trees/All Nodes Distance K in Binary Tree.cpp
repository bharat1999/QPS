// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void find_parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parents)
    {
        if(!root)
            return;
        if(root->left)
        {
            parents[root->left]=root;
            find_parents(root->left,parents);
        }
        if(root->right)
        {
            parents[root->right]=root;
            find_parents(root->right,parents);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parents;
        find_parents(root,parents);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        vector<int> res;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                auto cur = q.front();
                q.pop();
                visited[cur]=true;
                if(k==0)
                    res.push_back(cur->val);
                if(cur->left and !visited[cur->left])
                    q.push(cur->left);
                if(cur->right and !visited[cur->right])
                    q.push(cur->right);
                if(parents.count(cur)>0 and !visited[parents[cur]])
                    q.push(parents[cur]);
            }
            k--;
        }
        return res;
    }
};