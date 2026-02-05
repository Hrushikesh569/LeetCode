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
public:
    int maxi = 0 ;
    unordered_map<int,int>mp;
    void level(TreeNode* root , int deep)
    {
        if(!root) return ;
        mp[root->val]= deep;
        maxi  =  max(deep,maxi);
        level(root->left,deep+1);
        level(root->right,deep+1);
    }
    TreeNode* dfs(TreeNode* root)
    {
        if(!root) return root;
        if(mp[root->val]==maxi)
        return root;
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);
        if(left and right) return root;
        if(left) return left;
        return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        mp.clear();
        maxi = 0 ; 
        level(root,0);  
        return dfs(root);
    }
};