class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }   
        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};