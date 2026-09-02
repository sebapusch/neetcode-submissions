class Solution {
public:
    vector<int> productExceptSelfDivision(vector<int>& nums) {
        vector<int> out(nums.size());
        
        int zero_ix = -1;
        int product = 1;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                if (zero_ix >= 0)
                    return out;
                else
                    zero_ix = i;
            }
            else
                product *= nums[i];
        }

        if (zero_ix < 0)
        {
            for (size_t i = 0; i < nums.size(); ++i)
                out[i] = product / nums[i];
        }
        else
            out[zero_ix] = product;

        return out;
    }

    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);

        for (size_t ix = 0; ix < nums.size(); ++ix)
        {
            int jx = nums.size() - ix - 1;

            if (ix > 0)
                prefix[ix] = prefix[ix - 1] * nums[ix - 1];
            
            if (jx < nums.size() - 1)
                suffix[jx] = suffix[jx + 1] * nums[jx + 1];
        }

        vector<int> out(nums.size());

        for (size_t ix = 0; ix < nums.size(); ++ix)
            out[ix] = prefix[ix] * suffix[ix];

        return out;
    }
};
