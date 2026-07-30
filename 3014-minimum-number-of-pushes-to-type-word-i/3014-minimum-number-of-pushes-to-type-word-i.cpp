class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int add = 1;
        for(int i = 0;i< word.size();i++){
            if(i>=8 && i%8==0){
                add++;
            }
            ans += add;
        }
        return ans;
    }
};