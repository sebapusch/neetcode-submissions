class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int ix = 0;
        int jx = numbers.size() - 1;

        while (true)
        {
            int sum = numbers[ix] + numbers[jx];

            if (sum == target)
                return {ix + 1, jx + 1};

            if (sum > target)
                --jx;
            else
                ++ix;
        }
    }
};
