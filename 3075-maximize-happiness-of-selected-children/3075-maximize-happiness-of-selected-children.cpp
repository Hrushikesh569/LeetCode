class Solution {
public:
    long long maximumHappinessSum(vector<int>& happy, int k) {
        sort(happy.rbegin(),happy.rend());
        long long  cnt = 0 , x=0 ; 
        for(int i = k - 1;  i>=0 ; i--)
        {
            int val = happy[i] - x++;
            val =  max(0,val);
          //  cout<<val<<" ";
            cnt+=val;
        }
       // cout<<endl;
        long long  cnt2 = 0 ;
         x = 0 ; 
        for(int i  =0 ; i < k ;i++)
        {
            int val = happy[i] - x++;
            val =  max(0,val);
          //  cout<<val<<" ";
            cnt2+=val;
        }
      //  cout<<cnt<<" "<<cnt2<<endl;
        return max(cnt2,cnt);
    }
};