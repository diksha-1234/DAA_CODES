#include<bits/stdc++.h>
using namespace std;
struct node{
    int parent;
    int rank;
};
struct edge{
    int src;
    int dest;
    int wt;
};
vector<node> ds;
vector<edge>mst;
int find(int v){
    if(ds[v].parent==-1){
        return v;
    }
    return ds[v].parent=find(ds[v].parent);
}
void union_op(int fromP,int toP){
    if(ds[fromP].rank>ds[toP].rank){
        ds[toP].parent=fromP;
    }
    else if(ds[fromP].rank<ds[toP].rank){
        ds[fromP].parent=toP;
    }
    else{
        ds[fromP].parent=toP;
        ds[toP].rank+=1;
    }
}
bool comparator(edge a,edge b){
    return a.wt<b.wt;
}
void kruskals(vector<edge>&edgelist,int V,int E){
    sort(edgelist.begin(),edgelist.end(),comparator);
    for(int i=0;i<V;i++){
        ds[i].parent=-1;
        ds[i].rank=0;
    }
    int i=0,j=0;
    while(i<V-1&&j<E){
        int fromP=find(edgelist[j].src);
        int toP=find(edgelist[j].dest);
        if(fromP==toP){
            ++j;
            continue;
        }
        mst.push_back(edgelist[j]);
        union_op(fromP,toP);
        ++i;
    }
}
void printmst(){
    cout<<"mst---------------->";
    cout<<"(src,dest,weight)"<<endl;
    for(auto x:mst){
        cout<<"("<<x.src<<","<<x.dest<<","<<x.wt<<")"<<endl;
    }
}
int main(){
    int V,E;
    cin>>V>>E;
    ds.resize(V);
    vector<edge>edgelist;
    edge temp;
    for(int i=0;i<E;i++){
        int from,to,w;
        cin>>from>>to>>w;
        temp.src=from;
        temp.dest=to;
        temp.wt=w;
        edgelist.push_back(temp);
    }
    kruskals(edgelist,V,E);
    printmst();
}
