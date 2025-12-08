class Solution {
public:
    int flag = 0 ; 
    vector<int>count = vector<int>(251,0);
    void fun()
    {
        for(long long  i = 1 ; i  <= 250 ; i++)
        {
            for(long long  j = 1 ; j <= 250 ; j++)
            {
                long long x = i*i+j*j;
                long long c = (1LL)*sqrt(x);
                if(c*c==x)
                if(c<=250) count[c]++;
            }
        }
        long long maxi = 0 ; 
        for(int i = 1 ; i <=250 ;i++)
        {
            count[i]+=(count[i-1]);
        }
    }
    int countTriples(int n) {
        if(flag==0)
        {
            flag = 1; 
            fun();
        }
        for(int i = 0 ; i <= 250 ; i++) cout<<count[i]<<" ";
        return count[n];
    }
};