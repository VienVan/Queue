#include <iostream>
#include "Queue.h"
using namespace std;
#include <assert.h>

Queue::Queue() : front(NULL), end(NULL), size(0) {}

Queue::Queue(const Queue &queue):size(queue.size)
{

        if(queue.front == NULL)
        {
            end = front = NULL;
        }
        else
        {
            front = new Node;
            front->data = queue.front->data;
            NodePtr temp;
            temp = queue.front;
            NodePtr qtemp = front; //create temporary iterator

            while(temp->next != NULL)
            {

                qtemp->next = new Node;
                qtemp = qtemp->next;
                temp = temp->next;
                qtemp->data = temp->data;
            }

            end = qtemp;
        }

}

Queue::~Queue()
{
    NodePtr temp = front;
    NodePtr temp2 = front;
    while (temp != NULL)
    {
        temp = temp->next;
        delete temp2;
        temp2 = temp;
    }
}

void Queue::dequeue(){
	assert (size != 0);

		if (size == 1) {

	        delete front;

	        front = end = NULL;

	        size = 0;

	    } else {

	        NodePtr temp = front; //store pointer to first so we don't lose access to it

	        front = front->next; //advance the pointer

	        delete temp; //free the memory for the original first node

	        size--;
	    }
}

void Queue::enqueue(string data) {
	NodePtr N = new Node(data);
	if(size == 0)
	{
		front = end = N;
	}
	else
	{
		end->next = N;
		end = N;
	}
	size++;

}

bool Queue::operator==(const Queue &queue){
	if(size != queue.size)
	        return false;
	    NodePtr temp1 = front;
	    NodePtr temp2 = queue.front;
	    while(temp1 != NULL)
	    {
	        if(temp1->data != temp2->data)
	            return false;
	        temp1 = temp1->next;
	        temp2 = temp2->next;
	    }
	    return true;
}

string Queue::get_front() {
	assert (size != 0);
	return front->data;
}

int Queue::get_size() { return size; }

void Queue::print()
{
    NodePtr temp;
    temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool Queue::is_empty()
{
	return (size == 0) ? true : false;
}
