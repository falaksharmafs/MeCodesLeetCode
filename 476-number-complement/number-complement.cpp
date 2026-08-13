class Solution {
public:
    int findComplement(int num) {
        int m = 0;
        int temp = num;

        while(temp>0){
            m = (m<<1)|1;
            temp >>=1;
        }
        return m^num;

    }
};