class Solution {
public:
    int minRotations(string s) {
        int n=s.size();
        int res=0;
        int prev=0;
        for(int i=0;i<n;i++)
        {
            int curr=s[i]-'0';
            int d=abs(curr-prev);
            res+=min(d,10-d);
            prev=curr;
        }
        return res;
    }
};