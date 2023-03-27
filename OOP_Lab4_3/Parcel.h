#pragma once
#define _CRT_SECURE_NO_WARNINGS
//#include "Container.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Parcel
{
public:
	int danger;
	double obem;

private:
	int id;
	string town_sender;
	string town_recipient;
	double shirina;
	double visota;
	double dlina;
	double weight;

	//int num_is_container;
	//public virtual void move

public:
	int get_id();

	void print_information();

	//генерация случайного номера для посылки (реализовать проверку уникальности)
	void generate_id();

	//получение города получателя
	string get_town();


	void set_information();
};

