class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int l = flowerbed.size();

        if(n == 0)
            return true;

        for(int i = 0; i < l; i++) {

            bool leftkhali = (i == 0) || (flowerbed[i-1] == 0);
            bool rightkhali = (i == l-1) || (flowerbed[i+1] == 0);

            if(flowerbed[i] == 0 && leftkhali && rightkhali) {
                flowerbed[i] = 1;
                n--;

                if(n == 0)
                    return true;
            }
        }

        return false;
    }
};