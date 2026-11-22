class Solution {
public:
    const int MOD=1e9+7;
    long long dp[100001][3][2][2];

    long long helper(int n,int e,int l,int t)
    {
        if(n==0)
        {
            return (e==0 && l==0 && t==0);
        }

        if(dp[n][e][l][t]!=-1)
        return dp[n][e][l][t];
        
        return dp[n][e][l][t]=((helper(n-1,max(0,e-1),l,t))%MOD+(helper(n-1,e,0,t))%MOD+(helper(n-1,e,l,0))%MOD+23*helper(n-1,e,l,t))%MOD;

    }
    int stringCount(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n,2,1,1);
    }
};