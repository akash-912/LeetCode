class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack;
        stack<int> starStack;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]=='(') openStack.push(i);
            else if(s[i]=='*') starStack.push(i);
            else{
                if(!openStack.empty()) openStack.pop();
                else if(!starStack.empty()) starStack.pop();
                else return false;
            }
        }
        while(!openStack.empty()){
            if(starStack.empty()) return false;
            if(starStack.top()<openStack.top()) return false;

            openStack.pop();
            starStack.pop();
        }
        return true;
    }
};