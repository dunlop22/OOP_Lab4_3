#pragma once
#include "Parcel.h"

class ProxyParcel :
    public Parcel
{
private:
    Parcel* Parce;

public:
    void set_parcel(Parcel* parc);  //установка значения объекта
    bool check_info();  //проверка вводимой инфомации
    bool send_parcel();   //генерация случайного события. будет отправлена посылка или нет     с вероятностью 1/3
    

};

