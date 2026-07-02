class Solution {
public:
    int findMax(vector<int>& arr){
        int maxNum = INT_MIN;
        for(auto& it:arr){
            maxNum = max(maxNum,it);
        }
        return maxNum;
    }
    long long no_of_days(vector<int>& weights,int days,int cap){
        long long cnt = 0;
        int sum = 0;
        int n = weights.size();
        int i = 0;
        while(i<n){
            if(sum+weights[i]>cap){
                cnt++;
                sum = 0;
            }else{
                sum += weights[i];
                i++;
            }
        }
        if(sum>0) cnt++;
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = findMax(weights);
        int n = weights.size();
        int high = 0;
        for(int i = 0;i<n;i++){
            high += weights[i];
        }
        while(low<=high){
            int mid = low + (high - low)/2;
            long long day = no_of_days(weights,days,mid);
            if(day<=days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;

    }
};