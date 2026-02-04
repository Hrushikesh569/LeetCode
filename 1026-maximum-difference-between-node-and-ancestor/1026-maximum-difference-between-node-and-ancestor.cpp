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
        int ans  ;
        int dfs(TreeNode* root,int maxi , int mini)
        {
            if(!root)
            {
                return abs(mini - maxi);
            }
            mini = min(root->val,mini);
            maxi = max(root->val,maxi);
           int l = dfs(root->left,maxi,mini);
           int r = dfs(root->right,maxi,mini);
           return max(r,l);
        }
        int maxAncestorDiff(TreeNode* root) {
            
            return dfs(root,-6000,6000); 
        }
    };