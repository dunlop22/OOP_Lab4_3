#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "container.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class parcel
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
	//public virtaul void move

public:
	int get_id();

	void print_information();

	//��������� ���������� ������ ��� ������� (����������� �������� ������������)
	void generate_id();

	//��������� ������ ����������
	string get_town();


	void set_information();
};

