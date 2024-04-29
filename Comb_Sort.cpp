#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int gap=n;
    bool isSwapped=true;
    while(gap>1||isSwapped){
        gap=floor(gap/1.3);
        if(gap<1){
            gap=1;
        }
        isSwapped=false;
        for(int i=0;i<n-gap;i++){
            if(v[i]>v[i+gap]){
                swap(v[i],v[i+gap]);
                isSwapped=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}