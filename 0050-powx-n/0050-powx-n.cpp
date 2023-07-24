class Solution {
public:
    double myPow(double x, int n)
    {
        // pow(4,5)=pow(4,2)*pow(4,2)*pow(4,1)
        // pow(4,2)=pow(4,1)*pow(4,1)
        // pow(4,1)=4
        
        // if n is negative then 1/x
        // pow(4,-5)=pow(4,-2)*pow(4,-2)*pow(4,-1)
        // pow(4,-2)=pow(4,-1)*pow(4,-1)
        // pow(4,-1)=1/4

        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;
        double temp = myPow(x, n / 2);
        if (n % 2 == 0) // even (positive or negative)
            return temp * temp;
        if (n > 0) // positive odd
            return x * temp * temp;
        return (temp * temp) / x; // negative odd
    }
};