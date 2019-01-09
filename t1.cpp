/*
	VeMUlator project (Originally developed by MJaoune <mjaoune55@gmail.com>) and any files affiliated with it come with ABSOLUTELY NO WARRANTY under any circumstances; use at your own risk.
	Though it would be really appreciated if my name gets credited as "original developer" in case of redistribution.
*/

#include "t1.h"

VE_VMS_TIMER1::VE_VMS_TIMER1(VE_VMS_RAM *_ram, VE_VMS_INTERRUPTS *_intHandler, VE_VMS_AUDIO *_audio)
{
	ram = _ram;
	intHandler = _intHandler;
	audio = _audio;
	
	TRLStarted = 0;
    TRHStarted = 0;
}

VE_VMS_TIMER1::~VE_VMS_TIMER1()
{
}

void VE_VMS_TIMER1::runTimer()
{
	int TCNT_data = ram->readByte_RAW(T1CNT); //Timer control register

	bool TRLEnabled;
	bool TRHEnabled;
	bool TRLONGEnabled;

	TRLEnabled = (TCNT_data & 64) != 0;
	TRHEnabled = (TCNT_data & 128) != 0;
	TRLONGEnabled = (TCNT_data & 32) != 0;

	//Increase timers
	if(TRLEnabled) 
	{
		if(TRLStarted++ == 0) 
		{
			ram->T1RL_data = ram->readByte_RAW(T1LR);

			audio->setT1(ram->T1RL_data);
			//printf("Started T1RL\n");
		}

		ram->T1RL_data++;
		if(TRLONGEnabled && !TRHEnabled) ram->T1RL_data++; //Tcyc/2, equivalent to ram->T1RL_data += 2;

	} 
	else 
	{
		ram->T1RL_data = ram->readByte_RAW(T1LR);
		TRLStarted = 0;
	}

	audio->setEnabled(TRLEnabled & !TRLONGEnabled);



	if(TRHEnabled) 
	{
		TRHStarted++;
		if(!TRLONGEnabled) ram->T1RH_data++;
	} 
	else 
	{
		ram->T1RH_data = ram->readByte_RAW(T1HR);
		TRHStarted = 0;
	}

	//Overflow in ram->T1RL_data, 8-bit mode
	if(ram->T1RL_data > 255 && !TRLONGEnabled)
	{
		TCNT_data |= 2;

		if ((TCNT_data & 1) != 0) intHandler->setT1HLOV();

		//Stop timer
		//TCNT_data &= 0xBF;

		//Reload contents
		ram->T1RL_data = ram->readByte_RAW(T1LR);
	}
	//Overflow in ram->T1RL_data, 16-bit mode
	else if(ram->T1RL_data > 255 && TRLONGEnabled)
	{
		ram->T1RH_data++;

		//Reload contents
		ram->T1RL_data = ram->readByte_RAW(T0LR);
	}

	//Overflow in ram->T1RH_data, 8-bit mode
	if(ram->T1RH_data > 255 && !TRLONGEnabled)
	{
		TCNT_data |= 8;

		if ((TCNT_data & 4) != 0) intHandler->setT1HLOV();

		//Stop timer
		//TCNT_data &= 0x7F;

		//Reload contents
		ram->T1RH_data = ram->readByte_RAW(T1HR);
	}

	//Overflow in 16-bit mode
	else if(ram->T1RH_data > 255 && TRLONGEnabled)
	{
		TCNT_data |= 2;
		TCNT_data |= 8;

		if ((TCNT_data & 4) != 0) intHandler->setT1HLOV();

		//Stop both timers
		//TCNT_data &= 0x1F;

		//Reload contents
		ram->T1RL_data = ram->readByte_RAW(T1LR);
		ram->T1RH_data = ram->readByte_RAW(T1HR);
	}


	//ram->writeByte_RAW(ram->T1LR, ram->T1RL_data);
	//ram->writeByte_RAW(ram->T1HR, ram->T1RH_data);
	ram->writeByte_RAW(T1CNT, TCNT_data);
}
