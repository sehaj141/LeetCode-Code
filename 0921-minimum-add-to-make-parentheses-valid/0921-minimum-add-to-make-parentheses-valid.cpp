class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBracket = 0;
        int closedBracket = 0;

        for(char c : s){
            if(c == '('){
                openBracket++;
            }else{
                if(openBracket > 0){
                    openBracket--;
                }else{
                    closedBracket++;
                }
            }
        }
        return openBracket + closedBracket;
    }
};