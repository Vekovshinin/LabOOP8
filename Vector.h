#pragma once
#include<iostream>
#include "ClassPrint.h"
using namespace std;

class Vector
{
protected:
	Print** obj;
	int size;
	int current_size = 0;
public:
	void Add() {
		cout << "1. Print\n2. Magazine\n>";
		int x; cin >> x; 
		if (x == 1) {
			Print* tmp = new Print;
			tmp->SetInf();
			if (current_size < size) {
				obj[current_size] = tmp;
				current_size++;
			}
			else {
				Print** temp = new Print * [size + 1];
				for (int i = 0; i < size; ++i)
					temp[i] = obj[i];
				temp[size] = tmp;
				delete[] obj;
				obj = temp;
				current_size++;
			}
		}
		if (x == 2) {
			Magazine* tmp = new Magazine;
			tmp->SetInf();
			if (current_size < size) {
				obj[current_size] = tmp;
				current_size++;
			}
			else {
				Print** temp = new Print * [size + 1];
				for (int i = 0; i < size; ++i)
					temp[i] = obj[i];
				temp[size] = tmp;
				delete[] obj;
				obj = temp;
			}
		}
	}
	void del() {
		Print** temp = new Print * [size - 1];
		for (int i = 0; i < size-1; ++i)
			temp[i] = obj[i];
		delete[] obj;
		obj = temp;
		current_size--;
		size--;
	}
	void show() {
		for (int i = 0; i < current_size; ++i)
			obj[i]->GetInfo();
	}
	void showName() {
		for (int i = 0; i < current_size; ++i)
			obj[i]->GetName();
	}
};


