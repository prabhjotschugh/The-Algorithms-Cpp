#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> sieve_prime(int n)
{
    vector<bool> sieve(n + 1 ,false) ;

        sieve[0] = sieve[1] = true ;

        for(int i=2; i * i <= n ; i++)
        {
            if(!sieve[i])
            {
                for(long long j = (long long)i*i ; j <= n ; j += i)
                    sieve[j] = true ;
            }
        }

    vector<int> primes ;

    for(int i = 2 ; i <= n ; i++)
    {
        if(!sieve[i] ) primes.push_back(i) ;
    }

    return primes ;
}

int main() 
{
    vector<int> A = sieve_prime(10) ; // They are  4 primes till 10: {2, 3, 5, 7}
    vector<int> B = sieve_prime(20) ; // There are 8 primes till 20: {2, 3, 5, 7, 11, 13, 17, 19}

    for(auto it : A) cout << it << " " ;
    cout << endl ;

    for(auto it : B) cout << it << " " ;
    cout << endl ;

    return 0;
}