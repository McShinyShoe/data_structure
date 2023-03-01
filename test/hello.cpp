#include <iostream>

int isPrime(int num)
{
    for (int i = 2; i < num; i++)
        if(num % i == 0) return false;
    return true;
};

int nPrime(int n)
{
    int r = 2;
    while(n)
        if(isPrime(r++)) n--;
    return r - 1;
}

int main()
{
    std::cout << "Primes:" << std::endl;
    for(int i = 1; i <= 10; i++)
        std::cout << nPrime(i) << std::endl;
    return 0;
}