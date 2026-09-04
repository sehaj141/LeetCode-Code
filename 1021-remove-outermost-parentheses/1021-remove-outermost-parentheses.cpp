class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int level = 0;
        for(char c : s){
            if(c == '('){
                if(level > 0) result += c;
                level++;
            }else if (c == ')'){
                level--;
                if(level > 0) result += c;
            }
        }
        return result;
    }
};