#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int openCount, int closeCount, int maxPairs) {
        // Base case: string has reached the maximum required length (2 * n)
        if (current.length() == maxPairs * 2) {
            result.push_back(current);
            return;
        }

        // Decision 1: Add an opening bracket if we haven't reached n yet
        if (openCount < maxPairs) {
            current.push_back('(');
            backtrack(result, current, openCount + 1, closeCount, maxPairs);
            current.pop_back(); // Undo choice for backtracking
        }

        // Decision 2: Add a closing bracket only if it doesn't exceed open brackets
        if (closeCount < openCount) {
            current.push_back(')');
            backtrack(result, current, openCount, closeCount + 1, maxPairs);
            current.pop_back(); // Undo choice for backtracking
        }
    }
};