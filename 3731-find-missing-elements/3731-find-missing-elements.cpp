class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int low = INT_MAX;
        int high = INT_MIN;

        // Find minimum and maximum
        for (int i = 0; i < nums.size(); i++) {
            low = min(low, nums[i]);
            high = max(high, nums[i]);
        }

        vector<int> ans;

        // Check every number between low and high
        for (int i = low; i <= high; i++) {

            bool found = false;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }

            if (!found)
                ans.push_back(i);
        }

        return ans;
    }
};