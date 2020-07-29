#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;
typedef long long ll;

bitset<10000010> prime;
vector<ll> primeList;
ll n;
const ll ub =  10000000;

void sieve(ll n)
{
    primeList.reserve(ub);
    prime.set();
    prime[0] = prime[1] = 0;
    primeList.push_back(2);
    for(ll I = 4; I<=n;I+=2)
    {
        prime[I] = 0;
    }

    for(ll I = 3; I*I<=n; I+=2)
    {
        if(prime[I])
        {
            primeList.push_back(I);
            for(ll J = I*I; J<=n; J+=I)prime[J] = 0;
        }
    }
}
bool isPrime(ll n)
{
    if(n<= ub)return prime[n];

    for(int I = 0; I<(int)primeList.size(); I++)
    {
        if(n%primeList[I]==0)return false;
    }
    return true;
}

int main()
{
    sieve(ub);
    int q;
    cin>>q;
    while(q--)
    {
        cin>>n;
        if(isPrime(n))cout<<"Prime"<<endl;
        else cout<<"Not Prime"<<endl;
    }

}
