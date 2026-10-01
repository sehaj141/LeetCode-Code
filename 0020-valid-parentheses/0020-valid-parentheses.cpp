#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // Push expected matching closing bracket
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } else {
                // If it's a closing bracket:
                // stack must not be empty and the top must match
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }
        
        // If the stack is empty, all brackets were properly matched
        return st.empty();
    }
};