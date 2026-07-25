class Solution {
public:
    int maxProduct(int n) {
        vector<int>dig;
        while(n!=0)
        {
            int t=n%10;
            n/=10;
            dig.push_back(t);
        }
        sort(dig.begin(),dig.end(),greater<>());
        
        return dig[0]*dig[1];
    }
};