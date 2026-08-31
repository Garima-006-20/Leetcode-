class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int index, vector<int>& current) {
        // Every current subset is a valid answer
        result.push_back(current);

        // Try adding each remaining element
        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);

            backtrack(nums, i + 1, current);

            // Backtrack: remove the element
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;

        backtrack(nums, 0, current);

        return result;
    }
};