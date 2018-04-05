#include "PQueue.h"

PQueue::PQueue()
{
	queues = new std::queue<DataStructure*>[50];
	numPriorities = 50;
	length = 0;
}

PQueue::PQueue(int size)
{
	queues = new std::queue<DataStructure*>[size];
	numPriorities = size;
	length = 0;
}

PQueue::~PQueue()
{
	delete[] queues;
}

int PQueue::GetLength()
{
	return length;
}

bool PQueue::Enqueue(DataStructure * data)
{
	int priority = data->priority;
	int startLength = queues[priority].size();
	queues[priority].push(data);
	int endLength = queues[priority].size();

	if (endLength > startLength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PQueue::Dequeue(DataStructure * data)
{
	if (length > 0)
	{
		int priority;
		for (int i = 0; i < numPriorities; i++)
		{
			if (!queues[i].empty())
			{
				priority = i;
				i = numPriorities;
			}
		}

		int startLength = queues[priority].size();
		data = queues[priority].front();
		queues[priority].pop();
		int endLength = queues[priority].size();
		if (startLength > endLength)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool PQueue::MakeEmpty()
{
	delete[] queues;
	queues = new std::queue<DataStructure*>[numPriorities];
	length = 0;

	if (length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
