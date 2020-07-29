#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
using namespace std;

bitset<10000010> prime;
const int ub = 10000000;
vector<int> primeList;
vector<int> C;
int L;

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

int gcd(int a, int b)
{
    if(b==0)return a;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return a*(b/gcd(a, b));
}

vector <int> primeFactors( int n )
{
     vector <int> f;
     int i = 0, p = primeList[i];

     while (p * p <= n) {
         while (n % p == 0) {
             n /= p;
             f.push_back( p );
         }

         p = primeList[++i];
     }

     if (n != 1) f.push_back( n );

     return f;
}

int calc()
{
    vector<int>::iterator i;

    i=C.begin();
    int lcmC = lcm(*i, *(i+1));
    while(i!=( C.end()-1 ) )
    {
        lcmC = lcm(lcmC, *(i+1));
        i++;
    }
    int X = (L-(L%lcmC))/lcmC;

    vector<int> FP = primeFactors(lcmC);
    int value = X;

    for(i = FP.begin(); i!=FP.end(); i++)
    {
        if(X%*i==0)value*=(*i);
    }
    return value;
}

void read()
{
    int N, v;
    cin>>N>>L;


    C.reserve(N);
    for(int I = 0; I<N; I++)
    {
        cin>>v;
        C.push_back(v);
    }
    cout<<calc()<<endl;
}


int main()
{
    sieve();
    read();
}
