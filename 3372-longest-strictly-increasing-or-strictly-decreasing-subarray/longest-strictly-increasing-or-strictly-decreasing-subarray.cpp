class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int in=1;
        int des=1;
        int res=1;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            in=nums[i-1]<nums[i] ? in+1 : 1;
            des=nums[i-1]>nums[i]? des+1 : 1;
            res=max({in,des,res});
        }

        return res;
    }
};