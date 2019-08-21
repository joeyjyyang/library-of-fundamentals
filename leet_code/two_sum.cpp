/*
 * Runtime: 4 ms - Beats 99.71% of submissions
 * Memory: 10 MB - Beats 56.40% of submissions
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> answer;
        std::unordered_map<int, int> hash_table;
        for (int i=0; i<nums.size(); i++)
        {
            int difference = target - nums[i];
            if (hash_table.find(difference) != hash_table.end() && hash_table[difference] != i)
            {
                answer.push_back(i);
                answer.push_back(hash_table[difference]);
                break;
            }
            else
            {
                hash_table.insert(std::make_pair(nums[i], i));
            }
        }
        return answer;
    }
};

