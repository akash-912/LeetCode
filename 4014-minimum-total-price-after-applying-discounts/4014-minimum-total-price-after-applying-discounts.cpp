class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        double sum = 0;
        int j = m - 1;
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        for(int i = n - 1;i>=0;i--){
            if(j>=0){
                double p = (double)prices[i];
                double d = (double)discounts[j];
                sum += (p*((100-d)/100));
                j--;
            }else{
                sum += (double)prices[i];
            }
        }
        return sum;
    }
};