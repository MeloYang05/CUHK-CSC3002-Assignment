/*
 * File: pqueue.h
 * --------------
 * This interface exports the PriorityQueue template class, which implements
 * a queue in which the elements are dequeued in priority order.
 */

#ifndef _pqueuelist_h
#define _pqueuelist_h

#include "error.h"

/*
 * Class: PriorityQueue<ValueType>
 * -------------------------------
 * This class models a linear structure called a priority queue in which
 * values are processed in order of priority.  As in conventional English
 * usage, lower priority numbers correspond to higher effective priorities,
 * so that a priority 1 item takes precedence over a priority 2 item.
 */

template <typename ValueType>
class PriorityQueue{

public:
/*
 * Constructor: PriorityQueue
 * Usage: PriorityQueue<ValueType> priorityqueue;
 * ------------------------------
 * Initializes a new empty priority queue.
 */

    PriorityQueue();

/*
 * Destructor: ~PrioirtyQueue
 * Usage: (usually implicit)
 * -------------------------
 * Frees any heap storage associated with this priority queue.
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

    void enqueue(ValueType value, double priority);

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

    PriorityQueue(const PriorityQueue<ValueType> &src);
    PriorityQueue<ValueType> & operator=(const PriorityQueue<ValueType> &src);

/*
 * Implementation notes: Queue data structure
 * ------------------------------------------
 * The list-based queue uses a linked list to store the elements
 * of the queue.  To ensure that adding a new element to the tail
 * of the queue is fast, the data structure maintains a pointer to
 * the last cell in the queue as well as the first.  If the queue is
 * empty, both the head pointer and the tail pointer are set to NULL.
 * Waht's more, there is also a priority to store the priority of the element*/

private:

/* Type for linked list cell */

    struct Cell{
        ValueType data;         /* The data value                  */
        Cell *link;             /* Link to the next cell           */
        double priority;        /*The priority value               */
    };

/* Instance variables */

       Cell *head;                          /* Pointer to the cell at the head */
       Cell *tail;                          /* Pointer to the cell at the tail */
       int count;                           /* Number of elements in the queue */

/* Private method prototypes */

    void deepcopy(const PriorityQueue<ValueType> &src);

};

/*
 * Implementation section
 * ----------------------
 * C++ requires that the implementation for a template class be available
 * to the compiler whenever that type is used.  The effect of this
 * restriction is that header files must include the implementation.
 * Clients should not need to look at any of the code beyond this point.
 */

/*
 * Implementation notes: PriorityQueue constructor
 * ---------------------------------------
 * The constructor creates an empty linked list and sets the count to 0.
 */

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue(){
    head=tail=NULL;
    count=0;
}

/*
 * Implementation notes: ~PriorityQueue destructor
 * ---------------------------------------
 * The destructor frees any heap memory allocated by the queue.
 */

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue(){
    clear();
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods use the count variable and therefore run in constant time.
 */

template <typename ValueType>
int PriorityQueue<ValueType>::size() const{
    return count;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() const{
    return count==0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear(){
    while (count>0){
        dequeue();
    }
}

/*
 * Implementation notes: enqueue
 * -----------------------------
 * This method allocates a new list cell to the chain and the location depends
 * on the priority it has. If the queue is currently empty, the new cell also
 * becomes the head pointer in the queue.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, double priority){
    Cell *cp= new Cell;
    cp->data=value;
    cp->priority=priority;
    cp->link=NULL;
    //The queue is empty
    if (head==NULL && tail==NULL){
        head=cp;
        tail=cp;
    } else{
        for (Cell *i=head;i!=NULL;i=i->link){
            //new cell has the highest priority
            if (priority < i->priority){
                cp->link=i;
                i=cp;
                break;
            //new cell has the lowest priority
            } else if (priority>=i->priority && i==tail){
                i->link=cp;
                tail=cp;
                break;
            //new cell should be inserted between two cells
            } else if (priority>=i->priority && priority<i->link->priority){
                cp->link=i->link;
                i->link=cp;
                break;
            }
        }
    }
    count++;
}

/*
 * Implementation notes: dequeue, peek
 * -----------------------------------
 * These methods check for an empty queue and report an error if
 * there is no first element.  The dequeue method also checks for
 * the case in which the queue becomes empty and sets both the head
 * and tail pointers to NULL.
 */

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue(){
    if (isEmpty()) error ("dequeue: Atempting to dequeue an empty queue");
    Cell *cp=head;
    head=cp->link;
    ValueType result=cp->data;
    if (head==NULL) tail=NULL;
    delete cp;
    count--;
    return result;
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek() const{
    if (isEmpty()) error("peek: Atempting to peek an empty queue");
    return head->data;
}

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue(const PriorityQueue<ValueType> &src){
    deepcopy(src);
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods follow the standard template, leaving the work to deepCopy.
 */

template <typename ValueType>
PriorityQueue<ValueType> & PriorityQueue<ValueType>::operator=(const PriorityQueue<ValueType> &src){
    if (this != &src) {
        clear();
        deepcopy(src);
    }
    return *this;
}

/*
 * Implementation notes: deepCopy
 * ------------------------------
 * This function copies the data from the src parameter into the current
 * object.  This implementation simply walks down the linked list in the
 * source object and enqueues each value in the destination.
 */

template <typename ValueType>
void PriorityQueue<ValueType>::deepcopy(const PriorityQueue<ValueType> &src) {
    head=NULL;
    tail=NULL;
    count=0;
    for (Cell *cp=src.head;cp!=NULL;cp=cp->link){
        enqueue(cp->data);
    }
}

#endif
