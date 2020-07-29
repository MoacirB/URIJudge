#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
vector<ll> sDiv;
vector<ll> DN;

void sd()
{
    sDiv.resize(1000001, 0);
    DN.resize(1000001, 0);

    for(int I = 1; I<=1000000; I++)
    {
        for(int J = I; J<=1000000; J+=I)
        {
            sDiv[J]+=I;
        }
        DN[I]+=sDiv[I]+DN[I-1];
    }
}

int main()
{
    sd();
    int N;
    cin>>N;
    while(N!=0)
    {
        cout<<DN[N]<<endl;
        cin>>N;
    }


}
