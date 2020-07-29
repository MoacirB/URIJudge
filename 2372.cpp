#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> > graph;
int inf = 10000000;
int N, M;

void read()
{
    cin>> N >> M;
    graph.resize(N, vector<int>(N, inf));

    for(int I = 0; I<M; I++)
    {
        int U, V, W;
        cin>> U >> V >> W;

        if(graph[U][V]>W)
        {
            graph[U][V] = W;
            graph[V][U] = W;
        }

    }
}

void FW()
{
    for(int K=0; K<N; K++)
    {
        graph[K][K] = 0;

        for(int I=0; I<N; I++)
        {
            for(int J=0; J<N; J++)
            {
                if(I==J)continue;
                if(graph[I][J]>graph[I][K]+graph[K][J])
                {
                    graph[I][J] = graph[I][K]+graph[K][J];
                }
            }
        }
    }
}

void search()
{
    int min_max=inf, max_line;
    for(int I=0; I<N; I++)
    {
        max_line=0;
        for(int J=0; J<N; J++)
        {
            if(graph[I][J]>min_max){max_line = inf;break;}
            if(graph[I][J]>max_line)max_line=graph[I][J];
        }
        if(max_line<min_max)min_max = max_line;
    }
    cout<<min_max<<endl;
}

void imprime()
{
    for(int I=0; I<N; I++)
    {
        for(int J=0, max_line=0; J<N; J++)
        {
            cout<<graph[I][J]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    read();
    FW();
    //imprime();
    search();
}
