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

    srand(time(NULL));  //для генерации случайных id
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    int num_parcel = 0;     //общее количество посылок
    int func;   //флаг для выбора пункта меню
    do
    {
        do           //главное меню
        {
            system("cls");
            cout << "1) Добавить несколько новых посылок\n2) Отправить посылки\n3) Просмотр информации об имеющихся посылках\nESC) Выход\n\nОбщее количество посылок на данный момент: " << parcel_spisok.size() << "\nОбщее количество контейнеров на данный момент: " << container_spisok.size() << "\n";
            func = _getch();
        } while (func != 49 && func != 50 && func != 51 && func != 27);

        if (func == 49)
        {
            int new_parcel; ///количество новых посылок
            do
            {
                system("cls");
                cout << "Введите количество новых посылок: ";
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
                            cout << "\n\nНесоответствие типа посылки и занимаемого объема.\nНажмите любую клавишу для повторного ввода информации о посылке!\n";
                            _getch();
                        }
                    } while (!(Prox.check_info()));        //минимальная  проверка. Опасный груз не может быть больше 50усл.ед.

                    if (Prox.send_parcel())
                    {
                        cout << "\n\nНевозможно доставить посылку в данный пункт назначения.\nНажмите любую клавишу для повторного ввода информации о посылке!\n";
                        _getch();
                    }
                } while (!(Prox.send_parcel()));

                parcel_spisok.push_back(parce_temp);
                
            }
            num_parcel = num_parcel + new_parcel;       //общее количество посылок (вместе с только что добавленными)
        }

        else if (func == 50)        //перемещение посылок
        {
            if (parcel_spisok.size() > 0)         //имеются посылки для отправления
            {
                system("cls");
                //распределение посылок по контейнерам
                Solver solv;
                solv.parcel_to_container(container_spisok, parcel_spisok, num_parcel);


                //вывод контейнеров и их посылок
                for (int i = 0;i < container_spisok.size();i++)
                {
                    cout << "Контейнер №: " << i + 1 << "\n";
                    container_spisok[i].print_information_c();
                }

                
                cout << "***   ***   ***   ***   ***   ***\nОбщее количество контейнеров: " << container_spisok.size();
                cout << "\n\nНажмите любую клавишу для продолжения";
                _getch();
                
                for (int i = 0; i < parcel_spisok.size(); i++)
                {
                    parcel_spisok.clear();
                    parcel_spisok.shrink_to_fit();

                }
                
                string town[5] = {"Барнаул", "Москва", "Новосибирск", "Владивосток", "Нижний Новгород"};
                cout << "\n\n\nПеремещение посылок в города...\n";

                for (int i = 0; i < 5; i++)
                {
                    for (int k = 0; k < container_spisok.size(); k++)
                    {
                        if (container_spisok[k].get_town() == town[i])
                        {
                            cout << "\n__" << town[i] << "__" << "\n";
                            cout << "Контейнер (ID): " << container_spisok[k].get_id();
                            cout << "\nПосылки:\n\n";
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
                            cout << "-->" << container_spisok[k].get_town() << "\nКонтейнер доставлен!\n";
                        }
                    }
                }

                container_spisok.clear();
                container_spisok.shrink_to_fit();
                num_parcel = 0;

                cout << "\n\nНажмите любую клавишу для выхода в главное меню";
                _getch();
                //удаление массива с посылками
            }
            else        //посылок для отправления нет
            {
                system("cls");
                cout << "Нет посылок для отправления!\n\nДля продолжения нажмите любую клавишу";
                _getch();
            }
        }

        else if (func == 51)        //просмотр информации о существующих посылках
        {
            system("cls");

            if (parcel_spisok.size() > 0)
            {
                //вывод информации о посылках
                for (int i = 0; i < parcel_spisok.size(); i++)
                {
                    parcel_spisok[i].print_information();
                }
            }
            else
            {
                cout << "Нет посылок для просмотра информации!";
            }
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();
        }
    } while (func != 27);

    //drive...-> меню перемещения -> конечный пункт


}
