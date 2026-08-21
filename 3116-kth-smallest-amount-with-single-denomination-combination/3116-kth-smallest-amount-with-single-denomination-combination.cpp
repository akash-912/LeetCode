class Solution {
public:
    long long lcm(long long a,long long b){
        return a / gcd(a,b) * b;
    }
    long long count(long long x, vector<int>& coins) {
        long long ans = 0;
        int n = coins.size();

        for(int mask = 1;mask < (1 << n);mask++){
            long long multiple = 1;
            int bits = 0;

            for(int i = 0;i<n;i++){
                if((mask & (1 << i))!= 0) {
                    bits++;
                    multiple = lcm(multiple, coins[i]);

                    if(multiple > x) {
                        break;
                    }
                }
            }

            if(multiple> x) {
                continue;
            }

            long long value = x / multiple;
            if(bits % 2 == 1) {
                ans += value;
            }else {
                ans -= value;
            }
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;

        long long high = (long long) coins[0] * k;
        for(int coin : coins) {
            high = min(high, (long long) coin*k);
        }

        while(low < high) {
            long long mid = low + (high - low)/2;
            if(count(mid, coins) >=k) {
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};