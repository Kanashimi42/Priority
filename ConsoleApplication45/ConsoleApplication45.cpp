#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {
	PriorityQueue a(5);
	string tempName;
	int tempPriority;

	for (int i = 0; i < 4; i++) {
		cout << "Enter name: ";
		cin >> tempName;
		do {
			cout << "Enter priority (less)1-10(more): ";
			cin >> tempPriority;

			if (tempPriority > 10 || tempPriority < 1)
				cout << "You entered an incorrect priority!" << endl << endl;
		} while (tempPriority > 10 || tempPriority < 1);

		a.Add(tempName, tempPriority);
	}
	cout << endl;

	a.Show();
	cout << endl;

	cout << "Priority Statistics: " << endl;
	for (int i = 0; i < 4; i++)
		cout << i + 1 << ". " << a.Extract() << endl;

	return 0;
}
