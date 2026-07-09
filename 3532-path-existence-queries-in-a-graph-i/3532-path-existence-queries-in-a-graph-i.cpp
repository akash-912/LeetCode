class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> connected(n,0);
        int com = 0;
        for(int i = 1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) com++;
            connected[i] = com;
        }
        vector<bool> ans;
        for(auto& it: queries){
            int i = it[0];
            int j = it[1];
            ans.push_back(connected[i]==connected[j]);
        }
        return ans;
    }
};