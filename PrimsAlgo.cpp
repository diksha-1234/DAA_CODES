#include<iostream>
#include<climits>
#include<vector>
#define V 5
using namespace std;
void addedge(vector<vector<int> >&graph,int src,int dest,int value){
	graph[src][dest]=value;
	graph[dest][src]=value;
}
void printgraph(vector<vector<int> >&graph){
	for(int u=0;u<graph.size();u++){
		for(int v=0;v<graph[u].size();v++){
			cout<<graph[u][v]<<" ";
		}
		cout<<endl;
	}
}
int minkey(int dist[V],bool mstset[V]){
	int min=INT_MAX,min_index;
	for(int i=0;i<V;i++){
		if(mstset[i]==false&&dist[i]<min){
			min=dist[i];
			min_index=i;
		}
	}
	return min_index;
}
void printmst(vector<vector<int> >&graph,int parent[V],int dist[V],bool mstset[V]){
	cout<<"M S T------->"<<endl;
	for(int i=1;i<V;i++){
		cout<<parent[i]<<"-"<<i<<"\t"<<graph[parent[i]][i]<<endl;
	}
	cout<<"modified distance array:"<<endl;
	for(int i=0;i<V;i++){
		cout<<dist[i]<<" ";
	}
	cout<<"modified mst status:"<<endl;
	for(int i=0;i<V;i++){
		cout<<mstset[i]<<" ";
	}
	cout<<"modified parent array"<<endl;
	for(int i=0;i<V;i++){
		cout<<parent[i]<<" ";
	}
}
void prims(vector<vector<int> >&graph){
	int dist[V];
	int parent[V];
	bool mstset[V];
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		mstset[i]=false;
	}
	parent[0]=-1;
	dist[0]=0;
	for(int count=0;count<V-1;count++){
		int src=minkey(dist,mstset);
			mstset[src]=true;
			
		for(int dest=0;dest<V;dest++){
			if(graph[src][dest]&&mstset[dest]==false&&graph[src][dest]<dist[dest]){
				parent[dest]=src;
				dist[dest]=graph[src][dest];
			}
		}
	}
	printmst(graph,parent,dist,mstset);
	
}
int main(){
	int e;
	cin>>e;
	vector<vector<int> >graph(V,vector<int>(V,0));
	for(int i=0;i<e;i++){
		int src,dest,value;
		cin>>src>>dest>>value;
		addedge(graph,src,dest,value);
	}
	printgraph(graph);
	prims(graph);
}