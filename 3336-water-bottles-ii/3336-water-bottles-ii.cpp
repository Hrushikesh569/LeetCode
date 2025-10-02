class Solution {
public:
    int maxBottlesDrunk(int n, int ex) {
        if(ex>n) return n;
        int total = n;
        int full = 0 , empty = n ;
        while(full+empty>=ex)
        {
            if(empty<ex)
            {
                empty+=full;
                total+=full;
                full = 0;
            }
            else
            {
                empty-=ex;
                ex++;
                full++;
            }
            cout<<full<<" "<<empty<<" "<<ex<<" "<<total<<endl;
        }
        total+=(full);
        return total;
    }
};