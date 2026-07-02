class Solution {
public:
    int possible(vector<int>& bloomDay,int& day,int m,int k){
        int cnt = 0;
        int no_of_bouquets = 0;
        for(auto& it:bloomDay){
            if(it<=day){
                cnt++;
            }else{
                no_of_bouquets += (cnt)/k;
                cnt = 0;
            }
        }
        no_of_bouquets += (cnt)/k;
        return no_of_bouquets;
    }
    int findMin(vector<int>& arr){
        int minNum = INT_MAX;
        for(auto& it:arr){
            minNum = min(minNum,it);
        }
        return minNum;
    }
    int findMax(vector<int>& arr){
        int maxNum = INT_MIN;
        for(auto& it:arr){
            maxNum = max(maxNum,it);
        }
        return maxNum;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = findMin(bloomDay);
        int high = findMax(bloomDay);
        long long n = bloomDay.size();
        if((long long)m*(long long)k>n) return -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int bouquets = possible(bloomDay,mid,m,k);
            if(bouquets>=m){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};