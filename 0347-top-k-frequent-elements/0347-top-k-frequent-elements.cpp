// Day 6 - 75 Days LeetCode Challenge
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        // Count frequency
        for(int num : nums){
            freq[num]++;
        }
        // Max Heap (frequency, element)
        priority_queue<pair<int,int>> pq;
        for(auto &p : freq){
            pq.push({p.second, p.first});
        }
        // Get top k elements
        vector<int> result;
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};