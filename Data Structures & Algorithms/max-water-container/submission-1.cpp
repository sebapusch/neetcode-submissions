class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int ix = 0;
        int jx = heights.size() - 1;

        int max_vol = 0;

        while (ix < jx)
        {
            int vol = (jx - ix) * min(heights[jx], heights[ix]);

            if (vol > max_vol)
                max_vol = vol;

            if (heights[ix] > heights[jx])
                --jx;
            else
                ++ix;
        }

        return max_vol;
    }
};
