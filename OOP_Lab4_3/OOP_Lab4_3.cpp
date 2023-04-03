#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include "Container.h"
#include "Parcel.h"
#include "Solver.h"
#include <vector>
#include "ProxyParcel.h"
#include <cstdlib>;

using namespace std;

int main()
{
    std::vector<Parcel> parcel_spisok;
    std::vector<Container> container_spisok;

    srand(time(NULL));  //��� ��������� ��������� id
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    int num_parcel = 0;     //����� ���������� �������
    int func;   //���� ��� ������ ������ ����
    do
    {
        do           //������� ����
        {
            system("cls");
            cout << "1) �������� ��������� ����� �������\n2) ��������� �������\n3) �������� ���������� �� ��������� ��������\nESC) �����\n\n����� ���������� ������� �� ������ ������: " << parcel_spisok.size() << "\n����� ���������� ����������� �� ������ ������: " << container_spisok.size() << "\n";
            func = _getch();
        } while (func != 49 && func != 50 && func != 51 && func != 27);

        if (func == 49)
        {
            int new_parcel; ///���������� ����� �������
            do
            {
                system("cls");
                cout << "������� ���������� ����� �������: ";
                cin >> new_parcel;
            } while (new_parcel < 0);
            cin.get();
           
            for (int i = 0; i < new_parcel; i++)
            {
                Parcel parce_temp;
                ProxyParcel Prox;
                
                do
                {
                    do
                    {
                        parce_temp.set_information();
                        Prox.set_parcel(&parce_temp);
                        if (!(Prox.check_info()))
                        {
                            cout << "\n\n�������������� ���� ������� � ����������� ������.\n������� ����� ������� ��� ���������� ����� ���������� � �������!\n";
                            _getch();
                        }
                    } while (!(Prox.check_info()));        //�����������  ��������. ������� ���� �� ����� ���� ������ 50���.��.

                    if (Prox.send_parcel())
                    {
                        cout << "\n\n���������� ��������� ������� � ������ ����� ����������.\n������� ����� ������� ��� ���������� ����� ���������� � �������!\n";
                        _getch();
                    }
                } while (!(Prox.send_parcel()));

                parcel_spisok.push_back(parce_temp);
                
            }
            num_parcel = num_parcel + new_parcel;       //����� ���������� ������� (������ � ������ ��� ������������)
        }

        else if (func == 50)        //����������� �������
        {
            if (parcel_spisok.size() > 0)         //������� ������� ��� �����������
            {
                system("cls");
                //������������� ������� �� �����������
                Solver solv;
                solv.parcel_to_container(container_spisok, parcel_spisok, num_parcel);


                //����� ����������� � �� �������
                for (int i = 0;i < container_spisok.size();i++)
                {
                    cout << "��������� �: " << i + 1 << "\n";
                    container_spisok[i].print_information_c();
                }

                
                cout << "***   ***   ***   ***   ***   ***\n����� ���������� �����������: " << container_spisok.size();
                cout << "\n\n������� ����� ������� ��� �����������";
                _getch();
                
                for (int i = 0; i < parcel_spisok.size(); i++)
                {
                    parcel_spisok.clear();
                    parcel_spisok.shrink_to_fit();

                }
                
                string town[5] = {"�������", "������", "�����������", "�����������", "������ ��������"};
                cout << "\n\n\n����������� ������� � ������...\n";

                for (int i = 0; i < 5; i++)
                {
                    for (int k = 0; k < container_spisok.size(); k++)
                    {
                        if (container_spisok[k].get_town() == town[i])
                        {
                            cout << "\n__" << town[i] << "__" << "\n";
                            cout << "��������� (ID): " << container_spisok[k].get_id();
                            cout << "\n�������:\n\n";
                            for (int n = 0; n < (container_spisok[k].get_inf_parcel()).size(); n++)
                            {
                                (container_spisok[k].get_inf_parcel())[n].print_information();
                                cout << "\n";
                            }
                            for (int j = 0; j < 5; j++)
                            {
                                Sleep(500);
                                cout << "....";
                            }
                            cout << "-->" << container_spisok[k].get_town() << "\n��������� ���������!\n";
                        }
                    }
                }

                container_spisok.clear();
                container_spisok.shrink_to_fit();
                num_parcel = 0;

                cout << "\n\n������� ����� ������� ��� ������ � ������� ����";
                _getch();
                //�������� ������� � ���������
            }
            else        //������� ��� ����������� ���
            {
                system("cls");
                cout << "��� ������� ��� �����������!\n\n��� ����������� ������� ����� �������";
                _getch();
            }
        }

        else if (func == 51)        //�������� ���������� � ������������ ��������
        {
            system("cls");

            if (parcel_spisok.size() > 0)
            {
                //����� ���������� � ��������
                for (int i = 0; i < parcel_spisok.size(); i++)
                {
                    parcel_spisok[i].print_information();
                }
            }
            else
            {
                cout << "��� ������� ��� ��������� ����������!";
            }
            cout << "\n\n��� ����������� ������� ����� �������\n";
            _getch();
        }
    } while (func != 27);

    //drive...-> ���� ����������� -> �������� �����


}
