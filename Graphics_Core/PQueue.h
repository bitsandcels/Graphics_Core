#include <queue>
#include "DynamicObject.h"
#include "StaticObject.h"

#pragma once

struct DataStructure;

class PQueue
{
public:
	PQueue();			// Default constructor uses 50 priorities;
	PQueue(int);		// Allows for the number of priorities to be customized;
	~PQueue();			// Destructor to clear memory when done.

	int GetLength();				// Returns the number of items in the priority queue
	bool Enqueue(DataStructure &);	// Add a new item to the queue
	bool Dequeue(DataStructure &);	// Remove the highest priority member from the queue
	bool MakeEmpty();				// Clear all members from the queue

private:
	int length;								// Number of elements in the PQueue
	int numPriorities;						// Number of priorities elements can be sorted into
	std::queue<DataStructure> * queues;	// A pointer to a queue of Data Structure pointers. Allows for dynamic allocation of of queues.
};

struct DataStructure
{
	DataStructure() {};
	int priority;
	bool staticObject;
	DynamicObject dObject;
	StaticObject sObject;
};
