#include "../../Libraries/src/LinkedList.hpp"
#include "../../Libraries/src/PriorityQueue.hpp"
#include "../../Libraries/src/MinComparator.hpp"
#include "GraphNode.hpp"

#include <vector>
#include <limits>
#include <iostream>

using namespace std;

// build list from easy to understand input
// avoiding using std datastructures so that maybe my library/templating/makefile practice was worth it...
LinkedList<LinkedList<GraphNode*>*> *BuildAdjacencyList() {
    
    vector<vector<int> > adj_con = {
        { 1, 2, 3 },
        { 0, 2, 4 },
        { 0, 1, 3, 4 },
        { 0, 2, 5 },
        { 1, 2, 5 },
        { 3, 4 }
    };

    vector<vector<int> > adj_val = {
        { 7, 9, 14 }, 
        { 7, 10, 15 },
        { 9, 10, 2, 11 },
        { 14, 2, 9 },
        { 15, 11, 6 },
        { 9, 6 }
    };

    LinkedList<LinkedList<GraphNode*>*> *adjacency_list = new LinkedList<LinkedList<GraphNode*>*>();
    
    for(int i = 0; i < adj_con.size(); i++) {
        LinkedList<GraphNode*>* node_list = new LinkedList<GraphNode*>();

        vector<int> node_con = adj_con[i];
        vector<int> node_val = adj_val[i];
        
        for(int j = 0; j < node_con.size(); j++) {
            node_list->Add(new GraphNode(node_con[j], node_val[j]));    
        }
        adjacency_list->Add(node_list);
    }

    return adjacency_list;
}

void DestroyAdjacencyList(LinkedList<LinkedList<GraphNode*>*> *adjacency_list) {
    for(int i = adjacency_list->Size()-1; i >= 0; i--) {
        LinkedList<GraphNode*>* node_list = adjacency_list->Get(i);
        for(int j = node_list->Size()-1; j >= 0; j--) {
            delete node_list->Get(j);
        }
        delete node_list;
    }
    delete adjacency_list;
}

void PrintNode(GraphNode* node) {
    cout << node->Id() << ":" << node->Dist() << "\n"; 
}

void DijkstraAlgorithm(LinkedList<LinkedList<GraphNode*>*> *adjacency_list, int source, int target) {
    // build heap of all nodes, with their current distances set to infinity.
    // set starting node to 0.
    PriorityQueue<GraphNode*>* pq = new PriorityQueue<GraphNode*>(adjacency_list->Size(), new MinComparator<GraphNode*>());

    for(int i = 0; i < adjacency_list->Size(); i++) {
        GraphNode* node;
        if(i == source) {
            node = new GraphNode(i, 0);
        } else {
            node = new GraphNode(i, numeric_limits<int>::max());
        }
        pq->Offer(node);
    }

    // poll first member off of heap.
    while(pq->Size() != 0) {
        GraphNode* current = pq->Poll();
        LinkedList<GraphNode*>* current_data = adjacency_list->Get(current->Id());

        for(int i = 0; i < current_data->Size(); i++) {
            GraphNode* neighbour_data = current_data->Get(i);
            
            // if the neighbour hasn't been marked visited yet, we need to access it
            if(pq->Contains(neighbour_data)) {
                LinkedList<GraphNode*> tmp;
                
                while(*pq->Peek() != *neighbour_data) {
                    tmp.Add(pq->Poll());
                }
                 
                // compare the neighbours current shortest distance to it with the distance to current node
                // plus the cost to access the neighbour
                GraphNode* neighbour = pq->Poll();
                if(neighbour->Dist() > current->Dist() + neighbour_data->Dist()) {
                    neighbour->UpdateDist(current->Dist() + neighbour_data->Dist());
                }
                
                pq->Offer(neighbour);
                for(int j = tmp.Size()-1; j >= 0; j--) {
                    pq->Offer(tmp.Get(j));
                }
            }
        }
         
        PrintNode(current);
        
        delete current;
    }

    delete pq;
}

int main() {
    LinkedList<LinkedList<GraphNode*>*> *adjacency_list = BuildAdjacencyList();

    DijkstraAlgorithm(adjacency_list, 0, 5);

    DestroyAdjacencyList(adjacency_list);

    return 0;
}
