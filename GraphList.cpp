/*Write a c++ program to implement graph by using adjacency list.
(directed/undirected)
*/
#include <iostream>
#include<vector>
using namespace std;
void addEdge(vector<vector<int>>&adjList,int src,int dest)
{
    adjList[src].push_back(dest);
    //uncomment the below line for undirected graph
    //adjList[dest].push_back(src);
}
void printGraph(vector<vector<int>>&adjList)
{
   for(int src=0;src<adjList.size();src++){
       cout<<"Adjacency list of vertex"<<src;
       for(auto dest:adjList[src]){
           cout<<"->"<<dest;
       }
       cout<<endl;
   }
    }

int main() {
    int v,e;
    cout<<"enter no of vertices and edges";
    cin>>v>>e;
    vector<vector<int>>adjList(v);
    cout<<"enter the edges(source and destination)";
    for(int i=0;i<e;i++)
    {
        int src,dest;
        cin>>src>>dest;
        addEdge(adjList,src,dest);
    }
    printGraph(adjList);
    return 0;
}