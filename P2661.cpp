#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long ll;

bitset<10000010> prime;
const ll ul = 10000000;
vector<ll> primeList;

void sieve()
{
    primeList.reserve(ul);
    prime.set();
    prime[0] = prime[1] = 0;
    primeList.push_back(2);

    for(ll I = 4; I<=ul; I+=2)
    {
        prime[I] = 0;
    }

    for(int I = 3; I*I<=ul; I+=2)
    {
        if(prime[I])primeList.push_back(I);
        for(ll J = I*I; J<=ul; J+=I)prime[J] = 0;
    }

    for(int I = sqrt(ul)+1; I<=ul; I++)
    {
        if(prime[I])primeList.push_back(I);
    }
}

bool isPrime(ll n)
{
    if(n<= ul)return prime[n];

    for(int I = 0; I<(int)primeList.size(); I++)
    {
        if(n%primeList[I]==0)return false;
    }
    return true;
}

int nDiv( ll n )
 {
     if(isPrime(n))return 1;
     int lp;
     int q = 0;
     int i = 0, p = primeList[i];

     while (p * p <= n)
     {
         while (n % p == 0)
         {
             n /= p;
             if(lp!=p)
             {
                 lp = p;
                 q++;
             }
         }

         p = primeList[++i];
     }
    if (n != 1)q++;
    return q; // f.size() = quantidade de fatores primos de n.
}


void desp(int ndiv)
{
    int q = pow(2, ndiv)-ndiv-1;
    cout<<q<<endl;
}

int main()
{
    sieve();

    ll N;
    cin>>N;
    int ndiv = nDiv(N);
    desp(ndiv);
}
