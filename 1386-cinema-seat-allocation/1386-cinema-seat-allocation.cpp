class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map row number to a bitmask of reserved seats (bits 1 to 10)
        unordered_map<int, int> rowMasks;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // We only care about seats 2 through 9
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << col);
            }
        }

        // Bitmasks corresponding to the three valid 4-seat configurations
        // Left:   seats 2, 3, 4, 5 -> (1<<2 | 1<<3 | 1<<4 | 1<<5) = 4 + 8 + 16 + 32 = 60
        // Right:  seats 6, 7, 8, 9 -> (1<<6 | 1<<7 | 1<<8 | 1<<9) = 64 + 128 + 256 + 512 = 960
        // Middle: seats 4, 5, 6, 7 -> (1<<4 | 1<<5 | 1<<6 | 1<<7) = 16 + 32 + 64 + 128 = 240
        const int LEFT_MASK = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        const int RIGHT_MASK = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        const int MIDDLE_MASK = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

        // Any row with zero reservations can seat 2 families
        int totalFamilies = (n - rowMasks.size()) * 2;

        for (const auto& [row, mask] : rowMasks) {
            bool leftFree = (mask & LEFT_MASK) == 0;
            bool rightFree = (mask & RIGHT_MASK) == 0;
            bool middleFree = (mask & MIDDLE_MASK) == 0;

            if (leftFree && rightFree) {
                totalFamilies += 2;
            } else if (leftFree || rightFree || middleFree) {
                totalFamilies += 1;
            }
        }

        return totalFamilies;
    }
};