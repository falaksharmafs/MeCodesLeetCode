class Solution {
public:
    int fib(int n) {
        if (n <= 1) // base case is always the lowest possible value of param
         return n;

        return(fib(n-1)+fib(n-2)); 

        
    }
};