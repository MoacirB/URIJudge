#include<iostream>
#include<vector>

using namespace std;

const int inf = 100;
vector < vector<int> > graph;

int N, M, P;

void readGraph(){
    cin >> N >> M >> P;

    graph.resize(N, vector<int>(N, inf));
    int A, B;

    for(int I = 0; I<M; I++){
        cin >> A >> B;

        graph[A-1][B-1] = 1;
        graph[B-1][A-1] = 1;
    }
}



void FW(){
    for(int K=0; K<N; K++){
        graph[K][K] = 0;

        for(int I=0; I<N; I++){
            for(int J=0; J<N; J++){
                if(I == J)continue;
                if(graph[I][J]>graph[I][K]+graph[K][J]){
                    graph[I][J] = graph[I][K]+graph[K][J];
                }
            }
        }
    }
}

int main(){
    readGraph();
    FW();
    while(P--){
        int K, L;
        cin>> K >> L;
        if(graph[K-1][L-1]<100)cout<<"Lets que lets"<<endl;
        else cout<<"Deu ruim"<<endl;
    }

    return 0;
}




/*bool bfs(int element, int find){
    vector <int> visited;
    visited.resize(N, 0);
    visited[element] = 1;
    queue<int> q;
    if(element == find)return true;

    q.push(element);

    while(!q.empty()){
        int e = q.front();
        q.pop();
        list<int>::iterator it;
        for(it = graph[e-1].begin(); it != graph[e-1].end(); it++){
            if(*it == find)return true;
            if(visited[*it-1] == 0){
                visited[*it-1] = 1;
                q.push(*it);
            }
        }
    }
    return false;
}*/
