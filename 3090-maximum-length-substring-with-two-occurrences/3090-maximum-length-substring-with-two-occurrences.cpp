class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len = 0;
        int n = s.size();
        int i = 0;
        int j = 0;
        vector<int> mpp(26,0);
        while(j<n){
            int ch = s[j] - 'a';
            mpp[ch]++;
            while(mpp[ch]>2){
                mpp[s[i]-'a']--;
                i++;
            }
            len = max(len,j-i+1);
            j++;
        }
        return len;
    }
};