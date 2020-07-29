#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;
vector<pp> edges;


int N, A;

/*Union Find*/
vector<int> parent;
vector<int> weight;

vector<int> parent_reverse;
vector<int> weight_reverse;

void start()
{
    parent.resize(A, -1);
    weight.resize(A, 0);

    parent_reverse.resize(A, -1);
    weight_reverse.resize(A, 0);

    for(int I = 0; I<A; I++)
    {
        parent[I] = I;
        parent_reverse[I] = I;
    }

}

int find(int e)
{
    if(parent[e]!=e)parent[e] = find(parent[e]);
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

int findReverse(int e)
{
    if(parent_reverse[e]!=e)parent_reverse[e] = findReverse(parent_reverse[e]);
    return parent_reverse[e];
}

void mergeReverse(int a, int b)
{
    a = findReverse(a);
    b = findReverse(b);

    if(weight_reverse[a]>weight_reverse[b])
    {
        parent_reverse[b] = a;
    }
    else
    {
        parent_reverse[a] = b;
    }

    if(weight_reverse[a] == weight_reverse[b])weight_reverse[b]++;
}
/*Fim Union Find*/
void read()
{
    cin>>N;
    A = 1000;
    start();
    edges.reserve(A);

    for(int I = 0; I<N; I++)
    {
        int U, V, W;
        cin>> U >> V >> W;

        edges.push_back( (make_pair(W, make_pair(U, V) ) ) );
    }
}

void kruskal()
{
    int cost_min = 0, cost_max = 0;
    sort(edges.begin(), edges.end());

    vector<pp>::iterator it;
    vector<pp>::reverse_iterator r_it;
    for(it = edges.begin(), r_it = edges.rbegin(); it!=edges.end(); it++, r_it++)
    {
        int U = it->second.first, V = it->second.second;
        int RU = r_it->second.first, RV = r_it->second.second;
        int W = it->first, RW = r_it->first;

        if(findReverse(RU) != findReverse(RV))
        {
            cost_max+=RW;
            mergeReverse(RU, RV);
        }
        if(find(U) != find(V))
        {
            cost_min+=W;
            merge(U, V);
        }
    }
    cout<<cost_max<<endl<<cost_min<<endl;
}
int main()
{
    read();
    kruskal();
}
