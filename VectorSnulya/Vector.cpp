#include "Vector.h"

Vector::Vector() {
	cur_size = 0;
	buf_size = 0;
	els = nullptr;
}

Vector::Vector(int size) {
	this->cur_size = size;
	this->buf_size = size;
	this->els = new double[size];
	for (int i = 0; i < size; i++) {
		els[i] = 0.0;
	}
}

Vector::Vector(const Vector &obj) {
	this->cur_size = obj.size();
	this->buf_size = obj.size();
	this->els = new double[size()];
	for (int i = 0; i < size(); i++) {
		this->els[i] = obj.els[i];
	}
}

Vector Vector::operator=(const Vector &obj) {
	this->cur_size = obj.size();
	this->buf_size = obj.size();
	this->els = new double[size()];
	for (int i = 0; i < size(); i++) {
		this->els[i] = obj.els[i];
	}
	return *this;
}

double& Vector::push_back(double e) {
	if (buf_size <= 0)
	{
		buf_size = 2;
		els = new double[buf_size];
	}
	else {
		if (cur_size >= buf_size) {
			buf_size *= 2;
			double *tmp;
			tmp = new double[buf_size];
			for (int i = 0; i < size(); i++)
				tmp[i] = els[i];
			delete[] els;
			els = tmp;
		}
	}
	els[cur_size++] = e;
	return els[cur_size - 1];
}

double& Vector::at(int index) {
	if (index<0 || index>size())
		return els[0];
	else
		return els[index];
}

double& Vector::operator[](int index) {
	return els[index];
}

bool Vector::operator==(Vector &obj) {
	if (size() != obj.size())
		return false;
	else {
		for (int i = 0; i < size(); i++)
		{
			if (els[i] != obj.els[i])
				return false;
		}
		return true;
	}
}

void  Vector::operator+(const Vector &obj) {
	for (int i = 0; i < size(); i++)
	{
		els[i] += obj.els[i];
	}
}

void  Vector::operator-(const Vector &obj) {
	for (int i = 0; i < size(); i++)
	{
		els[i] -= obj.els[i];
	}
}

bool Vector::operator!=(Vector &obj) {
	if (size() != obj.size())
		return true;
	else {
		for (int i = 0; i < size(); i++)
		{
			if (els[i] != obj.els[i])
				return true;
		}
		return false;
	}
}

ostream& operator<<(ostream& os, Vector v) {
	for (int i = 0; i < v.size(); i++)
	{
		os << v[i] << "\t";
		return os;
	}
}

ifstream& operator<<(ifstream& os, Vector v) {
	for (int i = 0; i < v.size(); i++)
	{
		os >> v[i];
		return os;
	}
}

