class Solution {
public:
    int minFlips(string s) {
        int ans = 0 ; 
        int n = s.size();
        int arr[2] = {0 }; 
        
        for(auto i : s)
        {
            arr[i-'0']++;
        }
        if(s[0]==s[n-1] and s[0]=='1' and arr[0]==n-2)
        {
            return 0 ; 

        }
        if(arr[0]==n-1 or arr[1]==0 or arr[1]==n) return 0 ; 
        if(s[0]==s[n-1] and s[0]=='1')
        {
            int x = arr[1]-2;
            return min({arr[0],x});
        }
        return min(arr[1]-1 , arr[0]);
    }
};