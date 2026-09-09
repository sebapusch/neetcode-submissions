class Solution {
public:
    bool isPalindrome(string s) 
    {
        int ix = 0;
        int jx = s.size() - 1;

        while (ix <= jx)
        {
            while(s[ix] == ' ' or not isalnum(s[ix]))
                ++ix;
            
            while(s[jx] == ' ' or not isalnum(s[jx]))
                --jx;

            if (ix > jx)
                return true;
            
            if (tolower(s[ix]) != tolower(s[jx]))
                return false;
            
            ++ix;
            --jx;
        }

        return true;
    }
};
