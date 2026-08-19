class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int totalTeams = 0;

        // Treat rating[j] as the middle soldier of the team
        for (int j = 1; j < n - 1; ++j) {
            int leftSmaller = 0, leftGreater = 0;
            int rightSmaller = 0, rightGreater = 0;

            // Count elements smaller and greater than rating[j] on the left
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    leftSmaller++;
                } else if (rating[i] > rating[j]) {
                    leftGreater++;
                }
            }

            // Count elements smaller and greater than rating[j] on the right
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) {
                    rightSmaller++;
                } else if (rating[k] > rating[j]) {
                    rightGreater++;
                }
            }

            // Combinations where rating[i] < rating[j] < rating[k]
            // and rating[i] > rating[j] > rating[k]
            totalTeams += (leftSmaller * rightGreater) + (leftGreater * rightSmaller);
        }

        return totalTeams;
    }
};