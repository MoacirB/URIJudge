#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

map<string, int> pessoas;
vector<int> parent;
vector<int>weight;
int N, M;



int find(int e)
{
    if(parent[e] != e)parent[e] = find(parent[e]);
    return parent[e];
}

int merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if(weight[a] > weight[b])
    {
        parent[a] = b;
    }
    else
    {
        parent[b] = a;
    }

    if(weight[a] == weight[b])
    {
        weight[b]++;
    }
}

void init()
{
    cin>>M>>N;

    parent.resize(M);
    weight.resize(M, 0);

    for(int I = 0; I<M; I++)
    {
        parent[I] = I;
    }
}

void read()
{
    int C = 0;
    for(int I=0; I<N; I++)
    {
        string p1, r, p2;
        cin>>p1>>r>>p2;

        pair<map<string,int>::iterator,bool> ret;

          ret = pessoas.insert( make_pair(p1, C) );
          if (ret.second) {
            C++;
          }

        ret = pessoas.insert( make_pair(p2, C) );
        if (ret.second) {
            C++;
        }
        map<string, int>::iterator it1, it2;
        it1 = pessoas.find(p1);
        it2 = pessoas.find(p2);

        int v1 = it1->second, v2 = it2->second;

        merge(v1, v2);
    }
}

void search()
{
    int C = 0;
    for(int I = 0; I<M; I++)
    {
        if(I==parent[I])C++;
    }
    cout<<C<<endl;
}
int main()
{
    init();
    read();
    search();
}
