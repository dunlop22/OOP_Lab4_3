#include "Solver.h"
//�������, ����������� � ���������
void solver::parcel_to_container(vector<container> container_mass, vector<parcel> parcel_mass, int num_parcel, int* num_container)
{
	for (int i = 0; i < num_parcel; i++)
	{

		if (parcel_mass[i].danger == 1)
		{
			//������������ �������� ������ ����������, ��� ����������� �� ���������� ���������
			/*
			container** container_spisok_temp = container_mass;       //�������� ���������� ������� ��� �����
			container_mass = new container*[*num_container + 1]; //�������� ������������� ������� � ������ ���������
			for (int i = 0; i < *num_container; i++)
			{
				container_mass[i] = container_spisok_temp[i];
			}

			delete[] container_spisok_temp;    //������� ������
			*/
			* num_container = *num_container + 1;

			container* container_temp = new danger_cont();

			container_temp->generate_id();
			container_temp->get_parcel(parcel_mass[i]);
			container_mass.push_back(*container_temp);

			cout << parcel_mass[i].danger;		//����� ������ ����������
			_getch();

		}
		else
		{
			//�������� ������� ���������� ����� � ������������ �����������
			for (int j = 0; j < *num_container; j++)
			{
				if (container_mass[j].check_free_obem(parcel_mass[i].obem) > 0)
				{
					//�������� ������ �����������
					if (container_mass[j].get_town() == parcel_mass[i].get_town())
					{
						//container_mass[j]->set_parcel_minus();
						container_mass[j].get_parcel(parcel_mass[i]);	//���������� 
					}
					else
					{
						goto new_cont;		//�������� ������ ����������
					}

				}
				else    //�������� ������ ����������
				{
				new_cont:
					container* container_temp = new big_cont();

					container_temp->generate_id();
					container_temp->get_parcel(parcel_mass[i]);
					container_mass.push_back(*container_temp);
				}
			}

		}
	}
}




