#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, int> p;
const int inf = 100000;
vector< list<p> > graph;
vector<int> parent;
vector<bool> visited;
vector<int> dist;

int C, E, D;
void read()
{
    graph.clear();
    parent.clear();
    visited.clear();
    dist.clear();

    graph.resize(C);
    parent.resize(C, -1);
    visited.resize(C, false);
    dist.resize(C, inf);

    int C1, C2, T;
    for(int I = 0; I<E; I++)
    {
        cin>>C1>>C2>>T;

        graph[C1-1].push_back(make_pair(T, C2-1));
        graph[C2-1].push_back(make_pair(T, C1-1));
    }

    cin>>D;
}

void djikstra(int d)
{
    priority_queue<p, vector<p>, greater<p> > pq;

    pq.push(make_pair(0, d));
    dist[d] = 0;
    parent[d] = d;

    while(!pq.empty())
    {
        int v = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if(visited[v])continue;

        visited[v] = true;

        list<p>::iterator it;
        for(it = graph[v].begin(); it!=graph[v].end(); it++)
        {
            int weight = it->first;
            int value = it->second;

            if(dist[value]> weight + w)
            {
                dist[value] = weight + w;
                parent[value] = v;
                pq.push(make_pair(dist[value], value));
            }
        }
    }
}

void printWay(){
    vector<int> a;
    a.reserve(C);
    int ip = parent[0];
    a.push_back(0);
    while(ip!=D-1)
    {
        a.push_back(ip);
        ip = parent[ip];
    }
    a.push_back(D-1);

    vector<int>::iterator i;
    vector<int>::reverse_iterator it;

    for(it = a.rbegin(); it!=a.rend(); it++)
    {
        cout<<" "<<*it+1;
    }
    cout<<endl;
}

void print()
{
    if(dist[0]<120)cout<<"Will not be late. ";
    else cout<<"It will be "<<dist[0]-120<<" minutes late. ";

    cout<<"Travel time - "<<dist[0]<<" - best way -";
    printWay();

}

int main()
{
    cin>>C>>E;

    while(C!=0&&E!=0)
    {
        read();
        djikstra(D-1);
        print();
        cin>>C>>E;
    }
}
