// C++ code to represent graph as an adjacency list::

#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e;
    cin>>v>>e;
    // For weighted graphs, we can create a vector of pairs!
    vector<int>n[v+1];
    while(e--){
        int m,k;
        cin>>m>>k;
        n[m].push_back(k);
        // Comment out the below statement to get directed graphs representation!
        n[k].push_back(m);
    }
    for(int i=1;i<=v;i++){
        cout<<i<<"-->";
        for(auto x:n[i]){
            cout<<x<<",";
        }
        cout<<endl;
    }
    
}