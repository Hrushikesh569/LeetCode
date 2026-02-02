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
    void dfs(TreeNode* root , int sum , vector<vector<int>>&ans , vector<int>&temp)
    {
        if(root==NULL)
        {
            return ;
        }
        sum+=root->val;
        temp.push_back(root->val);
        if(!root->left and !root->right and sum==t) 
        {
            ans.push_back(temp);
        }
        dfs(root->left , sum,ans,temp);
        dfs(root->right, sum,ans , temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        t = targetSum;
        dfs(root , 0,ans, temp);
        return ans;
    }
};