#pragma once
#include "Parcel.h"

class ProxyParcel :
    public Parcel
{
private:
    Parcel* Parce;

public:
    void set_parcel(Parcel* parc);  //��������� �������� �������
    bool check_info();  //�������� �������� ���������
    bool send_parcel();   //��������� ���������� �������. ����� ���������� ������� ��� ���     � ������������ 1/3
    

};

