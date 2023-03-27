#pragma once
#include "Parcel.h"
#include "Container.h"
#include <conio.h>
#include <vector>

class Solver
{
	//посылка, передвинься в контейнер
public:
	void parcel_to_container(vector<Container> &container_mass, vector<Parcel> parcel_mass, int num_parcel);
};



