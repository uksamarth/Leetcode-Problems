class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j = height.size()-1;
        int maxarea = 0;
        while(i<j){
            int currArea = min(height[i],height[j])*(j-i);
            maxarea = max(maxarea,currArea);

            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxarea;
    }
};