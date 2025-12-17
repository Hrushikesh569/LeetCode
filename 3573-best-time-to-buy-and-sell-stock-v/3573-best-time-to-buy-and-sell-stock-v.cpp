class Solution{
public:
long long dp[1001][501][3];
long long f(int a,int b,int c,vector<int>&p){
if(a==p.size()){
if(c==0)return 0;
return INT_MIN;
}
if(dp[a][b][c]!=INT_MIN)return dp[a][b][c];
long long x=INT_MIN,y=f(a+1,b,c,p);
if(b>0){
if(c==1)x=p[a]+f(a+1,b-1,0,p);
else if(c==2)x=-p[a]+f(a+1,b-1,0,p);
else x=max(-p[a]+f(a+1,b,1,p),p[a]+f(a+1,b,2,p));
}
return dp[a][b][c]=max(x,y);
}
long long maximumProfit(vector<int>&p,int b){
int n=p.size();
for(int i=0;i<n;i++)
for(int j=0;j<=b;j++)
for(int k=0;k<3;k++)
dp[i][j][k]=INT_MIN;
return f(0,b,0,p);
}
};
