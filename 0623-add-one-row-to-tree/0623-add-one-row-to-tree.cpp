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
    int d = 0 , v = 0 ;
    TreeNode* dfs(TreeNode* root , int cur)
    {
        if(!root) return root;
        if(cur+1==d)
        {
            TreeNode* node = new TreeNode(v);
            TreeNode* node2 = new TreeNode(v);
            node->left = root->left;
            node2->right = root->right;
            root->left = node;
            root->right = node2 ;
            return root;
        }
        dfs(root->left,cur+1);
        dfs(root->right,cur+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        v = val;
        d = depth;
        if(depth==1) 
        {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        return dfs(root, 1);
    }
};