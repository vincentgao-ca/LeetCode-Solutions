// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unprocessed_entries records the existence of each entry in num.
        unordered_set<int> unprocessed_entries;
        for (const auto& num : nums) {
            unprocessed_entries.emplace(num);
        }

        int max_interval_size = 0;
        while (!unprocessed_entries.empty()) {
            int num = *unprocessed_entries.begin();
            unprocessed_entries.erase(num);

            // Finds the lower bound of the largest range containing a.
            int lower_bound = num - 1;
            while (unprocessed_entries.count(lower_bound)) {
                unprocessed_entries.erase(lower_bound);
                --lower_bound;
            }

            // Finds the upper bound of the largest range containing a.
            int upper_bound = num + 1;
            while (unprocessed_entries.count(upper_bound)) {
                unprocessed_entries.erase(upper_bound);
                ++upper_bound;
            }
            max_interval_size =
            max(max_interval_size, upper_bound - lower_bound - 1);
        }
        return max_interval_size;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_map<int, int> hash;
        int ans{1};
        for (const auto& i : nums) {
            if (!hash[i]) {
                hash[i] = 1;
                int leftbound{hash[i - 1]}, rightbound{hash[i + 1]}; // Get neighbor info.
                hash[i - leftbound] = hash[i + rightbound] = 1 + leftbound + rightbound; // Update left and right bound info.
                ans = max(ans, 1 + leftbound + rightbound);
            }
        }
        return ans;
    }
};

//Time: O(n), Space:O(1)
class Solution3 {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.size()<1)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        bool cons = false;
        int result = 1;
        int last = nums[0];
        int onetime = 1;
        
        for(int i=1; i<n; i++) {
        
            if (cons == false) {
                if (last + 1 == nums[i]) {
                    cons = true;
                    result = max(result, ++onetime);
                }
              
            }
            else {
                if (last +1 == nums[i]) {
                    result = max(result, ++onetime);
                }
                else if ( last != nums[i]) {
                    cons = false;
                    onetime =1;
                }
            }
            
            last = nums[i];
        }
        
        return result;
        
    }
};
