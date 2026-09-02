#include <string>
#include <sstream>

class Solution {
public:

    string encode(vector<string>& strs) 
    {
        //if (strs.size() == 0)
        //    return "";

        string encoded;
        
        for_each(strs.begin(), strs.end(), [&encoded](auto const &str) {
            encoded += str + '~';
        });

        return encoded;
    }

    vector<string> decode(string s) 
    {
        stringstream stream(s);
        vector<string> msg;
        string buffer;
        while (std::getline(stream, buffer, '~'))
            msg.push_back(buffer);

        return msg;
    }
};
