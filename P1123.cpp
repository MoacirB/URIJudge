#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<iomanip>
using namespace std;

typedef pair<int, int> p;


const int inf = 0x3f3f3f3f;
vector< list<p> > graph;
vector<int> visited;
vector<int> dist;
vector<int> parent;

int N, M, C, K;

void read()
{

    visited.clear();
    dist.clear();
    graph.clear();
    parent.clear();

    visited.resize(N, 0);
    dist.resize(N, inf);
    graph.resize(N);
    parent.resize(N, -1);

    int U, V, P;
    for(int I = 0; I<M; I++)
    {
        cin>> U >> V >> P;
        graph[U].push_back( make_pair(P, V) );
        graph[V].push_back( make_pair(P, U) );
    }
}

void dijkstra(int k)
{
    priority_queue< p, vector<p>, greater<p> > pq;
    pq.push( make_pair(0, k) );
    dist[k] = 0;

    list<p>::iterator it;
    while(!pq.empty())
    {
        int weight = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(visited[v]!=0)continue;
        visited[v] = 1;


        for(it = graph[v].begin(); it != graph[v].end(); it++)
        {
            int vt = it->second;
            int w = it->first;

            if(v<C-1&&vt!=v+1)continue;
            if(dist[vt] > weight+w )
            {
                parent[vt] = v;
                dist[vt] = weight+w;
                pq.push( make_pair(dist[vt], vt) );
            }
        }
    }
}

void imprime_dist()
{
    vector<int>::iterator it;
    for(it = dist.begin(); it != dist.end(); it++)
    {
        cout<<*it<<endl;
    }
}

int main()
{
    cin>>N>>M>>C>>K;
    while(N!=0 && M!=0 && C!=0 && K!=0)
    {
        read();
        dijkstra(K);
        cout<<dist[C-1]<<endl;
        cin>>N>>M>>C>>K;
    }
}
