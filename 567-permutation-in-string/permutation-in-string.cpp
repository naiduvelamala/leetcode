class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        vector<int>freq1(26,0);
        for(int i=0;i<n;i++)
        {
            freq1[s1[i]-'a']++;
        }
        int l=0;
        int r=0;
        vector<int>freq2(26,0);
        while(r<s2.size())
        {
            freq2[s2[r]-'a']++;

            if(r-l+1==s1.size())
            {
                if(freq1==freq2)
                return true;
            }

            if(r-l+1<s1.size())
            {
                r++;
            }
            else{
                freq2[s2[l]-'a']--;
                l++;
                r++;
            }
        }
        return false;

    }
};