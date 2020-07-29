#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

typedef pair<int, int> p;
vector < list < p > > graph;
vector< int > dist;

int N, E, S, M;
void read()
{
    cin>>N>>E>>S>>M;
    graph.resize(N);
    dist.resize(N, -1);

    int A, B, T;
    for(int I = 0; I<M; I++)
    {
        cin>>A>>B>>T;

        graph[A].push_back( make_pair( T, B ) );
    }
}

void djikstra(int e)
{
    priority_queue< int, vector<int>, greater<int> > pq;
    int minute = -1;

    pq.push( e );

    list<p>::iterator i;
    while(!pq.empty())
    {
        int v = pq.top();
        pq.pop();
        minute++;
        list<p>::iterator i;
        for(i = graph[v].begin(); i!=graph[v].end(); i++)
        {
            if(minute>1000)
            {
                break;
            }
            if( (i->first == 0 && minute%3 != 0) || (i->first == 1 && minute%3 == 0))
            {
                dist[i->second] = minute;
                if(i->second == S)break;
                pq.push(  i->second );
            }
        }
    }
    if(dist[S] == -1)cout<<'*'<<endl;
    else cout<<dist[S]+1<<endl;
}

int main()
{
    read();
    djikstra(E);
}
