#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include <algorithm>    // std::sort

using namespace std;

vector < list<char> > graph;
vector <int> visited;
vector < vector<char> > conex;
int V, E, C, ct = 1;

void read(){
    cin >> V >> E;

    graph.clear();
    visited.clear();
    conex.clear();

    conex.resize(V);
    graph.resize(V);
    visited.resize(V, -1);

    for(int I = 0; I<E; I++){
        char to, from;
        cin >> to >> from;

        graph[to-'a'].push_back(from);
        graph[from-'a'].push_back(to);
    }
}

void BFS(){
    queue <char> q;
    C = -1;

    for(int I = 0; I<V; I++){
        if(visited[I] == -1){

            q.push((char)I+'a');
            visited[I] = 0;
            C++;
            conex.resize(C+1);

            while(!q.empty()){
                int v = q.front()-'a';
                conex[C].push_back(q.front());

                q.pop();
                list < char >:: iterator it;
                for(it = graph[v].begin(); it != graph[v].end(); it++){
                    if(visited[*it-'a'] == -1){
                        q.push(*it);
                        visited[*it-'a'] = 0;
                    }
                }
            }
        }
    }
}

void imprime()
{
    vector< vector<char> >::iterator itConex;
    vector<char>::iterator itList;
    int I = 0;
    cout<<"Case #"<<ct<<":"<<endl;
    for(itConex = conex.begin(); itConex !=conex.end(); itConex++, I++)
    {
        sort(conex[I].begin(), conex[I].end());
        for(itList = conex[I].begin(); itList !=conex[I].end(); itList++)
        {
            cout<<*itList<<",";
        }
        cout<<endl;
    }
    cout<<I<<" connected components"<<endl;
    cout<<endl;
    ct++;
}

int main(){
    int N;
    cin>>N;

    for(int I = 0; I<N; I++){
        read();
        BFS();
        imprime();
    }
}
