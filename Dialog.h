#pragma once
#include"Vector.h"
#include<iostream>

using namespace std;

void menu();

const int cmCreate = 1;
const int cmAdd = 2;
const int cmDel = 3;
const int cmExit = 4;
const int cmShow = 5;
const int cmShowName = 6;
const int evNothing = 0;
const int evMessage = 100;

class Event {
public:
	int what;
	int command;
};


class Dialog : public Vector {
	int EndState = 0;
public:
	void HandleEvent(Event&);
	void GetEvent(Event&);
	void ClearEvent(Event&);
	void Execute();
	bool Valid();
	void EndExec();
};

void Dialog::HandleEvent(Event& event) {
	int k;
	if (event.what == evMessage) {
		switch (event.command) {
		case cmAdd:
			Add(); ClearEvent(event); break;
		case cmDel:
			del(); ClearEvent(event); break;
		case cmShow:
			show(); ClearEvent(event); break;
		case cmShowName:
			showName(); ClearEvent(event); break;
		case cmExit:
			EndExec(); ClearEvent(event); break;
		case cmCreate:
			cout << "Введите количество элементов: "; cin >> this->size;
			obj = new Print * [size];
			ClearEvent(event);
			break;
		}
	}
}
void Dialog::GetEvent(Event& event) {
	string commands = "+-szqm";
	char c;
	system("pause");
	system("cls");
	menu();
	cout << "Введите команду > "; cin >> c;
	if (commands.find(c) >= 0) {
		event.what = evMessage;
		switch (c) {
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmShowName; break;
		case 'q': event.command = cmExit; break;
		case 'm': event.command = cmCreate; break;
		}
	}
	else event.what = evNothing;
}
void Dialog::ClearEvent(Event& a) {
	a.what = evNothing;
}
void Dialog::Execute() {
	Event event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (Valid());
}
bool Dialog::Valid() {
	return EndState == 0;
}
void Dialog::EndExec() {
	EndState = 1;
}
void menu() {
	cout << "Создать группу(m)";
	cout << "\nДобавить элемент в группу(+)";
	cout << "\nУдалить элемент из группы(-)";
	cout << "\nВывести информацию об элементах группы(s)";
	cout << "\nВывести информацию о названиях всех элементов группы(z)";
	cout << "\nКонец работы(q)";
	cout << endl;
}
