/*
 * File: StackDFS.cpp
 * ------------------
 * This program reimplements the depth-first search algorithm using an
 * explicit stack.
 */

#include "graphtypes.h"
#include "foreach.h"
#include "stack.h"
#include "set.h"
#include <iostream>
using namespace std;

//The prototype of visitingUsingDFS
void visitingUsingDFS(Node *node, Stack<Node *> &nodeStack,Set<Node *> &visited);

/*
 * Implementation Notes: depthFirstSearch
 * --------------------------------------
 * It contructs a nodeStack to control the search order, and it also consturcts a
 * visited set to store all the visited city, because there are some back flights
 * bwtween two citys. It put the start city node to the nodeStack first, and then
 * use the recursion method visitingUsingDFS to do the depth first search.
 */

void depthFirstSearch(Node *start) {
    Stack<Node *> nodeStack;
    Set<Node *> visited;
    nodeStack.push(start);
    visitingUsingDFS(start,nodeStack,visited);
}

/*
 * Implementation Notes: visitingUsingDFS
 * ---------------------------------------
 * Fistly the method will check whether the city node city is visited. If is visited,
 * it will remove the city from the stack, and do the next search. Else, it will print
 * out the name of city, add the city node to the visited set, add all the linked city
 * node of the city to the stack, and finally do the next search to the top city node in
 * nodeStack. This recursion method will stop until the nodeStack is empty.
 */
void visitingUsingDFS(Node *node, Stack<Node *> &nodeStack,Set<Node *> &visited){
    if (visited.contains(node)){
        nodeStack.pop();
        if (! nodeStack.isEmpty()) visitingUsingDFS(nodeStack.top(),nodeStack,visited);
    } else{
        cout<<node->name<<endl;
        visited.add(nodeStack.pop());
        foreach (Arc *arc in node->arcs){
            if (! visited.contains(arc->finish)) nodeStack.push(arc->finish);
        }
        if (! nodeStack.isEmpty()) visitingUsingDFS(nodeStack.top(),nodeStack,visited);
    }
}
