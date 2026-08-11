class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // If current window sum >= target
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);

                // Remove left element
                sum -= nums[left];
                left++;
            }
        }

        // If no valid subarray exists
        return minLen == INT_MAX ? 0 : minLen;
    }
};