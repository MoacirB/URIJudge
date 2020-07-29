#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
const int ub = 600000, dist = 60000000;

bitset<10000010> prime;
//vector<int> primeList;

void sieve()
{
    //primeList.reserve(ub);
    prime.set();
    prime[0] = prime[1] = 0;
    //primeList.push_back(2);

    for(int I = 4;I<=ub;I+=2)
    {
        prime[I]=0;
    }
    for(int I=3;I*I<=ub; I+=2)
    {
        if(prime[I])
        {
            for(int J = I*I; J<=ub;J+=I)
            {
                prime[J]=0;
            }
        }
    }
}

void calc(int peso)
{
    int vel=0, horas, dias;
    int Q=0;

    while(Q<10)
    {
        if(prime[peso])
        {
            vel+=peso;
            Q++;
        }
        peso++;
    }
    int h = dist/vel;
    int d = h/24;
    cout<<vel<<" km/h"<<endl<<h<<" h / "<<d<<" d"<<endl;
}

void read()
{
    int Peso;
    cin>>Peso;
    calc(Peso);
}

int main()
{
    sieve();
    read();
}

