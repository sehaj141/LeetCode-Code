class Solution {
public:
const int INT_MINI_VAL = -2147483648 ;
const int INT_MAXI_VAL =  2147483647;
    int helper(string &s, int i, long long num, int sign){
        if(i >= s.size() || !isdigit(s[i])){
            return (int)(num*sign);
        }
        num = num*10 + (s[i] - '0');

        if(sign*num <= INT_MINI_VAL) return INT_MINI_VAL;
        if(sign*num >= INT_MAXI_VAL) return INT_MAXI_VAL;

        return helper(s,i+1,num,sign);
    }
    int myAtoi(string s) {
       int i = 0;
       while(i< s.size() && s[i] == ' '){
         i++;
       } 
       int sign = 1;
       if(i<s.size() && (s[i] == '+' || s[i] == '-')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
       }
       return helper(s,i,0,sign);
    }
};