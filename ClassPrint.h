#pragma once
#include<iostream>
using namespace std;

class Magazine;

class Object {
public:
	virtual string GetAuthor() = 0;
	virtual string GetName() = 0;
	virtual void SetAuthor(string) = 0;
	virtual void SetName(string) = 0;
	virtual void GetInfo() = 0;
	virtual void SetInf() = 0;
};

class Print : public Object{
	string name;
	string author;
public:
	Print() {
		name = "Unknown"; author = "Unknown";
	}
	string GetAuthor() override;
	string GetName() override;
	void SetAuthor(string) override;
	void SetName(string) override;
	Print(string name, string author);
	void SetInf() override;
	void GetInfo() override {
		cout << "Название: " << this->name;
		cout << endl << "Автор: " << this->author;
		cout << endl;
	}
};
Print::Print(string name, string author) {
	this->author = author;
	this->name = name;
}
string Print::GetAuthor() {
	return this->author;
}
string Print::GetName() {
	return this->name;
}
void Print::SetName(string a) {
	this->name = a;
}
void Print::SetAuthor(string a) {
	this->author = a;
}
void Print::SetInf() {
	string a, b;
	cout << "Введите название: "; cin >> a;
	this->name = a;
	cout << "Введите автора: "; cin >> b;
	this->author = b;
}

class Magazine : public Print {
	int count_page;
public:
	Magazine() {
		count_page = 0;
	}
	void GetInfo() override {
		cout << "Название: " << GetName();
		cout << endl << "Автор: " << GetAuthor();
		cout << "\nКоличество страниц: " << count_page;
		cout << endl;
	}
	int GetCount_page();
	void SetCount_page(int);
	void SetInf() override;

};
int Magazine::GetCount_page() {
	return this->count_page;
}
void Magazine::SetCount_page(int count) {
	this->count_page = count;
}
void Magazine::SetInf() {
	string a, b; int k;
	cout << "Введите название: "; cin >> a;
	this->SetName(a);
	cout << "Введите автора: "; cin >> b;
	this->SetAuthor(b);
	cout << "Введите количество страниц: "; cin >> k;
	this->count_page = k;
}
