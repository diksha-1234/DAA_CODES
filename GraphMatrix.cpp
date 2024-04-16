/*Write a c++ program to implement graph by using adjacency matrix.
(directed/undirected)
*/
#include <iostream>
#include<vector>
using namespace std;
void addEdge(vector<vector<int>>&adjMatrix,int src,int dest)
{
    adjMatrix[src][dest]=1;
    //uncomment the below line for undirected graph
    //adjMatrix[dest][src]=1;
}
void printGraph(vector<vector<int>>&adjMatrix)
{
    cout<<"Adjacency Matrix Representation of a graph"<<endl;
    for(int i=0;i<adjMatrix.size();i++)
    {
        for(int j=0;j<adjMatrix[i].size();j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int v,e;
    cout<<"enter no of vertices and edges";
    cin>>v>>e;
    vector<vector<int>>adjMatrix(v,vector<int>(v,0));
    cout<<"enter the edges(source and destination)";
    for(int i=0;i<e;i++)
    {
        int src,dest;
        cin>>src>>dest;
        addEdge(adjMatrix,src,dest);
    }
    printGraph(adjMatrix);
    return 0;
}