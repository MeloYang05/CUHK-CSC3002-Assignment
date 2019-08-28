/*
 * File: pqueue.h
 * --------------
 * This file exports the PriorityQueue class, a collection in which values
 * are processed in priority order.
 */

#ifndef _pqueue_h
#define _pqueue_h

#include "vector.h"
#include "error.h"
#include <iostream>

/*
 * Class: PriorityQueue<ValueType>
 * -------------------------------
 * This class models a structure called a priority queue in which values
 * are processed in order of priority.  As in conventional English usage,
 * lower priority numbers correspond to higher effective priorities, so
 * that a priority 1 item takes precedence over a priority 2 item.
 */

template <typename ValueType>
class PriorityQueue {

public:

/*
 * Constructor: Queue
 * Usage: Queue<ValueType> queue;
 * ------------------------------
 * Initializes a new empty queue.
 */

   PriorityQueue();

/*
 * Destructor: ~Queue
 * Usage: (usually implicit)
 * -------------------------
 * Frees any heap storage associated with this queue.
 */

   ~PriorityQueue();

/*
 * Method: size
 * Usage: int n = queue.size();
 * ----------------------------
 * Returns the number of values in the queue.
 */

   int size() const;

/*
 * Method: isEmpty
 * Usage: if (queue.isEmpty()) . . .
 * ---------------------------------
 * Returns true if the queue contains no elements.
 */

   bool isEmpty() const;

/*
 * Method: clear
 * Usage: queue.clear();
 * ---------------------
 * Removes all elements from this queue.
 */

   void clear();

/*
 * Method: enqueue
 * Usage: queue.enqueue(value);
 * ----------------------------
 * Adds value to the end of the queue.
 */

   void enqueue(ValueType value,double priority);

/*
 * Method: dequeue
 * Usage: ValueType first = queue.dequeue();
 * -----------------------------------------
 * Removes and returns the first item in the queue.  This method
 * signals an error if called on an empty queue.
 */

   ValueType dequeue();

/*
 * Method: peek
 * Usage: ValueType first = queue.peek();
 * --------------------------------------
 * Returns the first value in the queue without removing it.  This
 * method signals an error if called on an empty queue.
 */

   ValueType peek() const;

/*
 * Copy constructor and assignment operator
 * ----------------------------------------
 * These methods implement deep copying for queues.
 */

   PriorityQueue(const PriorityQueue<ValueType> & src);
   PriorityQueue<ValueType> & operator=(const PriorityQueue<ValueType> & src);

/* Private section */

/*
 * Implementation notes: PriorityQueue Data Structure
 * --------------------
 * This priorityqueue uses vector to store the elements. The vector
 * stores cell, which contains both data and priority information.
 * There is also a count value which store the next position is the
 * vector which the new elements can be added in.
 */

private:

/* Instance variables */

    struct Cell {
        ValueType data;
        double priority;
    };
    Vector<Cell> elements;
    int count;

/* Private method prototypes */

   void deepCopy(const PriorityQueue<ValueType> & src);
   //used in dequeue to change the ranking between the father node and son node using recursion
   void changeValue_forward(int position);
   // used in enqueue to change the ranking between the father node and son node using recursion
   void changeValue_reverse(int position);

};

/*
 * Implementation notes: PrioirtyQueue constructor
 * ---------------------------------------
 * The constructor initializes the count value.
 */

template <typename Valuetype>
PriorityQueue<Valuetype>::PriorityQueue() {
    count=0;
}

/*
 * Implementation notes: clear
 * ---------------------------
 * The clear method uses the clear method for vector and set the count
 * value to 0.
 */

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
    clear();
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods use the count variable and therefore run in constant time.
 */

template <typename ValueType>
int PriorityQueue<ValueType>::size() const {
   return count;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() const {
   return count == 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear() {
    elements.clear();
    count=0;
}

/*
 * Implementation notes: enqueue
 * -----------------------------
 * The enqueue method fisrtly add the new elements to the end of the vector.
 * Then it uses the recursion method changeValue_reverse to adjust the ranking
 * between the father node and son node.
 */

template <typename ValueType>
void PriorityQueue<ValueType>:: enqueue(ValueType value, double priority){
    Cell new_cell;
    new_cell.data=value;
    new_cell.priority=priority;
    elements.add(new_cell);
    changeValue_reverse(count);
    count++;
}

/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods check for an empty queue and report an error if
 * there is no first element.
 * For dequeue method, it output the first value in the vector, and
 * then put the last element in the vector to the first position in
 * the vector.Finally it uses the changeValue_forward to adjust ranking
 * between the father node and son node.
 */

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
   if (isEmpty()) error("dequeue: Attempting to dequeue an empty queue");
   ValueType out=elements[0].data;
   count--;
   elements[0]=elements[count];
   elements.remove(count);
   changeValue_forward(0);
   return out;
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek() const {
   if (isEmpty()) error("peek: Attempting to peek at an empty queue");
   return elements[0].data;
}

/*
 * Implementation notes: changeValue_reverse
 * ------------------------------------
 * It is a recursion method which change the ranking of the father node and
 * son node. The order is from the last element to the first element. If the
 * priority of father is larger than the son node, the ranking will be changed.
 * The recuision will stopped if position equals 0 or father node is smaller than
 * son node.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::changeValue_reverse(int position){
    if (position>0 && elements[position].priority<elements[(position-1)/2].priority){
        Cell tem_cell=elements[position];
        elements[position]=elements[(position-1)/2];
        elements[(position-1)/2]=tem_cell;
        changeValue_reverse((position-1)/2);
    }
}

/*
 * Implementation notes: changeValue_forward
 * ------------------------------------
 * It is a recursion method which change the ranking of the father node and
 * son node. The order is from the first element to the last element. If the
 * priority of father is larger than the son node, the ranking will be changed.
 * The recuision will stopped if position*2+1 is less than count. The recursion
 * will be both allied to left node and right node.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::changeValue_forward(int position) {
    if (position*2+1<count){
        if (elements[position].priority>elements[position*2+1].priority){
            Cell tem_cell=elements[position];
            elements[position]=elements[position*2+1];
            elements[position*2+1]=tem_cell;
            if (position*2+2<count){
                if (elements[position].priority>elements[position*2+2].priority){
                    Cell tem_cell=elements[position];
                    elements[position]=elements[position*2+2];
                    elements[position*2+2]=tem_cell;
                }
            }
        }
        //adjust the left node
        changeValue_forward(position*2+1);
        //adjust the right node
        changeValue_forward(position*2+2);
    }
}

/*
 * Implementation notes: Deep copying support
 * ------------------------------------------
 * These methods implement deep copying for queues.
 */

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue(const PriorityQueue<ValueType> & src) {
   deepCopy(src);
}

template <typename ValueType>
PriorityQueue<ValueType> & PriorityQueue<ValueType>::operator=(const PriorityQueue<ValueType> & src) {
   if (this != &src) {
      elements.clear();
      deepCopy(src);
   }
   return *this;
}
template <typename ValueType>
void PriorityQueue<ValueType>::deepCopy(const PriorityQueue<ValueType> & src){
    count=src.size();
    for (int i=0;i<count;i++) {
        Cell tem_cell=src.dequeue();
        elements.add(tem_cell);
    }
}
#endif
