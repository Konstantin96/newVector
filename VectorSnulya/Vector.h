#include <iostream>
#pragma once
using namespace std;

class Vector {
private:
	int cur_size;
	int buf_size;
	double *els;
public:
	//constructors
	Vector();
	Vector(int size);
	Vector(const Vector &obj);	
	int size()const {
		return cur_size;
	}

	//operators
	Vector operator=(const Vector &obj);
	void operator+(const Vector &obj);
	void operator-(const Vector &obj);
	double &operator[](int index);
	bool operator==(Vector &obj);
	bool operator!=(Vector &obj);
	friend ostream& operator<<(ostream& os, Vector v);
	friend ifstream& operator>>(ifstream& os, Vector v);


	//methods
	double& push_back(double e);
	double& at(int index);



	~Vector() { delete[]els; }
};