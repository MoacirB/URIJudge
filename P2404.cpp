#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
vector<ppi> edges;
vector<ppi> mst;

int N, M;



/*Union Find*/
vector<int> parent;
vector<int> weight;

void UF_read(int n){
    parent.resize(n);
    weight.resize(n, 0);

    for(int I = 0; I<n; I++){
        parent[I] = I;
    }
}

int UF_find(int e){
    if(parent[e] != e)parent[e] = UF_find(parent[e]);
    return parent[e];
}

void UF_merge(int a, int b){
    a = UF_find(a);
    b = UF_find(b);

    if(weight[a] > weight[b]){
        parent[b] = a;
    }
    else{
        parent[a] = b;
    }

    if(weight[a] == weight[b]){
        weight[b]++;

    }
}
/*Fim Union Find*/


void read(){
    cin >>N >> M;
    edges.reserve(M);
    mst.reserve(N-1);

    int from, to, weight;
    for(int I = 0; I<M; I++){
        cin>> from >> to >> weight;
        edges.push_back( make_pair(weight, make_pair(from-1, to-1 ) ) );
    }
}

void imprime(){
    vector < ppi >::iterator it;
    for (it = mst.begin(); it != mst.end(); it++){
        int w = it->first;
        int u = it->second.first;
        int v = it->second.second;

        cout << u << " - " << v << " : " << w << endl;
    }
}

void print(){
    for(int I = 0; I<N; I++){
        cout<<I<<": "<<parent[I]<<endl;
    }
}

void kruskal(){
    int C = 1, dist=0;
    sort(edges.begin(), edges.end());
    UF_read(N);
    vector<ppi>::iterator itEdge;

    for(itEdge = edges.begin(); C<N; itEdge++){

        int from = itEdge->second.first;
        int to = itEdge->second.second;
        if( UF_find(from) != UF_find(to) ){
            mst.push_back( make_pair( itEdge->first,  make_pair(from, to) ) );
            UF_merge(from, to);
            C++;
            dist+=itEdge->first;
        }
    }
    cout<<dist<<endl;
}



int main(){
    read();
    kruskal();
}

