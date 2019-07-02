#ifndef __ADF4351_H__
#define __ADF4351_H__

#include <Arduino.h>

class ADF4351{
	public:
    ADF4351(int SCLK, int DATA, int LE, int CE);
    void begin(void);

    void WriteRegister(long regData);

  private:
    int _data, _sclk, _le, _ce;
    long _regData;
};

#endif
