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
    int t = 0 ;
    bool dfs(TreeNode* root, int sum)
    {
        if(root==NULL) return 0 ; 
        sum+=root->val;
     
        if(!root->left and !root->right and sum==t) return 1;
     //   cout<<sum<<" ";
      return dfs(root->left,sum) ||   dfs(root->right,sum);
    } 
    bool hasPathSum(TreeNode* root, int targetSum) {
        t = targetSum ;
        return dfs(root,0);
    }
};