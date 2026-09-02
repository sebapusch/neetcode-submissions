#include <ranges>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> anagrams;

        for (string const &str: strs)
        {
            vector<int> hash(26, 0);
            for (int ch : str)
                ++hash[ch - 'a'];

            if (anagrams.contains(hash))
                anagrams[hash].push_back(str);
            else
                anagrams[hash] = vector<string>{str};
        }

        return anagrams 
            | views::values 
            | ranges::to<std::vector>(); 
    }
};
