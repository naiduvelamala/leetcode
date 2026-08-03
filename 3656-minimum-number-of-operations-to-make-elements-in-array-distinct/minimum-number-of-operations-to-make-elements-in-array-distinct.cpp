class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        int ind=0;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                ind=i+1;
                break;
            }
        }

        if(ind==-1)return 0;
        else{
            return (ind+2)/3;
        }
    }
};