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

    void set_parcel(Parcel* parc);  //��������� �������� �������
    bool check_info();  //�������� �������� ���������
    bool send_parcel();   //��������� ���������� �������. ����� ���������� ������� ��� ���     � ������������ 1/3
    

};

