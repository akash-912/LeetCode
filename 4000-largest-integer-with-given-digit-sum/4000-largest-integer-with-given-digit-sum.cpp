class Solution {
public:
    int largestInteger(int n, int s) {
        if (9 * n < s) {
            return -1;
        }
        if(s==0) return 0;
        int start = pow(10,n-1);
        int end = pow(10,n);
        int ans = -1;
        for(int i = start;i<end;i++){
            string k = to_string(i);
            int num = 0;
            for(auto ch: k){
                num += ch - '0';
            }
            if(num==s){
                int digit = stoi(k);
                ans = max(ans,digit);
            }
        }
        return ans;
    }
};