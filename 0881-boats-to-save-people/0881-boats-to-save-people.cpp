#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            // If the lightest and heaviest person can fit together
            if (people[left] + people[right] <= limit) {
                left++;
            }
            // Heaviest person always takes a boat (either alone or paired)
            right--;
            boats++;
        }
        
        return boats;
    }
};