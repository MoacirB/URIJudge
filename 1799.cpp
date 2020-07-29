#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<map>
using namespace std;

typedef pair<string, int> p;

map< string, map< string, int > > graph;
vector<int> visited;
vector<int> dist;

int Pontos, Ligacoes;

void read()
{
    cin>>Pontos>>Ligacoes;
    visited.resize(Pontos, -1);
    dist.resize(Pontos);

    int C = 0;
    for(int I = 0; I<Ligacoes; I++)
    {
        string A, B;
        cin>>A>>B;
        if(!graph[A][B])
        {
            graph[A].insert(make_pair(B, C));
            graph[B].insert(make_pair(A, C+1));
            C+=2;
        }

    }
}
