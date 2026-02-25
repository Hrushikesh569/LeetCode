class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        multiset<pair<int,int>>st;
        for(auto i : arr)
        {
            int cnt = 0 ; 
            for(int bit=0 ; bit<32;bit++)
            {
                cnt+=((i>>bit)&1);
            }
            st.insert({cnt,i});
        }
    
    vector<int>ans;
    for(auto &i: st){
        ans.push_back((i.second));
    }
    
    return ans;
    }
};