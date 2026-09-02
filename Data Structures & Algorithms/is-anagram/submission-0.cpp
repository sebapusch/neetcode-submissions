class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> vec_s(s.begin(), s.end()); 
        vector<char> vec_t(t.begin(), t.end());

        sort(vec_s.begin(), vec_s.end());
        sort(vec_t.begin(), vec_t.end());

        return vec_s == vec_t;
    }
};
