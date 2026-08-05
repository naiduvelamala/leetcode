class Solution {
public:
    int solve(vector<int>&arr,int k,vector<int>&dp, int ind)
    {
        int n=arr.size();
        if(ind==n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int ans=INT_MIN;
        int maxi=INT_MIN;
        int len=0;
        for(int i=ind;i<min(ind+k,n);i++)
        {
            len++;
            ans=max(ans,arr[i]);
            int sum=len*ans+solve(arr,k,dp,i+1);
            maxi=max(maxi,sum);
        }
        return dp[ind]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);

        return solve(arr,k,dp,0);
    }
};