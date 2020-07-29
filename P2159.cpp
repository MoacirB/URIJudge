#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;
    double P, M;
    P = (double)n/(log(n));
    M = 1.25506*P;
    cout<<fixed<<setprecision(1);
    cout<<P<<' '<<M<<endl;
}
