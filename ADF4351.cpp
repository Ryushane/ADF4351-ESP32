#include "ADF4351.h"

// Constructor function; initializes communication pinouts
ADF4351::ADF4351(int SCLK, int DATA, int LE, int CE){
	_sclk = SCLK;
	_data=DATA;
	_le=LE;
	_ce=CE;
}

void ADF4351::begin(void){
	pinMode(_sclk, OUTPUT);
	pinMode(_data, OUTPUT);
	pinMode(_le, OUTPUT);
	pinMode(_ce, OUTPUT);
	
	// initialize
	digitalWrite(_sclk, LOW);
	digitalWrite(_data, LOW);
	digitalWrite(_le, LOW);
	digitalWrite(_ce, HIGH);
}


// write data into register
void ADF4351::WriteRegister(long regData){
	digitalWrite(_le, LOW);
	_regData = regData;

	for(int i=0; i<32; i++)
	{
		if(((_regData<<i)&0x80000000)==0x80000000)
		{
			digitalWrite(_data,1);
			
		}
		else
		{
			digitalWrite(_data,0) ;
			
		}

		digitalWrite(_sclk, HIGH);
		delay(1);
		digitalWrite(_sclk, LOW);
	}
	
	// load data into register
	digitalWrite(_le, HIGH);
	delay(1);
	digitalWrite(_le, LOW);
}