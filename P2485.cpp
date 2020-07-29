#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

typedef pair<int, int> pi;
const int inf = 100000;
vector< vector<int> > field;
vector< list<int> > edges;
vector<int> dist;
vector<int>parent;
vector<int> visited;
int A, B, V;

void read()
{
    V = 0;
    cin>> A>> B;
    field.clear();
    field.resize(A, vector<int>(B));
    for(int I = 0; I<A; I++)
    {
        for(int J = 0; J<B; J++)
        {
            cin >> field[I][J];
            if(field[I][J] != 0)field[I][J] = ++V;
        }
    }
    dist.clear();
    visited.clear();
    parent.clear();
    dist.resize(V, inf);
    parent.resize(V);
    visited.resize(V, -1);
}

void searchConnections(int I, int J)
{
    for(int i=I-1; i<I+2; i++)
    {
        for(int j=J-1; j<J+2; j++)
        {
            if(i==I&&j==J)continue;
            if(i<0||i>=A||j<0||j>=B)continue;
            if(field[i][j] != 0)
            {
                edges[field[I][J]-1].push_back(field[i][j]-1);
            }
        }
    }
}

void cv()
{
    edges.clear();
    edges.resize(V);
    for(int I = 0; I<A; I++)
    {
        for(int J = 0; J<B; J++)
        {
            if(field[I][J] != 0)searchConnections(I, J);
        }
    }
}

void djikstra(int src){
    priority_queue< pi, vector<pi>, greater<pi> > pq;

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()){
        int weight = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if(visited[v] != -1)continue;

        visited[v] = 0;
        list<int>::iterator it;
        for(it = edges[v].begin(); it != edges[v].end(); it++){
                if(dist[*it] > 1 + weight){
                    parent[*it] = v+1;
                    dist[*it] = 1 + weight;
                    pq.push(make_pair(dist[*it], *it));
                }
        }
    }
}


void printDist()
{
    int max_dist = 0;
    for(int I=0; I<V; I++)
    {
        if(dist[I]>max_dist)max_dist=dist[I];
    }
    cout<<max_dist<<endl;
}

int main()
{
    int cases;
    cin>>cases;
    int X,Y;
    while(cases--)
    {
        read();
        cv();
        cin>>X>>Y;
        djikstra(field[X-1][Y-1]-1);
        printDist();
    }

}
