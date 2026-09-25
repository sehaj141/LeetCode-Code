class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        return solve(expression);
    }
    
private:
    vector<string> solve(string exp) {
        set<string> res;
        int n = exp.size();
        
        // Base: single char
        if (n == 0) return {""};
        
        vector<set<string>> groups;
        set<string> curr = {""};
        int i = 0;
        
        while (i < n) {
            if (exp[i] == '{') {
                // Find matching '}'
                int j = i + 1, cnt = 1;
                while (cnt > 0) {
                    if (exp[j] == '{') cnt++;
                    else if (exp[j] == '}') cnt--;
                    j++;
                }
                // Parse inside braces and get union
                vector<string> inner = solve(exp.substr(i + 1, j - i - 2));
                set<string> next;
                for (auto& a : curr) {
                    for (auto& b : inner) {
                        next.insert(a + b);
                    }
                }
                curr = move(next);
                i = j;
            } else if (exp[i] == ',') {
                // End current group, start new
                groups.push_back(curr);
                curr = {""};
                i++;
            } else {
                // Regular char, append to all strings in curr
                set<string> next;
                for (auto& s : curr) {
                    next.insert(s + exp[i]);
                }
                curr = move(next);
                i++;
            }
        }
        
        groups.push_back(curr);
        
        // Union all groups
        for (auto& g : groups) {
            res.insert(g.begin(), g.end());
        }
        
        return vector<string>(res.begin(), res.end());
    }
};