#include <ranges>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (string const &str: strs)
        {
            string chars(str.begin(), str.end());
            sort(chars.begin(), chars.end());

            if (anagrams.contains(chars))
                anagrams[chars].push_back(str);
            else
                anagrams[chars] = vector<string>{str};
        }

        return anagrams 
            | views::values 
            | ranges::to<std::vector>(); 
    }
};
