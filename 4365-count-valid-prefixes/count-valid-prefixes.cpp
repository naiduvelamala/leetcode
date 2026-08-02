class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();
        int a=0;
        int b=0;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='0'){
                a++;
            }
            else{
                b++;
            }
            if(abs(a-b)<=1){
                ans++;
            } 
        }
        return ans;
    }
};