class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> values;

        for (int ix = 0; ix < nums.size(); ++ix)
        {
            int value = target - nums[ix];

            if (values.contains(value))
                return {values[value], ix};
            else
                values[nums[ix]] = ix;
        }

        return {};
    }
};
