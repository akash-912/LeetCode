class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        int count = 0;
        for(int j = 0;j<n-1;j++){
            set<char> st1;
            set<char> st2;
            vector<int> right(27,0);
            for(int k = j+1;k<n;k++){
                st2.insert(s[k]);
                right[st2.size()]++;
            }
            for(int i = j;i>=0;i--){
                st1.insert(s[i]);
                count += right[st1.size()];
            }
        }
        return count;
    }
};