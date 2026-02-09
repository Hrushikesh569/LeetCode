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
    void dfs(TreeNode* root, vector<int>&v)
    {
        if(!root) return ; 
        
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    TreeNode* bst( int low , int high,vector<int>&v)
    {
        if(low>high) return NULL;
        int mid = low + (high -  low)/2;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = bst(low , mid -1 , v);
        node->right = bst(mid+1 , high,v);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        dfs(root,v);      
        for(auto i : v)cout<<i<<" ";
        return bst(0 , v.size()-1,v);  
    }
};