class Solution {
public:
    int bestClosingTime(string nums) {
        int cnt = 0 ;
        int ind = 0 ; 
        for(auto i  : nums)
        {
           cnt+=(i=='N');
        }
        int cur = cnt;
        int x = 0;
        for(auto i : nums)
        {
            x++;
            cur=(i=='Y')?++cur:--cur;
            if(cur>cnt)
            {
                ind  = x;
                cnt = cur;
            }
        }
        return ind;
    }
};