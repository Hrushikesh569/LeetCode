class Solution {
public:
    string addBinary(string aa, string bb) {
        int n = aa.size()-1;
        int m = bb.size()-1;
        string ans ="";
        int curry = 0,sum = 0 ; 
        while(n>=0 or m>=0)
        {
            sum = curry ;
            if(n>=0)
            {
                sum+=(aa[n]-'0');
                n--;
            }
            if(m>=0)
            {
                sum+=(bb[m]-'0');
                m--;
            }
            curry = (sum>1);
       //     cout<<curry<<" ";
            ans.push_back((sum%2==0?'0':'1'));
        }
      //  cout<<curry;
        if(curry)
        {
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};