class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        for (int ix = 0; ix < len; ++ix)
        {
            for (int jx = ix + 1; jx < len; ++jx)
            {
                if (nums[ix] + nums[jx] == target)
                    return vector<int>{ix, jx};
            }
        }

        return vector<int>();
    }
};
