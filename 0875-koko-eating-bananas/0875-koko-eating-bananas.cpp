class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxNum = INT_MIN;
        for (auto& it : piles) {
            maxNum = max(maxNum, it);
        }
        return maxNum;
    }
    long long findHour(vector<int>& piles, int& h) {
        long long totalH = 0;
        for (auto& it : piles) {
            totalH += ceil((double)it / (double)h);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = findHour(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};