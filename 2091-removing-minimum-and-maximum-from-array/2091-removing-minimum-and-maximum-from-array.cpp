class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int max_i = 0;
        int min_i = 0;
        int max_num = INT_MIN;
        int min_num = INT_MAX;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int val = nums[i];
            if(val>max_num){
                max_num = val;
                max_i = i;
            }
            if(val<min_num){
                min_num = val;
                min_i = i;
            }
        }
        int left = min(max_i,min_i);
        int right = max(max_i,min_i);

        int bfr = right + 1;
        int bba = n - left;
        int op = left + 1 + (n - right);

        return min({bfr,bba,op});
    }
};