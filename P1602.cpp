#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

bitset<10000010> prime;
const int ub = 2000001;
vector<int> divs;
vector<int> divP;

void recieve()
{
    divs.resize(ub,0);
    divP.resize(ub, 0);
    prime.set();
    divs[0] = 0;
    divs[1] = 1;
    for(int I = 2; (I*2)<=ub; I++)
    {
        if(prime[I])
        {
            divs[I] = 2;
            for(int J = I+I; J<=ub; J+=I)
            {
                prime[J] = 0;
                int d = 0, t = J;
                while(t%I == 0)
                {
                    t/=I;
                    d++;
                }
                if(divs[J]==0)divs[J]+=d+1;
                else divs[J]*= (d+1);
            }
        }
    }
    divP[2] = 1;
    for(int I = 3;I<ub; I++)
    {
        divP[I] = divP[I-1];
        if(prime[ divs[I] ])divP[I]++;
    }
}

void read()
{
    int N;
    while(cin>>N)
    {
        cout<<divP[N]<<endl;
    }
}

int main()
{
    recieve();
    read();
}
