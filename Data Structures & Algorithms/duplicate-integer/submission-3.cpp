class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> unique;

        for (int num: nums)
        {
            if (unique.contains(num))
                return true;
            unique.insert(num);
        }

        return false;
    }
};