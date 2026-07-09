class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int m = queries.size();
        int n = nums.size();
        vector<int> ans(m,0);
        vector<int> prefSum(n,0);
        prefSum[0] = nums[0];
        for(int i = 1;i<n;i++){
            prefSum[i] = prefSum[i-1] + nums[i];
        }
        for(int i = 0;i<m;i++){
            int tar = queries[i];
            int low = 0;
            int high = n-1;
            int mid = low + (high -low)/2;
            while(low<=high){
                mid = low + (high - low)/2;
                if(prefSum[mid]<=tar){
                    ans[i] = mid + 1;
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};