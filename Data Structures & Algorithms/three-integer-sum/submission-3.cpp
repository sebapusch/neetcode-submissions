class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> combinations;

        for (size_t ix = 0; ix < nums.size() - 2; ++ix)
        {
            if (ix > 0 and nums[ix] == nums[ix - 1])
                continue;

            int target = -nums[ix];
            int jx = ix + 1;
            int hx = nums.size() - 1;

            while (jx < hx)
            {
                int sum = nums[jx] + nums[hx]; 
                if (sum == target)
                {
                    combinations.push_back({nums[ix], nums[jx], nums[hx]});
                    
                    while (jx < hx and nums[++jx] == combinations[combinations.size() - 1][1])
                        ;

                    while (hx > jx and nums[--hx] == combinations[combinations.size() - 1][2])
                        ;
                }
                else if (sum > target)
                    --hx;
                else
                    ++jx;
            }
        }

        return combinations;
    }
};
