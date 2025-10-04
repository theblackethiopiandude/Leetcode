class Solution {
public:
        int maxArea(vector<int>& height) {
        int area = 0;
        {        
            int L = 0, R = height.size() - 1; 
            while(L < R){
                area = max(area, ((R-L) * min(height[L], height[R])));
                if(height[L] < height[R])
                    L++;
                else 
                    R--;
            }
        }
        return area;
    }
};
