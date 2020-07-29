#include<iostream>
#include<vector>

using namespace std;

const int INF = 0x3f3f3f3f;

vector< vector<int> > graph;

int N, M;

void read(){
    cin >> N >> M;
    graph.resize(N, vector<int>(N, INF));

    for(int I = 0; I< M; I++){
        int U, V, W;
        cin >> U >> V >> W;

        graph[U][V] = W;
        graph[V][U] = W;
    }
}

void FW(){
    for(int K = 0; K<N; K++){
        graph[K][K] = 0;

        for(int I = 0; I<N; I++){
            for(int J = 0; J<N; J++){
                if(I == J)continue;

                if(graph[I][J] > graph[I][K]+graph[K][J])graph[I][J] = graph[I][K]+graph[K][J];
            }
        }
    }
}

busca(){
    int maior = 0;

    for(int I = 0; I<N; I++){
        for(int J = 0; J<N; J++){
            if(graph[I][J]> maior)maior = graph[I][J];
        }
    }
    cout<<maior;
}

imprime(){
    for(int I = 0; I<N; I++){
        for(int J = 0; J<N; J++){
            cout<<graph[I][J]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    read();
    FW();
    imprime();
    busca();
    return 0;
}
