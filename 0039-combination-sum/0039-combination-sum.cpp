class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target,
                   int start, vector<int>& current) {

        // Target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Try all candidates
        for (int i = start; i < candidates.size(); i++) {

            // If candidate is greater than remaining target
            if (candidates[i] > target)
                continue;

            // Choose
            current.push_back(candidates[i]);

            // i again because same number can be reused
            backtrack(candidates, target - candidates[i], i, current);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;

        backtrack(candidates, target, 0, current);

        return result;
    }
};