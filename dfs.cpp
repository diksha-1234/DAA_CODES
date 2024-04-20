// Write a C++ program to implement dfs(preorder).
#include <iostream>
#include<vector>
using namespace std;
void addEdge(vector<vector<int>>&graph,int src,int dest)
{
    graph[src].push_back(dest);
}
void printGraph(vector<vector<int>>&graph){
    for(int i=0;i<graph.size();i++){
        cout<<"adjacency list of vertex"<<i;
        for(auto dest:graph[i]){
            cout<<"->"<<dest;
        }
        cout<<endl;
    }
}
void dfs(vector<vector<int>>&graph,int start,vector<bool>&visited){
    visited[start]=true;
    cout<<start<<"->";
        for(auto neighbour:graph[start]){
            if(!visited[neighbour]){
               dfs(graph,neighbour,visited);
            }
        }
}
int main() {
 int v,e;
 cout<<"enter no of vertices and edges";
 cin>>v>>e;
 vector<vector<int>>graph(v);
 cout<<"add edges(src and dest)";
 for(int i=0;i<e;i++)
 {
     int src,dest;
     cin>>src>>dest;
     addEdge(graph,src,dest);
 }
 printGraph(graph);
 int startvertex;
 cout<<"enter startvertex";
 cin>>startvertex;
 vector<bool>visited(graph.size(),false);
 dfs(graph,startvertex,visited);
    return 0;
}