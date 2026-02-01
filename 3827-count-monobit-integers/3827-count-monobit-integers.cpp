class Solution {
public:
    // int arr[1001] = {0};
    // int flag = 0 ; 
    // void fun()
    // {
    //     flag = 1 ; 
    //     int val = 0 ; 
    //     arr[0] = 1; 
    //     for(int i = 1 ; i <=1000 ; i++)
    //     {
    //         arr[i] = arr[i-1];
            
    //     }
    // }
    int countMonobit(int n) {
        if(n<=1) return n+1; 
       int cnt = 0 ; 
       int val = n ; 
       int x = 0 ; 
       val++;
       while(val>0) 
       {
         if(val&1) x++;
         val>>=1;
       }val  = n ; 
       while(val>0)
       {
            val/=2;
            cnt++;
       }
       if(x==1) cnt++;
       return cnt;
    }
};