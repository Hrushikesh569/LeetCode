class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 0 ; i < s.size() - 1 ; i++)
        {
          //  cout<<((s[i]-s[i+1]))<<endl;
            if(abs(-s[i]+s[i+1])>2) return 0 ;
        }
        return true;
    }
};