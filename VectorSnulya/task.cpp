#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
	Vector v,v1;
	v.push_back(10);
	v.push_back(2.5);
	v.push_back(4.3);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
	cout << "\n\n"<<endl;
	v[0] = 1.8;
	v.at(1) = 5.4;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << "\n\nVector v2  " << endl;
	Vector v2 (v);
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << endl;
	}

	cout << "\n\n" << endl;
	cout << (v==v2) << endl;
	system("pause");
	return 0;
}