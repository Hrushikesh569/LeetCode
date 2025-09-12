class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(auto i : s) 
        {
            if(i=='a' || i=='u' || i=='o' || i=='i' || i=='e' )
            {
                cnt++;
            }
        }
        return cnt;
    }
   
};