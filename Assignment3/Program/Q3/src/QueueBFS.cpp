/*
 * File: QueueBFS.cpp
 * ------------------
 * This program reimplements the breadth-first search algorithm using an
 * explicit queue.
 */
#include "graphtypes.h"
#include "foreach.h"
#include "queue.h"
#include "set.h"
using namespace std;

void visitingUsingBFS(Node *node, Queue<Node *> &nodeQueue, Set<Node *> &visited);

void breadthFirstSearch(Node *start) {
    Queue<Node *> nodeQueue;
    Set<Node *> visited;
    nodeQueue.enqueue(start);
    visitingUsingBFS(start,nodeQueue, visited);
}
void visitingUsingBFS(Node *node, Queue<Node *> &nodeQueue, Set<Node *> &visited){
    if (visited.contains(node)){
        nodeQueue.dequeue();
        if (! nodeQueue.isEmpty()) visitingUsingBFS(nodeQueue.peek(),nodeQueue, visited);
    }else {
        cout<<node->name<<endl;
        visited.add(nodeQueue.dequeue());
        foreach (Arc *arc in node->arcs){
            if (! visited.contains(arc->finish)) nodeQueue.enqueue(arc->finish);
        }
        if (! nodeQueue.isEmpty()) visitingUsingBFS(nodeQueue.peek(),nodeQueue, visited);
    }
}
