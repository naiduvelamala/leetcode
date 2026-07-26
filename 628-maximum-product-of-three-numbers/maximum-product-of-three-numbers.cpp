class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return max(nums.back()*nums[n-2]*nums[n-3] , nums.back()*nums.front()*nums[1]);
    }
};