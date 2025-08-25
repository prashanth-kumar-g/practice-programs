// C++ Program to illustrate the stack
#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack<int> s;

	for (int i = 1; i <= 5; i++) {
		s.push(i);
	}

	s.push(6);
	// checking top element
	cout << "s.top() = " << s.top() << endl;

	// getting all the elements
	cout << "s: ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	// size after popping all elements
	cout << "\nFinal Size: " << s.size();

	return 0;
}
