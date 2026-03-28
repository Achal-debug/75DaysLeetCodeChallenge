// Day 17 - 75 Days LeetCode Challenge 
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, maxFreq = 0, maxLen = 0;
        for(int right = 0; right < s.length(); right++){
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            // check condition
            while((right - left + 1) - maxFreq > k){
                count[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};