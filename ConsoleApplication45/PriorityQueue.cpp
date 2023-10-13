#include <iostream>
#include "PriorityQueue.h"

using namespace std;
PriorityQueue::PriorityQueue(int maxSize) {
	maxQueueLength = maxSize;
	wait = new client[maxQueueLength];
	priority = new int[maxQueueLength];
	queueLength = 0;
}
PriorityQueue::~PriorityQueue() {
	delete[] wait;
	delete[] priority;
}

void PriorityQueue::Add(string n, int p) {
	if (!IsFull()) {
		wait[queueLength].name = n;
		priority[queueLength] = p;
		queueLength++;
	}
}

void PriorityQueue::Show() {
	for (int i = 0; i < queueLength; i++)
		cout << "Name: " << wait[i].name << " Priority: " << priority[i] << endl;
}

string PriorityQueue::Extract() {
	if (!IsEmpty()) {
		int indexMaxPriority = 0;

		for (int i = 1; i < queueLength; i++)
			if (priority[indexMaxPriority] < priority[i])
				indexMaxPriority = i;

		string temp1 = wait[indexMaxPriority].name;
		int temp2 = priority[indexMaxPriority];

		for (int i = indexMaxPriority; i < queueLength - 1; i++) {
			wait[i] = wait[i + 1];
			priority[i] = priority[i + 1];
		}
		queueLength--;

		return temp1;
	}
	string err = "Error";
	return err;
}

void PriorityQueue::Clear() { queueLength = 0; }

bool PriorityQueue::IsEmpty() { return queueLength == 0; }
bool PriorityQueue::IsFull() { return queueLength == maxQueueLength; }

int PriorityQueue::GetCount() { return queueLength; }