class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;

        for(int i=0;i<n;i++)
        mp[nums[i]]++;
        int res=0;
        if(k==0)
        {
            for(auto it: mp)
            {
                if(it.second>1)
                res++;
            }
        }
        else{
            for(auto it:mp)
            {
                if(mp.count(it.first+k))
                {
                    res++;
                }
            }
        }
        return res;
    }
};