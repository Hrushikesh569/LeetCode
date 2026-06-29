class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int end  = n - 1 ;
        int st = 0  ; 
       // while(end>=0 and nums[end]==2) end--;
      //  cout<<end<<" ";
        for(int i = 0 ; i < end; i++)
        {
            while(end>=0 and nums[end]==2) end--;
            if(nums[i]==2 and end>i) 
            {
                swap(nums[i],nums[end]);
                
            }
        } 
      //  while(st<n and nums[st]==0) st++;
       // cout<<st<<endl;
        for(int i = n - 1 ; i>st ; i--)
        {
            while(st<n and nums[st]==0) st++;
            if(nums[i]==0 and i>st)
            {
                swap(nums[i],nums[st++]);
                 
            }
        }
        
    }
};