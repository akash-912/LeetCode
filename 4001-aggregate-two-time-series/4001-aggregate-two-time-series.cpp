class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        int n = series1.size();
        int m = series2.size();

        while(i<n&&j<m){
            int val1 = series1[i][0];
            int val2 = series2[j][0];
            if(val1==val2){
                ans.push_back({val1,series1[i][1]+series2[j][1]});
                i++;
                j++;
            }
            else if(val1>val2){
                ans.push_back({val2,series1[i][1]+series2[j][1]});
                j++;
            }else{
                ans.push_back({val1,series1[i][1]+series2[j][1]});
                i++;
            }
        }

        while(i<n){
            int val1 = series1[i][0];
            ans.push_back({val1,series1[i][1]});
            i++;
        }
        while(j<m){
            int val2 = series2[j][0];
            ans.push_back({val2,series2[j][1]});
            j++;
        }
        return ans;
    }
};