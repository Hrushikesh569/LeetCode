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
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int cur = 1;
        while(!q.empty())
        {
             auto node = q.front();
             q.pop();
             if(node.second==depth-1)
             {
                TreeNode* leftside = new TreeNode(val);
                TreeNode* rightside = new TreeNode(val);
                leftside->left = node.first->left;
                rightside->right = node.first->right;
                node.first->left = leftside;
                node.first->right = rightside;
             }
             if(node.first->left)
             q.push({node.first->left,node.second+1});
             if(node.first->right)
             q.push({node.first->right,node.second+1});
        }
        return root;
    }
};