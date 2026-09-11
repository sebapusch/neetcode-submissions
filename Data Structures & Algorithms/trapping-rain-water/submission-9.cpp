#include <algorithm>

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int water = 0;

        int l = 0;
        int r = height.size() - 1;

        int max_l = height[l];
        int max_r = height[r];

        while(l < r)
        {
            if (max_l < max_r)
            {
                max_l = max(max_l, height[++l]);
                water += max(0, max_l - height[l]);  
            }
            else
            {
                max_r = max(max_r, height[--r]); 
                water += max(0, max_r - height[r]);
            }
        }

        return water;
    }
};
