class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> mp; // fruit type -> frequency

        int left = 0;
        int ans = 0;

        // Expand the window
        for (int right = 0; right < fruits.size(); right++) {

            // Add current fruit to the window
            mp[fruits[right]]++;

            // If more than 2 fruit types, shrink the window
            while (mp.size() > 2) {

                mp[fruits[left]]--;

                // Remove the fruit type if its count becomes 0
                if (mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);

                left++;
            }

            // Update the maximum window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};