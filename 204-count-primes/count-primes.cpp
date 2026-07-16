class Solution {
public:
    int countPrimes(int n) {
        if(n<3) {
            return 0;
        }
        vector<bool> isComposite(n, false);
        int count = 0;
        for (int i =2 ; i < n ; i ++) {
            if(!isComposite[i]) {
                count++;
                for(long j = (long)i * i ; j < n ; j+= i)
                isComposite[j] = true;
            }
        }
        return count;
        
    }
};