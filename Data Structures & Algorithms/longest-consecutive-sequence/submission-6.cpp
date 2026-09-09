class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> num_set(nums.begin(), nums.end());

        int max = 0;
        int cur = 0;
        int len;
        for (auto num : num_set)
        {
            if (num_set.contains(num - 1))
                continue;
            
            cur = num;
            while (num_set.contains(++cur))
                ;

            len = cur - num;
            if (len > max)
                max = len;
        }

        return max;
    }
};
