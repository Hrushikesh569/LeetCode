class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        
        
        int i  = n -1 , j = n +m-1  , k = m - 1 ; 
        
        while(i>=0  and k>=0 )
        {
            if(nums2[k]>=nums1[i])
            {
                nums1[j] = nums2[k];
                j--,k--;
            }
            else
            {
                nums1[j] = nums1[i];
                nums1[i] = 0  ; 
                i--,j--;
                
            }
        }
        while(k >= 0)
        {
            nums1[j] = nums2[k];
            j--;
            k--;
        }

    }
};