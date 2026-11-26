class Solution {
public:
    bool canAliceWin(int n) {
        int c=0;
        int f=10;
        while(n>=0)
        {
            n=n-f;
            f--;
            c++;
        }
        if(c%2==0)return true;

        return false;
    }
};