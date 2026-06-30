class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> mpp;
        int max_len = 1;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int num = arr[i] - difference;
            if(mpp.find(num)!=mpp.end()){
                mpp[arr[i]] = mpp[num] + 1;
            }else{
                mpp[arr[i]] = 1;
            }
            max_len = max(max_len,mpp[arr[i]]);
        }
        return max_len;
    }
};