class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        while(repeated.size() < b.size()){
            repeated += a;
            count++;
        }
        if(repeated.find(b) != string::npos){
            return count;
        }
        repeated += a;
        if(repeated.find(b) != string::npos){
            return count + 1;
        }
        return -1;
        /*
        string repeated = a;
        int count = 1;

        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }
        //string.find(substring)
       // It searches for substring inside the string ; It returns: Index of the first occurrence if found ; string::npos if not found.
        if (repeated.find(b) != string::npos)
            return count;

        repeated += a;

        if (repeated.find(b) != string::npos)
            return count + 1;

        return -1;
        */
    }
};