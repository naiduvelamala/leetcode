class Solution {
public:
    vector<vector<int>>res;
    void helper(vector<int>&path, int k, int n, int ind,int sum)
    {
        if(sum>n)
        return;

        if(path.size()==k)
        {
            if(sum==n)
            {
                res.push_back(path);
            }
            return;
        }

        for(int i=ind;i<=9;i++)
        {
            path.push_back(i);
            helper(path,k,n,i+1,sum+i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>path;
        helper(path,k,n,1,0);

        return res;
    }
};