#include <iostream>
#include <vector>
#include <list>

using namespace std;



vector<list<int>> graph;
int v;

void addEdge(int src , int dest  , bool bi_dir = true){

        graph[src].push_back(dest);

        if(bi_dir){
            graph[dest].push_back(src);
        }
}

void display(){

    for(int i = 0 ; i<graph.size();i++){
        cout<<i<<"->";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<"\n";
    }
}

int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;

    while(e--){
        int s,d;
        cin>>s>>d;
        addEdge(s,d ,true);
    }
    display();
}

