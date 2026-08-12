class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto [ch,cnt] : freq){
            pq.push({cnt,ch});
        }
        string res;
        while(!pq.empty()){
            auto [cnt,ch] = pq.top();
            pq.pop();
            res += string(cnt,ch);
        }
        return res;
    }
};