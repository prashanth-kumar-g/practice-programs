// C++ program to illustate the queue container
#include <iostream>
#include <queue>
using namespace std;

int main()
{

	// creating queue
	queue<int> q;

	// pushing elements
	for (int i = 1; i <= 5; i++) {
		q.push(i);
	}
	q.push(6);

	cout << "q.front() = " << q.front() << endl;
	cout << "q.back() = " << q.back() << endl;

	// printing queue by popping all elements
	cout << "q: ";
	int size = q.size();
	for (int i = 0; i < size; i++) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}
