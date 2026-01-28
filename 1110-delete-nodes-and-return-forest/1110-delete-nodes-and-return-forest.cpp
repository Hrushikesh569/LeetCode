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
    TreeNode* dfs(TreeNode* root , unordered_set<int>&st, vector<TreeNode*>&ans)
    {
        if(root==NULL)
        {
            return NULL;
        }
        root->left = dfs(root->left,st,ans);
        root->right =dfs(root->right,st,ans);
        if(st.count(root->val))
        {
            if(root->left)
            {
                ans.push_back(root->left);
            }
            if(root->right)
            {
                ans.push_back(root->right);
            }
            return NULL;
        }
        else
        {
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& v) {
        unordered_set<int>st;
        for(auto &i : v) st.insert(i);
        vector<TreeNode*>ans;
        dfs(root , st , ans);
       if(!st.count(root->val)) ans.push_back(root);
        return ans;
    }
};