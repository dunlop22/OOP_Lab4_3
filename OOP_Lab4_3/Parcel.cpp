#include "Parcel.h"

int parcel::get_id()
{
	return (this->id);
}
//����� ���������� � �������
void parcel::print_information()
{
	cout << this->id << " : " << this->town_sender << "-->" << this->town_recipient << "  (" << this->shirina << "x" << this->dlina << "x" << this->visota << ") " << this->weight << "��.\n";
}
//��������� ���������� ������ ��� ������� (����������� �������� ������������)
void parcel::generate_id()
{
	//��������� ���������� 8-�� �������� ������ id
	this->id = 10000000 + rand() % 90000000;
	//�������� ���������������� ������� ������ (���???)
}
//��������� ������ ����������
string parcel::get_town()
{
	return (this->town_recipient);
}

void parcel::set_information()
{
	//��������� ��������������� 8-�������� ������ ������� (ID)
	while (cin.get() != '\n');	//������� ������ �����
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

	cout << "\n\n������� ������: ";
	//cin >> this->visota;

	cout << "\n\n������� �����: ";
	//cin >> this->dlina;

	this->obem = this->dlina * this->visota * this->shirina;

	cout << "\n\n������� ��� (��.): ";
	//cin >> this->weight;
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


