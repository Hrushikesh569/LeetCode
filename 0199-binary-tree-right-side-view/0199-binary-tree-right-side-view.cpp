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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL) return {};
        vector<int>ans;
        
        while(!q.empty())
        {
            int n = q.size();
            TreeNode* x  ; 
            while(n--)
            {
                x = q.front();
                q.pop();
                if(x->left!=NULL)
                {
                    q.push(x->left);
                }
                if(x->right)
                {
                    q.push(x->right);
                }
            }
            ans.push_back(x->val);

        }
        return ans;
    }
};