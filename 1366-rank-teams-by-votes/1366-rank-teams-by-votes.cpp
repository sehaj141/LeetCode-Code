class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int numTeams = votes[0].length();
        
        // rankCount[26][numTeams]: tracks count of votes for each rank position
        vector<vector<int>> rankCount(26, vector<int>(numTeams, 0));
        
        // Populate vote counts
        for (const string& vote : votes) {
            for (int i = 0; i < numTeams; ++i) {
                rankCount[vote[i] - 'A'][i]++;
            }
        }
        
        // Initialize list of teams present in the voting
        string result = votes[0];
        
        // Custom sort teams based on voting criteria
        sort(result.begin(), result.end(), [&](char a, char b) {
            for (int i = 0; i < numTeams; ++i) {
                if (rankCount[a - 'A'][i] != rankCount[b - 'A'][i]) {
                    return rankCount[a - 'A'][i] > rankCount[b - 'A'][i];
                }
            }
            // Tie-breaker: alphabetical order
            return a < b;
        });
        
        return result;
    }
};