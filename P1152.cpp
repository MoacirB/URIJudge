#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int>p;
typedef pair<int, p> pp;

vector< pp> edges;
int m, n, total, min_value;

/*Union Find*/
vector<int> weight;
vector<int> parent;

void start()
{
    parent.clear();
    weight.clear();

    parent.resize(n);
    weight.resize(n, 0);

    for(int I = 0; I<n; I++)
    {
        parent[I] = I;
    }
}

int find(int e)
{
    if(parent[e]!= e)parent[e] = find(parent[e]);
    return parent[e];
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if(weight[a]>weight[b])
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }

    if(weight[a] == weight[b])weight[b]++;
}

/*Fim Union Find*/

void read()
{
    total = 0;
    start();
    edges.clear();
    edges.reserve(n);

    for(int I = 0; I<m; I++)
    {
        int  x, y, z;
        cin>> x >> y >> z;
        total+=z;
        edges.push_back( make_pair( z, make_pair( x, y ) ) );
    }
}


void kruskal()
{
    min_value = 0;
    int C = 1;
    sort(edges.begin(), edges.end());

    vector<pp>::iterator it;
    for(it = edges.begin(); C<n; it++)
    {
        int x = it->second.first;
        int y = it->second.second;
        int z = it->first;

        if(find(x) != find(y))
        {
            min_value+=z;
            merge(x, y);
            C++;
        }
    }

    cout<<total-min_value<<endl;
}

void print(){
    for(int I = 0; I<n; I++){
        cout<<I<<": "<<parent[I]<<endl;
    }
}

int main()
{
    cin>>n>>m;
    while(n!=0&&m!=0)
    {
        read();
        kruskal();
        cin>>n>>m;
    }

}
