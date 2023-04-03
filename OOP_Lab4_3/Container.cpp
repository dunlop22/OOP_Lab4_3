#include "Container.h"

void Container::generate_id()
{
	this->id = 10000 + rand() % 90000;
}

int Container::get_id()
{
	return this->id;
}

void Container::get_parcel(Parcel parc)
{
	this->town = parc.get_town();
	this->parce.push_back(parc);	//помещение посылки в список
	this->free_obem = this->free_obem - parc.obem;
	this->kol_vo_parcel = kol_vo_parcel + 1;
}

bool Container::check_free_obem(double obem)
{
	if (this->free_obem >= obem)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Container::get_town()
{
	return (this->town);
}

void Container::print_information_c()
{
	cout << "ID: " << this->id << "  ";
	for (int i = 0;i < parce.size();i++)
	{
		if (i != 0)
		{
			cout << "           ";
		}
		this->parce[i].print_information();
	}
	cout << "Свободное место в контейнере: " << this->free_obem << "м^3\n\n";
}

vector<Parcel> Container::get_inf_parcel()
{
	return this->parce;
}
