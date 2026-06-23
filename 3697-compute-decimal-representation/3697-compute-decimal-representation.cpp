class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        string s = to_string(n);
        int k = s.size();
        vector<int> ans;
        int m = pow(10,k-1);
        for(int i = 0;i<k;i++){
            int x = s[i] - '0';
            if(x>0) ans.push_back(x*m);
            m = m/10;
        }
        return ans;
    }
};