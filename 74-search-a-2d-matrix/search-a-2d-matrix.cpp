class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>r;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            r.push_back(matrix[i][m-1]);
        }
        int ind=-1;
        for(int i=0;i<r.size();i++)
        {
            if(r[i]==target)
            {
                return true;
            }
            if(r[i]>target)
            {
                ind=i;
                break;
            }
        }
        if(ind==-1)return false;
        for(int i=0;i<m;i++)
        {
            if(matrix[ind][i]==target){
                return true;
            }
        }
        return false;

    }
};