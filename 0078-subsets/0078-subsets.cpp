class Solution {
public:
    vector<vector<int>> ans;
    vector<int> arr;

    void subset(vector<int>& nums, int index) {
        // Base case
        if (index == nums.size()) {
            ans.push_back(arr);
            return;
        }

        // Include current element
        arr.push_back(nums[index]);
        subset(nums, index + 1);

        // Backtrack
        arr.pop_back();

        // Exclude current element
        subset(nums, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        subset(nums, 0);
        return ans;
    }
};