#include <vector>
#include <string>
#include <unordered_set>
#include <numeric>

class Solution {
public:
    int minimumLengthEncoding(std::vector<std::string>& words) {
        // Step 1: Store all unique words
        std::unordered_set<std::string> uniqueWords(words.begin(), words.end());

        // Step 2: Remove any word that is a suffix of another word
        for (const std::string& word : words) {
            for (int i = 1; i < word.length(); ++i) {
                uniqueWords.erase(word.substr(i));
            }
        }

        // Step 3: Sum up the lengths of all remaining words + 1 for each '#'
        int totalLength = 0;
        for (const std::string& word : uniqueWords) {
            totalLength += word.length() + 1;
        }

        return totalLength;
    }
};