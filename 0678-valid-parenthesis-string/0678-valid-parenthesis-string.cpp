class Solution {
public:
    bool checkValidString(string s) {
        int maxOpen = 0; // (
        int minOpen = 0;//  )

        for(char c : s){
            if(c == '('){
                maxOpen++;
                minOpen++;
            }else if (c == ')'){
                maxOpen--;
                minOpen--;
            }else{
                maxOpen++;
                minOpen--;
            }
            if(maxOpen < 0){
                return false;
            }
            minOpen = max(minOpen,0);
        }
        return minOpen == 0;
    }
};