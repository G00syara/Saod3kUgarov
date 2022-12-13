#pragma once
#include <vector>
#include <exception>
#include <iostream>


class PriorityQueue
{
private:
	std::vector<int> queue;
	void FixHeap(int i, int length)
	{
		int left = 2 * i + 1, right = left + 1, largest;
			if ((left <= length) && (queue[left] > queue[i]))
				largest = left;
			else
				largest = i;
			if (right <= length && queue[right] > queue[largest])
				largest = right;
			if (largest != i)
			{
				int temp = queue[i];
				queue[i] = queue[largest];
				queue[largest] = temp;
				FixHeap(largest, length);
			}
	}

public:
	void Queue(int val) {
		queue.push_back(val);
		int n = queue.size() - 1;
		int parent = n / 2;
		while ((parent >= 0) && (queue[parent] < val))
		{
			int temp = queue[n];
			queue[n] = queue[parent];
			queue[parent] = temp;
			n = parent;
			parent = n / 2;
		}
	}
	int Pop()
	{
		try
		{
			if (queue.size() == 0)
				throw (1);
			else
			{
				int temp = queue[0];
				queue.erase(queue.begin());
				if (queue.size() > 0)
				{
					int temp2 = queue[queue.size() - 1];
					queue.pop_back();
					queue.insert(queue.begin(), temp2);
					FixHeap(0, queue.size() - 1);
				}
				return temp;
			}
		}
		catch(int a)
		{
			std::cout << "logic error" << std::endl;
		}
	}
	int GetSize()
	{
		return queue.size();
	}

};

