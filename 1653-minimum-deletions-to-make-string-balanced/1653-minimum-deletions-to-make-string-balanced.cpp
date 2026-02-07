class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        // int st = -1 ; 
        // int end = 0 ; 
        // int x[2]{0};
        // for(int i = 0 ; i < n ;i++)
        // {
        //     x[s[i]-'a']++;
        //     if(s[i]=='b' && st==-1)
        //     {
        //         st = i ; 
        //     }
        //     if(s[i]=='a') end = i ;
        // }
        // if(st==-1 || end==0) return 0 ; 
        // int arr[2] = {0};
        // for(int i = st ; i <=end ; i++)
        // {
        //     arr[s[i]-'a']++;
        // }
        // cout<<x[0]<<" "<<x[1];
        // return min(arr[0],arr[1]);
    
    int total = 0 ; 
    int  a = 0 ;
    int  b  = 0 ;
    for(auto i : s)
    {
        if(i=='a')
        {
            a++;
        }
        else
        {
            b++;
        }
       // cout<<a<<" "<<b<<endl;
        if(a>b) 
        {
            total+=b;
            a = 0 , b = 0 ;
        }
    }
    total+=min(a,b);
        return total;
    
    }
};