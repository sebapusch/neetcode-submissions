class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, vector<int>> values;
        for (int ix = 0; ix < nums.size(); ++ix)
        {
            if (not values.contains(nums[ix]))
                values[nums[ix]] = vector<int>{ix};
            else
                values[nums[ix]].push_back(ix);
        }

        for (int ix = 0; ix < nums.size(); ++ix)
        {
            int value = target - nums[ix];

            if (value == nums[ix])
            {
                if (values[value].size() > 1)
                    return vector<int>{ix, values[value][1]};
            }
            else if (values.contains(value))
                return vector<int>{ix, values[value][0]};
        } 
    }
};
