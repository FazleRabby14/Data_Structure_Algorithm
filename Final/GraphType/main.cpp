#include "graphtype.cpp"
#include<iostream>
using namespace std;

int main()
{
    GraphType<char> graph;
    graph.AddVertex('A');
    graph.AddVertex('B');
    graph.AddVertex('C');
    graph.AddVertex('D');
    graph.AddVertex('E');
    graph.AddVertex('F');
    graph.AddVertex('G');
    graph.AddVertex('H');

    graph.AddEdge('A','B',1);
    graph.AddEdge('B','C',1);
    graph.AddEdge('B','D',1);
    graph.AddEdge('C','D',1);
    graph.AddEdge('D','E',1);
    graph.AddEdge('D','F',1);
    graph.AddEdge('E','G',1);
    graph.AddEdge('F','H',1);

    int outDegree=graph.OutDegree('D');
    cout<<"OutDegree of graph D is:"<<outDegree<<endl;

    bool foundEdgeBD=graph.FoundEdge('B','D');
    if(foundEdgeBD){
        cout<<"There is an Edge"<<endl;
    }
    else{
        cout<<"There is not an Edge"<<endl;
    }

    cout<<"Path B to E using Depth first Search:"<<endl;
    graph.DepthFirstSearch('B','E');

    cout<<"Path E to B using Breadth first Search:"<<endl;
    graph.BreadthFirstSearch('B','E');

}
