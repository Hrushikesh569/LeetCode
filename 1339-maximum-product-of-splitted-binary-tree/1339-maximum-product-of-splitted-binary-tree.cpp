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
 #define ll long long 
class Solution {
public:
    ll tSum = 0 ;
    ll m = 1e9+7;
    ll maxi = 0 ; 
    ll totalSum(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left = totalSum(root->left);
        int right = totalSum(root->right);
        return (root->val + left + right);
    }
       ll  find(TreeNode* root)
    {
        if(!root) return 0; 
        ll sumSub = find(root->left) + find(root->right) + root->val;
        ll rem = tSum - sumSub;
        maxi = max(maxi,rem*sumSub);
        return sumSub;
      
    }
    int maxProduct(TreeNode* root) {
        tSum = totalSum(root);
        maxi = 0; 
        find(root);
        ll ans = maxi ;
        
        return ans%m;
    }
};