#include<iostream>
#include<queue>
#include<map>
using namespace std;

typedef pair<string, int> p;
typedef pair<int, string> pis;
typedef pair<int, pair<string, int> > pi;

const int inf = 10000000;

map< string, map< string, int > > graph;
map<string, bool> visited;
map<string, int> dist;

int Pontos, Ligacoes;

void read()
{
    cin>>Pontos>>Ligacoes;

    for(int I = 0; I<Ligacoes; I++)
    {
        string A, B;
        cin>>A>>B;

        if(!graph[A][B])
        {

            visited.insert( make_pair(A, false ) );
            visited.insert( make_pair(B, false) );

            dist.insert( make_pair(A, inf) );
            dist.insert( make_pair(B, inf) );

            graph[A][B] = 1;
            graph[B][A] = 1;
        }
    }
}



void djikstra(string src)
{
    priority_queue< pis, vector < pis >, greater < pis > > pq;

    pq.push( make_pair(0, src) );

    dist[src] = 0;

    map<string, int>::iterator it;

    while(!pq.empty())
    {
        int weight = pq.top().first;
        string k = pq.top().second;

        pq.pop();

        if(visited[k])continue;

        visited[k] = true;

        for(it = graph[k].begin(); it!= graph[k].end(); it++)
        {
            if(dist[it->first] > weight + 1)
            {
               dist[it->first] = weight + 1;
               pq.push( make_pair( dist[it->first], it->first));
            }
        }
    }
}

void print()
{
    cout<<dist["Entrada"]+dist["Saida"]<<endl;
}

int main()
{
    int dist_pontos = 0;
    read();
    djikstra("*");
    print();
}
