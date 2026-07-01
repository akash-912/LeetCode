class Solution {
public:
    long long findMin(vector<int>& ranks){
        long long minNum = LLONG_MAX;
        for(auto& it:ranks){
            minNum = min(minNum,(long long)it);
        }
        return minNum;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = findMin(ranks)*(long long)cars*(long long)cars;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long carsFixed = 0;
            for(auto& r:ranks){
                carsFixed += sqrt(mid/r);
            }
            if(carsFixed>=cars){
                high = mid - 1;
            }else low = mid + 1;
        }
        return low;
    }
};