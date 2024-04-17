// Write a C++ program to implement bfs(level order).
#include <iostream>
#include<vector>
#include<queue>
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
void bfs(vector<vector<int>>&graph,int start){
    vector<bool>visited(graph.size(),false);
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        cout<<current<<"->";
        for(auto neighbour:graph[current]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
            }
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
 bfs(graph,startvertex);
    return 0;
}