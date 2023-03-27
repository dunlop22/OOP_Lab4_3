#pragma once
#include "parcel.h"
#include "container.h"
#include <conio.h>
#include <vector>

class solver
{
	//посылка, передвинься в контейнер
public:
	void parcel_to_container(vector<container> container_mass, vector<parcel> parcel_mass, int num_parcel, int* num_container);
};



