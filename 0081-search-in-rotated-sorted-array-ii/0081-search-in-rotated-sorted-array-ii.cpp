class Solution {
public:
    bool search(vector<int>& nums, int target) {
         // observations/................
        // what is the search space 
        // there is no monotones some timesss
        // divide into monotoness formate but howww???????
        // like check the sorted one first like if( some part is sorted ) then check 
        // is left part if(nums[mid]>= target) then we have high = mid - 1 ; or mid 
        // else low = mid 
        // else{ target>= nums[mid] then low = mid ; 
        // else {high = mid }}
        int low = 0 ,  high = nums.size()-1;
        int ans= -1 ; 
        while(low<= high)
        {
            int mid = low + (high - low)/2;
            if(target==nums[mid]) return 1;
            if(nums[low]==nums[mid]){ low++;
            continue;}
            if(nums[low]<=nums[mid])
            {
                if(target<=nums[mid] and target>= nums[low])
                {
                    ans = mid ; 
                    high = mid - 1 ; 
                }
                else
                {
                    low = mid + 1 ; 
                }
            }
            else
            {
                if(target>=nums[mid] and target<=nums[high])
                {
                    ans = mid ; 
                    low = mid + 1 ; 
                }
                else
                {
                    high = mid - 1 ; 
                }
            }
        }
        if(ans != -1 and nums[ans]!=target) return 0 ;
        if(ans==-1) return 0;
        return 1 ; 
    }
};