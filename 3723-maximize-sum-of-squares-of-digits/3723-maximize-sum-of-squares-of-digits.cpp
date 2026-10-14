class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(num>0){
            if(sum>9){
                ans += '9';
                sum -= 9;
            }else{
                char ch = sum + '0';
                ans += ch;
                sum = 0;
            }
            num--;
        }
        if(sum>0) ans = "";
        return ans;
    }
};