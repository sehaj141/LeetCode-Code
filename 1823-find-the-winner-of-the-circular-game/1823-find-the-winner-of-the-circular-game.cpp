class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // Base case for 1 person (0-indexed)
        
        // Build up from 2 people to n people
        for (int i = 2; i <= n; ++i) {
            winner = (winner + k) % i;
        }
        
        // Convert from 0-indexed to 1-indexed
        return winner + 1;
    }
};