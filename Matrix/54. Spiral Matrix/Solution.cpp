class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        int count=0;
        int rowStart=0,rowEnd=m-1,colStart=0,colEnd=n-1;
        while(count<m*n){
            for(int i=colStart;count<m*n && i<=colEnd;i++){
                count++;
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;
            for(int i=rowStart;i<=rowEnd && count<m*n;i++){
                count++;
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            for(int i=colEnd;i>=colStart && count<m*n;i--){
                count++;
                ans.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            for(int i=rowEnd;i>=rowStart && count<m*n;i--){
                count++;
                ans.push_back(matrix[i][colStart]);
            }
            colStart++;
            
        }
        return ans;
    }

};
