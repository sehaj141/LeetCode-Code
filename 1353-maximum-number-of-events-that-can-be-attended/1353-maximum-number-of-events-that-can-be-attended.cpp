class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events primarily by their start day
        sort(events.begin(), events.end());
        
        // Min-heap to store end days of currently available events
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int totalAttended = 0;
        int i = 0;
        int n = events.size();
        int day = 0;
        
        // Process until all events are considered and no events are left in heap
        while (i < n || !minHeap.empty()) {
            // If no active events, jump day directly to the start day of the next event
            if (minHeap.empty()) {
                day = events[i][0];
            }
            
            // Add all events starting on or before current 'day'
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }
            
            // Remove events that have already expired before 'day'
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
            
            // Attend the event that ends the earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                totalAttended++;
                day++;
            }
        }
        
        return totalAttended;
    }
};