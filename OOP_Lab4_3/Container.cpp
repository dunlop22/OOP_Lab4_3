#include "Container.h"

void container::generate_id()
{
	this->id = 10000 + rand() % 90000;
}

void container::get_parcel(parcel parc)
{
	this->parce.push_back(parc);	//��������� ������� � ������
	this->kol_vo_parcel = kol_vo_parcel + 1;
}

bool container::check_free_obem(double obem)
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

string container::get_town()
{
	return (this->town);
}