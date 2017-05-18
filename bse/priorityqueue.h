#pragma once
template<typename K>
class PriorityQueue
{
public:
	PriorityQueue();
	PriorityQueue(int max);
	PriorityQueue<K>(K a[]);
	~PriorityQueue();

	void insert(K v);
	K max();
	K delMax();
	bool isEmpty();
	int size();

private:
	K pq[];
	int N = 0;
};

