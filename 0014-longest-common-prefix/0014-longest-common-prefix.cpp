class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ;
        int n = 1e9 ;  
        for(auto  i : strs) n = min(n  , (int)i.size());   
    //    cout<<n<<endl;  
        for(int i = 0 ; i < n ; i++) 
        { 
            int cnt = 0;  
            char c= strs[0][i]; 
            for(int j = 0 ; j < strs.size(); j++)  
            {    
                cnt+=(c==strs[j][i]);  
            }    
           // cout<<c<<" "<<cnt<<endl; 
       if(cnt==strs.size()) 
            ans+=c;
        else break;
        }
        return ans;
    }
};