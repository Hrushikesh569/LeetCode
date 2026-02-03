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
    
    void dfs(TreeNode* root,vector<int>&st)
    {
        if(!root) return ; 
        st.push_back(root->val);
        dfs(root->left,st);
      //  cout<<root->val<<" ";
        dfs(root->right,st);
        
    }
    int countNodes(TreeNode* root) {
       vector<int>st;
        dfs(root,st);
        return st.size();
    }
};