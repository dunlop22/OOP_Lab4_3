#include "Container.h"

void Container::generate_id()
{
	this->id = 10000 + rand() % 90000;
}

void Container::get_parcel(Parcel parc)
{
	this->parce.push_back(parc);	//помещение посылки в список
	this->free_obem = this->free_obem - parc.obem;
	this->kol_vo_parcel = kol_vo_parcel + 1;
}

bool Container::check_free_obem(double obem)
{
	if (this->free_obem > obem)
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
	cout << "ID: " << this->id << "   ";
	for (int i = 0;i < parce.size();i++)
	{
		this->parce[i].print_information();
	}
}
