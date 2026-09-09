class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> num_set(nums.begin(), nums.end());

        int max = 0;
        for (auto num : num_set)
        {
            if (num_set.contains(num - 1))
                continue;
            
            int cur_num = num;
            while (num_set.contains(++cur_num))
                ;

            int len = cur_num - num;
            if (len > max)
                max = len;
        }

        return max;
    }
};
