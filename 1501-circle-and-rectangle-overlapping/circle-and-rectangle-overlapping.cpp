class Solution {
public:
    bool checkOverlap(int radius, int xC, int yC, int x1, int y1, int x2, int y2) {
        int xi;
        int yi;

        if (xC < x1) {
            xi = x1;
        } else if (xC > x2) {
            xi = x2;
        } else {
            xi = xC;
        }

        if (yC < y1) {
            yi = y1;
        } else if (yC > y2) {
            yi = y2;
        } else {
            yi = yC;
        }

        int dx = xi - xC;
        int dy = yi - yC;

        return dx * dx + dy * dy <= radius * radius;
    }
};