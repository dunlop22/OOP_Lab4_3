#pragma once 
#include <string>
#include "Transport.h"
#include "Parcel.h"
#include <vector>

using namespace std;

class Container
{
	//���������
	//�������
	//��� ������� ������

	int id;	//���������� �����

	
	string town;	//����������� ����������
	vector<Parcel> parce;

protected:
	int kol_vo_parcel = 0;		//����� ���������� ������� � ����������
	double free_obem;			//���������� ���������� ����� � ����������

public:
	virtual void generate_id();
	virtual void get_parcel(Parcel parc);
	virtual bool check_free_obem(double obem);
	virtual string get_town();
	virtual void print_information_c();
	/*
	//���������
	//�������
	//��� ������� ������

	int id;	//���������� �����
	int* spisok;	//������ � ����������� �������� �������
	string town;	//����������� ����������
	//parcel* parce = new parcel();
	parcel* parce;

	public:
		double free_obem;
		int kol_vo_parcel = 0;

	public: virtual void generate_id()
	{
		this->id = 10000 + rand() % 90000;
	}

	public: virtual void get_parcel(parcel parc)
	{
		//����� ���� ��� �������, ����������� ����������������� �������
		//����� ������� ������ �������


		//���������� ������� ������������� �������
		parcel* parce_temp = parce;       //�������� ���������� ������� ��� �����
		parce = new parcel[_msize(parce) / sizeof(parcel) + 1]; //�������� ������������� ������� � ������ ���������
		for (int i = 0; i < _msize(parce) / sizeof(parcel) - 1; i++)
		{
			parce[i] = parce_temp[i];
		}

		delete[] parce_temp;    //������� ������

		parce[_msize(parce) / sizeof(parcel) - 1] = parc;


		kol_vo_parcel = kol_vo_parcel + 1;
		free_obem = free_obem - parc.obem;
	}



	public: virtual void go_to_transport(transport * transp1)
	{
		transp1->drive();
	}

	public: virtual void set_town(string town_)	//��������� ������ ����������
	{
		this->town = town_;
	}

	public: virtual string get_town()	//��������� ������ ����������
	{
		return (this->town);
	}

public: virtual int check_free_obem(double obem)	//�������� ������� ���������� �����
{
	if (free_obem - obem > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/

};

class danger_cont : public Container	//��������� � ������� ����������
{
public:
	danger_cont()
	{
		Container::kol_vo_parcel = 0;	//� ����� ������������
	}
};


class small_cont : public Container		//��������� ���������
{
public:
	small_cont()
	{
		kol_vo_parcel = 0;
		Container::free_obem = 100;
	}
};

class big_cont : public Container	//������� ���������
{
public:
	big_cont()
	{

		this->kol_vo_parcel = 0;
		Container::free_obem = 200;
	}

};
//��������� ������� ������������ ��������

//��� �������� ���������� �� ��������������� ��� �� ����������� ��������, �� ������� �� ����� �������������