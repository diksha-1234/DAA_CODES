#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
void addedge(vector<vector<pii>>&graph,int s,int d,int w){
    graph[s].push_back({d,w});
    graph[d].push_back({s,w});
}
void printgraph(vector<vector<pii>>&graph){
    for(int u=0;u<graph.size();u++){
        cout<<u<<"->";
        for(auto neighbour:graph[u]){
            cout<<neighbour.first<<",";
        }
        cout<<endl;
    }
}
void dijkstra(vector<vector<pii>>&graph,int start,int end){
    int n=graph.size();
    vector<int>dist(n,INT_MAX);
    vector<int>parent(n,-1);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto neighbour:graph[u]){
            int v=neighbour.first;
            int w=neighbour.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
                parent[v]=u;
            }
        }
    }
    cout<<"minimum distance from start->end"<<dist[end]<<endl;
    vector<int>path;
    for(int x=end;x!=-1;x=parent[x]){
        path.push_back(x);
    }
    cout<<"path"<<endl;
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<"->";
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<pii>>graph(v);
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        addedge(graph,s,d,w);
    }
    printgraph(graph);
    int start,end;
    cin>>start>>end;
    dijkstra(graph,start,end);
}