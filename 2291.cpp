#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int ub = 10000000;
bitset<10000010> prime;
vector<int> primeList;
vector<int> perfects;

void sieve()
{
    primeList.reserve(ub);
    prime.set();
    primeList.push_back(2);
    prime[0] = prime[1] = 0;

    for(int I = 4; I<=ub; I+=2)
    {
        prime[I] = 0;
    }

    for(int I = 3; I*I<=ub; I+=2)
    {
        if(prime[I])
        {
            primeList.push_back(I);
            for(int J = I*I; J<=ub; J+=I)
            {
                prime[J] = 0;
            }
        }
    }

    int I = ( ((int)sqrt(ub)+1)%2!=0 ) ?  ((int)sqrt(ub)+1) :  ((int)sqrt(ub)+2);
    for(int I = sqrt(ub)+1; I<=ub; I+=2)
    {
        if(prime[I])primeList.push_back(I);
    }
}

int sumDiv( ll n )
{
     ll i = 0, p = primeList[i], ans = 1;

     while (p * p <= n)
    {
        int e = 0;
        while (n % p == 0)
        {
             n /= p;
             e++;
        }
        ans *= (pow( (double) p, e + 1.0 ) - 1) / (p - 1);
        p = primeList[++i];
     }
     if (n != 1)
     {
        int v = ( (n*n)-1 ) / (n - 1);
        ans *= v;
     }
     return ans;
}

void calc()
{
    perfects.reserve(1000001);
    perfects[0] = 0;
    for(int I = 1; I<1000000; I++)
    {
        perfects[I]+=(perfects[I-1]+sumDiv(I));
    }
}

int main()
{
    sieve();
    calc();

    int N;
    cin>>N;
    while(N!=0)
    {
        cout<<perfects[N]<<endl;
        cin>>N;
    }

}
