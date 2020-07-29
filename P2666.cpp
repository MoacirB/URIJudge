#include<iostream>
#include<list>
#include<vector>
#include<cmath>

using namespace std;

vector < list< pair< int, int > > > graph;
vector < int > parent;
vector < int > gold;
int C, viagens, distancia = 0;

void read()
{
    int N;
    cin>>N>>C;
    parent.resize(N, -1);
    gold.resize(N);
    graph.resize(N);

    for(int I=0; I<N; I++)
    {
        cin>>gold[I];
    }

    int A,B,W;
    for(int I = 0; I<N-1; I++)
    {
        cin>>A>>B>>W;
        graph[A-1].push_back( make_pair( W, B-1 ) );
        graph[B-1].push_back( make_pair( W, A-1 ) );
    }
}

void dfs(int v)
{
    list< pair< int, int > >::iterator i;
    for(i = graph[v].begin(); i != graph[v].end(); i++)
    {
        if(parent[i->second] == -1)
        {
            parent[i->second] = v;
            dfs(i->second);
            viagens = ceil((float)gold[i->second]/(float)C);
            gold[v]+=gold[i->second];
            distancia += (i->first*viagens*2);
        }
    }
}

int main()
{
    read();
    parent[0] = 0;
    dfs(0);
    cout<<distancia<<endl;
    return 0;
}
