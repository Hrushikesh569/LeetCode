class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn>8) return {};
        vector<string>ans;
        for(int i = 0 ;i <= 11 ; i++)
        {
            for(int j = 0 ; j <60 ; j++)
            {
                int cntmin= 0;
                int cnth = 0;  
                for(int bit =0 ; bit<32 ; bit++)
                {
                    if((j>>bit)&1)  cntmin++;
                    if((i>>bit)&1)  cnth++;
                }
                if(cntmin+cnth==turnedOn)
                {
                    string s = to_string(i);
                    string x = to_string(j);
                    if(x.size()==1) x = '0'+x;
                    ans.push_back(s+':'+x);
                }
            }
        }
        return ans;
    }
};