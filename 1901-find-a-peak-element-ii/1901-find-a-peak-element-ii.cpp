class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat,int n,int col){
        int maxInd = -1;
        int maxVal = -1;
        for(int i = 0;i<n;i++){
            if(mat[i][col]>maxVal){
                maxVal = mat[i][col];
                maxInd = i;
            }
        }
        return maxInd;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            int rowInd = findMaxIndex(mat,n,mid);
            int left = mid - 1>=0?mat[rowInd][mid-1]:-1;
            int right = mid + 1<m?mat[rowInd][mid+1]:-1;
            int val = mat[rowInd][mid];
            if(val>left&&val>right) return {rowInd,mid};
            else if(val<left) high = mid - 1;
            else low = mid + 1;
        }
        return {-1,-1};
    }
};