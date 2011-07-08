#include <cstdlib>
#include <cstdio>
#include <cmath>

long getFib(int n);

/*
    Problem no. 2:
    By considering the terms in the Fibonacci sequence whose 
    values do not exceed four million, find the sum of the 
    even-valued terms.
    
    This program instead calculates the sum of all even 
    fibonacci numbers up until a given term number.    
    (in polynomial time)    

    "Common knowledge":
    fib(33) < 4 million < fib(34)
    
    now for the trick:

    A proof that for an n s.t n%3==0,
    the sum of all even valued fibonacci terms up to n equals to
    half the sum of all fibonacci terms up to n:
    
    * Fibonacci with seeds: F(1) = 1, F(2) = 1 (or F(0) = 0, F(1) = 1)
    
    1. First we notice that, n is divisible by 3 iff F(n) is even.        
    2. Then we get, the series of 2*F(3i), when i range from 1 to some k,
       = F(3i) + F(3i) = F(3i) + F(3i - 1) + F(3i - 2) = F(i) when i range from
       1 to 3k.
    3. From here it's easy to see that the series of F(i)/2, when i range from 1 to
       3n, equals F(3i), when i range from 1 to n.   
    
    Using the fact that the sum of F(i), when i range from 1 to n, is
    F(n+2) - 1, and using fibonacci's closed form expression, we can calculate
    the problem in polynomial time.
*/
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage <exe> <positive integer>\n");
        return 1;
    }

    long n_arg = atol(argv[1]);
    if (n_arg <= 0) {
        printf("argument should be an integer > 0\n");
        return 1;
    }     
    
    // lower n to the nearest multiple of 3.
    long n = (n_arg/3)*3;   

    long sum_fibs_up_to_limit = getFib(n + 2) - 1;        

    printf("sum of all even fibs up to that limit is: %ld\n", sum_fibs_up_to_limit/2);        
    
    return 0;
}

long getFib(int n) {
    static double sq5 = sqrt(5.0);
    static double phi = (1 + sq5) / 2.0, xi = (1 - sq5)/2.0;

    return static_cast<long>(floor((pow(phi, n) - pow(xi, n))/sq5));
}
