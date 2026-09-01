class Solution {
public:
    int maxArea(vector<int>& height) {

        auto lower = 0;
        auto upper = height.size() -1;

        auto max_water_area = 0;

        while (lower < upper) {
            auto min_height = std::min(height[lower], height[upper]);
            auto water_area = min_height * (upper - lower);

            if (max_water_area < water_area) {
                max_water_area = water_area;
            }

            if (height[lower] < height[upper]) {
                lower++;
            } else {
                upper--;
            }

        }

        return max_water_area;
    }
};