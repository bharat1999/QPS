//https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/?category[]=Tree&category[]=Tree&problemStatus=solved&page=1&query=category[]TreeproblemStatussolvedpage1category[]Tree#


class Solution {
    int sumTree(Node* root)
    {
        if(!root)
            return 0;
        if(!root->left and !root->right) // if leaf node save value first and make 0
        {
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        int left = sumTree(root->left);
        int right = sumTree(root->right);
        int temp = left + right + root->data; // first save value to be returned
        root->data = left + right; // than update
        return temp;
    }
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        sumTree(node);
    }
};