#pragma once

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
	double &operator[](int index);

	//methods
	double& push_back(double e);
	double& at(int index);

	bool Vector::operator==(Vector &obj);
	~Vector() { delete[]els; }

};