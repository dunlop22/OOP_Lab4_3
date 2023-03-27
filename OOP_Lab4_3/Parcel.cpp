#include "Parcel.h"

int Parcel::get_id()
{
	return (this->id);
}
//����� ���������� � �������
void Parcel::print_information()
{
	cout << this->id << " : " << this->town_sender << "-->" << this->town_recipient;
	if (this->danger == 1)
	{
		cout << " (!_DANGER_!) ";
	}
	cout << " (" << this->shirina << "x" << this->dlina << "x" << this->visota << ") " << this->weight << "��.   " << this->obem << " (�^3)\n";
}
//��������� ���������� ������ ��� ������� (����������� �������� ������������)
void Parcel::generate_id()
{
	//��������� ���������� 8-�� �������� ������ id
	this->id = 10000000 + rand() % 90000000;
	//�������� ���������������� ������� ������ (���???)
}
//��������� ������ ����������
string Parcel::get_town()
{
	return (this->town_recipient);
}

void Parcel::set_information()
{
	//��������� ��������������� 8-�������� ������ ������� (ID)
	generate_id();
	system("cls");
	cout << "���� ���������� � ����� �������\n\n���������� ����� ������� (id): " << this->id;

	cout << "\n\n������� ����� �����������: ";
	getline(cin, this->town_sender);

	string town[5] = { "�������", "������", "�����������", "�����������", "������ ��������" };
	int num_town;
	do
	{
		cout << "\n\n1) �������\n2) ������\n3) �����������\n4) �����������\n5) ������ ��������";
		cout << "\n\n�������� ����� ����������: ";
		num_town = _getch();
	} while (num_town < 49 || num_town > 55);
	this->town_recipient = town[num_town - 49];
	cout << num_town - 48 << " (" << this->town_recipient << ")";

	cout << "\n\n������� ������: ";
	//cin >> this->shirina;
	this->shirina = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)

	cout << "\n\n������� ������: ";
	//cin >> this->visota;
	this->visota = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)

	cout << "\n\n������� �����: ";
	//cin >> this->dlina;
	this->dlina = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)

	//this->obem = this->dlina * this->visota * this->shirina;
	this->obem = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)

	cout << "\n\n������� ��� (��.): ";
	//cin >> this->weight;
	this->weight = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)
	do
	{
		cout << "\n\n������� �������? (1 - ��, 2 - ���)";
		this->danger = _getch();
	} while (this->danger != 49 && this->danger != 50);
	this->danger = this->danger - 48;
	cout << "\n\n����� ������� ��� �������������";
	_getch();
}
/*
public: virtual void move(container * cont1)		//�� ��������
{
	cont1->get_parcel(id);
}
*/


