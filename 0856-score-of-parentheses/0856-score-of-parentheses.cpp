class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); // base score

        for(char c : s){
            if(c == '('){
                st.push(0); // start new inner score
            } else {
                int v = st.top(); st.pop(); // score inside ()
                int w = st.top(); st.pop(); // score outside
                st.push(w + max(2 * v, 1)); // if v=0 then () = 1
            }
        }
        return st.top();
    }
};