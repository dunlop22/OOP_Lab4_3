#include "Container.h"

void Container::generate_id()
{
	this->id = 10000 + rand() % 90000;
}

void Container::get_parcel(parcel parc)
{
	this->parce.push_back(parc);	//помещение посылки в список
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
