class Solution {
public:
    static const int MOD=1e9+7;

    long long merge(vector<int>&arr,int low,int mid,int high)
    {
        long long c=0;
        int left=low;
        int right=mid+1;
        vector<int>temp;

        while(left<=mid && right<=high)
        {
            if(arr[left]<=arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                c+=(mid-left+1);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
    
        while(right<=high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
        return c;
    }
    
    long long mergesort(vector<int>&arr,int low,int high)
    {
        if(low>=high)return 0;

        int mid=low+(high-low)/2;
        long long c=0;

        c+=mergesort(arr,low,mid);
        c+=mergesort(arr,mid+1,high);
        c+=merge(arr,low,mid,high);

        return c;
    }

    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<a){
                arr.push_back(0);
            }
            else if(nums[i]<=b){
                arr.push_back(1);
            }
            else{
                arr.push_back(2);
            }
        }

        long long ans=mergesort(arr,0,arr.size()-1);

        return ans%MOD;
    }
};