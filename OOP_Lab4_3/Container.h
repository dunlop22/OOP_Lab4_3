#pragma once 
#include <string>
#include "transport.h"
#include "parcel.h"
#include <vector>

using namespace std;

class container
{
	//���������
	//�������
	//��� ������� ������

	int id;	//���������� �����

	double free_obem;			//���������� ���������� ����� � ����������
	string town;	//����������� ����������
	vector<parcel> parce;

protected:
	int kol_vo_parcel = 0;		//����� ���������� ������� � ����������

public:
	virtual void generate_id();
	virtual void get_parcel(parcel parc);
	virtual bool check_free_obem(double obem);
	virtual string get_town();
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

class danger_cont : public container	//��������� � ������� ����������
{
public:
	danger_cont()
	{
		container::kol_vo_parcel = 1;	//� ����� ������������
	}
};


class small_cont : public container		//��������� ���������
{
public:
	small_cont()
	{
		kol_vo_parcel = 3;
	}
};

class big_cont : public container	//������� ���������
{
public:
	big_cont()
	{

		this->kol_vo_parcel = 5;
	}

};
//��������� ������� ������������ ��������

//��� �������� ���������� �� ��������������� ��� �� ����������� ��������, �� ������� �� ����� �������������