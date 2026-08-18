class Solution {
public:
    int INT_MIN_VAL = -pow(2,31) ; 
    int INT_MAX_VAL = pow(2,31) - 1;
    int helper(string &s, int i, long long num, int sign){
        if(i >= s.size() || !isdigit(s[i])){
            return (int)(sign * num);
        }
        num = num*10 + (s[i] - '0');

        if(sign*num <=  INT_MIN_VAL) return INT_MIN_VAL;
        if(sign*num >= INT_MAX_VAL) return INT_MAX_VAL;

        return helper(s,i+1,num,sign);
    }
    int myAtoi(string s) {
        int i=0;
        while(i <s.size() && s[i] == ' '){
            i++;
        }
        int sign = 1;
        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-')?-1 : 1;
            i++;
        }
        return helper(s,i,0,sign);
    }
};