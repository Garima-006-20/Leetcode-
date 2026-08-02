class Solution {
public:

    set<vector<int>> s;

    void getAllCombinations(vector<int>& arr, int tar, int idx,
                            int target, vector<vector<int>>& ans,
                            vector<int> combin) {

        // Base cases
        if (idx == arr.size() || tar < 0) {
            return;
        }

        if (tar == 0) {
            if (s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        // Include current element
        combin.push_back(arr[idx]);

        // Use current element only once
        getAllCombinations(arr, tar - arr[idx], idx + 1,
                           target, ans, combin);

        // Use current element multiple times
        getAllCombinations(arr, tar - arr[idx], idx,
                           target, ans, combin);

        combin.pop_back();

        // Exclude current element
        getAllCombinations(arr, tar, idx + 1,
                           target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> combin;

        // Clear set for safety
        s.clear();

        getAllCombinations(candidates, target, 0,
                           target, ans, combin);

        return ans;
    }
};