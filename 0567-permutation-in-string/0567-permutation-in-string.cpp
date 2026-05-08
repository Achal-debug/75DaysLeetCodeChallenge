// Day 58 - 100 Days LeetCode Challenge
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for(char c : s1){
            count1[c - 'a']++;
        }
        int windowSize = s1.length();
        for(int i = 0; i < s2.length(); i++){
            count2[s2[i] - 'a']++;
            if(i >= windowSize){
                count2[s2[i - windowSize] - 'a']--;
            }

            if(count1 == count2){
                return true;
            }
        }

        return false;
    }
};