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
    void dfs(TreeNode* root , string &s , vector<string>&v)
    {
        if(!root)
        {
            return ;
        }
        s+=(root->val+'0');
        if(!root->left and !root->right)
        {
            v.push_back(s);
            
        }
        dfs(root->left,s,v);
        dfs(root->right,s,v);
        s.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        string s ; 
        vector<string>v;
        dfs(root,s,v);
        int ans = 0 ; 
        for(auto &i : v)
        {
            int val = 1;
            int temp = 0; 
            for(int j = i.size()-1 ;j>=0 ;j--)
            {
                if(i[j]-'0') temp+=val;
                val<<=1;
            }
        //    cout<<temp<<" ";
            ans+=temp;
        }
        return ans ; 
    }
    
};