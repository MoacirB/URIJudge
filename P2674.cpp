#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bitset<10000010> prime;
//vector<int> primeList;
const int ub = 10000000;

void sieve()
{
    //primeList.reserve(ub);
    prime.set();
    prime[0] = prime[1] = 0;

    for(int I = 4; I<=ub; I+=2)
    {
        prime[I] = 0;
    }

    for(int I=3; I*I<=ub; I+=2)
    {
        if(prime[I])
        {
            for(int J = I*I; J<=ub; J+=I)prime[J] = 0;
        }
    }
}

string calc(int n)
{
    if(!prime[n])return "Nada";
    int dq = 1;
    while(n/dq>10)
    {
        dq*=10;
    }

    while(dq>=1)
    {
        if(!prime[n/dq])return "Primo";
        n%=dq;
        dq/=10;
    }
    return "Super";
}

void read()
{
    int n;
    while(cin>>n)
    {
        cout<<calc(n)<<endl;
    }
}

int main()
{
    sieve();
    read();
}
