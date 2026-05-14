// Day 64 - 100 Days LeetCode Challenge
class Solution {
public:
    int calculateHours(vector<int>& piles, int speed){
        int hours = 0;
        for(int pile : piles){
            hours += ceil((double)pile / speed);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left < right){
            int mid = left + (right - left) / 2;
            int hours = calculateHours(piles, mid);
            if(hours <= h){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};