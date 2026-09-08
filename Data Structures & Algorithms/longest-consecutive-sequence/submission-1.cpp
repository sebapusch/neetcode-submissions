class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        size_t longest = 0;
        size_t current = 1;
        
        int prev = nums[0];
        int num;

        for (size_t i = 1; i < nums.size(); ++i)
        {            
            num = nums[i];

            if (num == prev)
            {
                continue;
            }

            if (num != prev + 1)
            {
                if (current > longest)
                    longest = current;
                
                current = 1;
            }
            else
                ++current;

            prev = num;
        }

        if (current > longest)
            return current;

        return longest;
    }
};
