class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>v1,v2;
        string s = "";
        int n1 = version1.size();
        int n2 = version2.size();
        for(int ii = 0 ; ii < n1 ; ii++)
        {
            char i = version1[ii];
            if(i!='.')
            {
                s+=i;
            }
            else 
            {
                v1.push_back(s);
                s = "";
            }
            if(ii==n1-1) v1.push_back(s);
        }
        s="";
         for(int ii = 0 ; ii < n2 ; ii++)
        {
            char i = version2[ii];
            if(i!='.')
            {
                s+=i;
            }
            else 
            {
                v2.push_back(s);
                s = "";
            }
            if(ii==n2-1) v2.push_back(s);
        }
        if(v1.size()==0) v1.push_back((version1));
        if(v2.size()==0) v2.push_back((version2));
        int i = 0 , j = 0 ;
        int a1 = 0;
        int a2 = 0;
        //  for(auto i: v1)cout<<i<<" ";cout<<endl;
        // for(auto i: v2)cout<<i<<" ";
        while(i<v1.size() && j<v2.size())
        {
            int f1 = stoi(v1[i++]);
            int f2 = stoi(v2[j++]);
            cout<<f1<<" "<<f2<<endl;
            if(f1<f2) return -1;
            if(f1>f2) return 1;
        }
        
        while(i<v1.size())
        {
            int f1 = stoi(v1[i++]);
          
            a1+=f1;
    
            
        }
        while(j<v2.size())
        {
            int f2 = stoi(v2[j++]);
            a2+=f2;
        }
     //  cout<<a1<<" "<<a2<<endl;
       if(a1==a2) return 0;
        if(a1<a2) return -1;
        return 1;
       
        
    }
};