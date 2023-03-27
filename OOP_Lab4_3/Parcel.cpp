#include "Parcel.h"

int Parcel::get_id()
{
	return (this->id);
}
//вывод информации о посылке
void Parcel::print_information()
{
	cout << this->id << " : " << this->town_sender << "-->" << this->town_recipient;
	if (this->danger == 1)
	{
		cout << " (!_DANGER_!) ";
	}
	cout << " (" << this->shirina << "x" << this->dlina << "x" << this->visota << ") " << this->weight << "кг.   " << this->obem << " (м^3)\n";
}
//генерация случайного номера для посылки (реализовать проверку уникальности)
void Parcel::generate_id()
{
	//генерация случайного 8-ми значного номера id
	this->id = 10000000 + rand() % 90000000;
	//проверка индивидуальности данного номера (как???)
}
//получение города получателя
string Parcel::get_town()
{
	return (this->town_recipient);
}

void Parcel::set_information()
{
	//генерация индивидуального 8-значного номера посылки (ID)
	generate_id();
	system("cls");
	cout << "Ввод информации о новой посылке\n\nУникальный номер посылки (id): " << this->id;

	cout << "\n\nВведите город отправителя: ";
	getline(cin, this->town_sender);

	string town[5] = { "Барнаул", "Москва", "Новосибирск", "Владивосток", "Нижний Новгород" };
	int num_town;
	do
	{
		cout << "\n\n1) Барнаул\n2) Москва\n3) Новосибирск\n4) Владивосток\n5) Нижний Новгород";
		cout << "\n\nВыберите город получателя: ";
		num_town = _getch();
	} while (num_town < 49 || num_town > 55);
	this->town_recipient = town[num_town - 49];
	cout << num_town - 48 << " (" << this->town_recipient << ")";

	cout << "\n\nВведите ширину: ";
	//cin >> this->shirina;
	this->shirina = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)

	cout << "\n\nВведите высоту: ";
	//cin >> this->visota;
	this->visota = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)

	cout << "\n\nВведите длину: ";
	//cin >> this->dlina;
	this->dlina = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)

	//this->obem = this->dlina * this->visota * this->shirina;
	this->obem = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)

	cout << "\n\nВведите вес (кг.): ";
	//cin >> this->weight;
	this->weight = 8 + rand() % (54 - 8 + 1);		//генерация случайного значения объема (для теста)
	do
	{
		cout << "\n\nПосылка опасная? (1 - ДА, 2 - НЕТ)";
		this->danger = _getch();
	} while (this->danger != 49 && this->danger != 50);
	this->danger = this->danger - 48;
	cout << "\n\nЛюбая клавиша для подтверждения";
	_getch();
}
/*
public: virtual void move(container * cont1)		//от решателя
{
	cont1->get_parcel(id);
}
*/


