class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> num_set(nums.begin(), nums.end());

        int max = 0;
        int cur = 1; 
        for (auto num : num_set)
        {
            if (cur == 0)
            {
                if (not num_set.contains(num - 1))
                    ++cur;
            }
            else if (num_set.contains(num + 1))
            {
                ++cur;
            }
            else
            {
                if (cur > max)
                    max = cur;
                cur = 1;
            }
        }

        return max;
    }
};
