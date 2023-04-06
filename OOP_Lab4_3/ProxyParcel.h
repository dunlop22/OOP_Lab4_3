#pragma once
#include "Parcel.h"
#include "Big_Cont.h"

class ProxyParcel :
    public Parcel
{
private:
    Parcel* Parce;

public:
    ProxyParcel(Parcel* parc) :Parcel()
    { Parce = parc; };

    void set_parcel(Parcel* parc);  //установка значения объекта
    bool check_info();  //проверка вводимой инфомации
    bool send_parcel();   //генерация случайного события. будет отправлена посылка или нет     с вероятностью 1/3
    

};

