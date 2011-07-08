#include <cstdio>
#include <cstdlib>


/*
    Problem no. 1:
    If we list all the natural numbers below 10 that are multiples 
    of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

    Find the sum of all the multiples of 3 or 5 below 1000.
    
    This program sums the multiples of 3 and 5 up until the given number.
*/
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: <exe> <target number>\n");
        return 1;
    }

    int target = atoi(argv[1]);
    printf("first try:\n");
    int d5 = (target%5 == 0)?target/5 - 1:target/5;
    int d3 = (target%3 == 0)?target/3 - 1:target/3;
    int d15 = (target%15 == 0)?target/15 - 1:target/15;

    int sum = d5*(d5+1)*5/2 + d3*(d3 + 1)*3/2 - d15*(d15+1)*15/2;

    printf("the of all the multiples of 3 and 5 up to %d is: %d\n", target, sum); 
    
    return 0;
}
