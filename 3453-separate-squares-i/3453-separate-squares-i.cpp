class Solution {
public:
    double area(double mid , vector<vector<int>>&v)
    {
        double total = 0;
        for(auto &i : v)
        {
            double  y = i[1];
            double  l = i[2];
            if(mid<y) continue;
            if(mid>=y+l)
            {
                total+=(l*l*1.0);
            }
            else if (mid>y && mid<y+l)
            {
                total+=(l*1.0*(mid-y));
            }
        }
        return total;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int  l  = 1e9;
        int  h= -1e9;
        double  total = 0 ; 
        for(auto &a:squares)
        {
            l = min(l , a[1]);
            h = max(h, a[1]+a[2]);
            total +=(a[2]*1.0*a[2]);
        }
        double low = l;
        double high = h;
        total /=2;
        double ans = 0 ; 
        while (high - low > 1e-6)
        {
            double mid = low + (high - low )/2;
            if(area(mid , squares)<total)
            {
                low = mid;
            }
            else
            {
                ans  = mid ; 
                high = mid;
            }
        }
     //   cout<<total<<" "<<low<<" "<<high<<endl;
        return ans ; 
    }
};