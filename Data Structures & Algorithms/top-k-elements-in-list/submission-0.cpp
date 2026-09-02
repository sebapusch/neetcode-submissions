class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = 10;
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            if (freq.contains(num))
                ++freq[num];
            else
                freq[num] = 1;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto el : freq)
            buckets[el.second].push_back(el.first);
        
        vector<int> top_k;
        top_k.reserve(k);

        int ix = buckets.size() - 1;
        while (ix > 0 and top_k.size() < k)
        {
            size_t jx = 0;
            while (jx < buckets[ix].size() and top_k.size() < k)
            {
                top_k.push_back(buckets[ix][jx]);
                ++jx;
            }
            --ix;
        }

        return top_k;
    }
};
