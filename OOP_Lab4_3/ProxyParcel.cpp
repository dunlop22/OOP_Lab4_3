#include "ProxyParcel.h"


void ProxyParcel::set_parcel(Parcel* parc)
{
    Parce = parc;
    cout << "this" << this->obem << "\n";
    cout << "parc" << parc->obem;
}

bool ProxyParcel::check_info()
{
    //cout << this->obem;
    _getch();
	if (this->danger == 1 && this->obem > 50)
	{
        cout << "\n\n�������������� ���� ������� � ����������� ������.\n������� ����� ������� ��� ���������� ����� ���������� � �������!\n";
        return false;
	}
	else
	{
        if (this->obem > 200)       //����� ������� ������, ��� ����� ����������
        {
            
            cout << "����� ������� ��������� ��������� ��������.\n������� ����� ������� ��� ���������� ����� ���������� � �������!\n";
            return false;
        }
        else
        {
            return true;
        }
	}
    
}

bool ProxyParcel::send_parcel()
{
    {
        int num = 10 + rand() % (256 - 10 + 1);
        if (num % 2 == 0)
        {
            return true;
        }
        else
        {
            cout << "\n\n���������� ��������� ������� � ������ ����� ����������.\n������� ����� ������� ��� ���������� ����� ���������� � �������!\n";
            return false;
        }
    }
}


