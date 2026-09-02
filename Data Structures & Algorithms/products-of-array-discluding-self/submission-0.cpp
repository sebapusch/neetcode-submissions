class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
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
};
