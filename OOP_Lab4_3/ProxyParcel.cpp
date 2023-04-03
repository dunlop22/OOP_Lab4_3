#include "ProxyParcel.h"


void ProxyParcel::set_parcel(Parcel* parc)
{
    Parce = parc;
}

bool ProxyParcel::check_info()
{
	if (this->danger == 1 && this->obem > 50)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ProxyParcel::send_parcel()
{
    {
        int num = 10 + rand() % (256 - 10 + 1);
        if (num % 3 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


