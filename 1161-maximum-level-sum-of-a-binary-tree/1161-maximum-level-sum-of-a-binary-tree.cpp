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
    map<int , int>mp;
  void dfs(TreeNode* root , int level)
    {
        if(!root) return;
        mp[level]+=root->val;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int maxSum = -1e9+7;  
        int level = 0 ; 
        // int curLevel = 1 ; 
        // while(!q.empty())
        // {
        //     int n = q.size();
        //     int sum = 0 ; 
        //     while(n--)
        //     {
        //         TreeNode* temp = q.front();
        //         q.pop();
        //         sum+=temp->val;
        //         if(temp->left) q.push(temp->left);
        //         if(temp->right)q.push(temp->right);
        //     }
        //     if(sum>maxSum)
        //     {
        //         maxSum = sum;
        //         level = curLevel;
        //     }
        //     curLevel++;
        // }
        mp.clear();
        dfs(root , 1);
        for(auto [i,j]:mp)
        {
            if(maxSum<j)
            {
                maxSum = j;
                level = i;
            }
        }
        return level;
    }
};