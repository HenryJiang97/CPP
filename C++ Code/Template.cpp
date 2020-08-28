#include<iostream>
using namespace std;

template <typename T>

void swp (T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	/* code */

	int a = 2;
	int b = 4;

	swp(a, b);

	cout<<a<<" "<<b;

	return 0;
}