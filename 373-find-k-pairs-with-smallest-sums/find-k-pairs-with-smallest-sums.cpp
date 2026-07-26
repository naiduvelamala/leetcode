class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>res;
        priority_queue<pair<int,pair<int,int>>>pq;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)pq.push({sum,{nums1[i],nums2[j]}});
                else if(sum<pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else{
                    break;
                }
            }
        }

        while(!pq.empty())
        {
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};