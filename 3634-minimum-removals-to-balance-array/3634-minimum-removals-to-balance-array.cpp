class Solution {
public:
    #define ll long long 
    int minRemoval(vector<int>& nums, int k) {
        int n  = nums.size();
        if(n==1) return 0;
       sort(nums.begin(),nums.end());

      // for(auto i : nums)cout<<i<<" ";
        int i = 0 , j = 1 ; 
        
        int mini =1e9;
        while(i<=j and j<n)
        {
            while(j<n && 1LL*nums[i]*k>=1LL*nums[j])
            {
                
             //   cout<<i<<" "<<j<<endl;
                mini = min(mini,n-(j-i+1));
                j++;
            }
            if(j<n and nums[i]*k<nums[j])
            i++;
        }
        return mini ; 
    }
};