class Solution {
public:
    string largestOddNumber(string num) {
        int end = -1;
        int i;
        for( i= num.size()-1;  i >= 0; i--){
            if((num[i]-'0') % 2 != 0){
                end = i;
                break;
            }
        }
        i = 0;
        while(i <= end && num[i] == '0'){
            i++;
        }
        return num.substr(i, end-i+1);
    }
};