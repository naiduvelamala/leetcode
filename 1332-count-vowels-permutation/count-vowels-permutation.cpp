class Solution {
public:
    const int MOD=pow(10,9)+7;
    int a=0,e=1,i=2,o=3,u=4;
    vector<vector<long long>>temp;
    long long helper(int ch,int n)
    {
        if(n==0)
        return 1;

        if(temp[ch][n]!=-1)
        return temp[ch][n];

        if(ch==a)
        {
            temp[ch][n]=helper(e,n-1)%MOD;
        }
        else if(ch==e)
        {
            temp[ch][n]=(helper(a,n-1)+helper(i,n-1))%MOD;
        }
        else if(ch==i)
        {
            temp[ch][n]=(helper(a,n-1)+helper(e,n-1)+helper(o,n-1)+helper(u,n-1))%MOD;
        }
        else if(ch==o)
        {
            temp[ch][n]=(helper(i,n-1)+helper(u,n-1))%MOD;
        }
        else if(ch==u)
        {
            temp[ch][n]=(helper(a,n-1))%MOD;
        }
        return temp[ch][n];
    }
    int countVowelPermutation(int n) {
        int res=0;
        temp.resize(5,vector<long long>(n+1,-1));

        res=(res+helper(a,n-1))%MOD;
        res=(res+helper(e,n-1))%MOD;
        res=(res+helper(i,n-1))%MOD;
        res=(res+helper(o,n-1))%MOD;
        res=(res+helper(u,n-1))%MOD;

        return res;
    }
};