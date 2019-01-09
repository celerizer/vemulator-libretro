/*
	VeMUlator project (Originally developed by MJaoune <mjaoune55@gmail.com>) and any files affiliated with it come with ABSOLUTELY NO WARRANTY under any circumstances; use at your own risk.
	Though it would be really appreciated if my name gets credited as "original developer" in case of redistribution.
*/

#include "interrupts.h"

VE_VMS_INTERRUPTS::VE_VMS_INTERRUPTS()
{
	Reset = 0;
    INT0 = 0;
    INT1 = 0;
    INT2 = 0;
    INT3 = 0;
    T0HOV = 0;
    T1HLOV = 0;
    SIO0 = 0;
    SIO1 = 0;
    RFB = 0;
    P3_data = 0;
    P3_Taken = true;
}

VE_VMS_INTERRUPTS::~VE_VMS_INTERRUPTS()
{
}

//Setters
void VE_VMS_INTERRUPTS::setReset(){
	Reset = 1;
}
void VE_VMS_INTERRUPTS::clearReset(){
	Reset = 0;
}

void VE_VMS_INTERRUPTS::setINT0(){
	INT0 = 1;
}
void VE_VMS_INTERRUPTS::clearINT0(){
	INT0 = 0;
}

void VE_VMS_INTERRUPTS::setINT1(){
	INT1 = 1;
}
void VE_VMS_INTERRUPTS::clearINT1(){
	INT1 = 0;
}

void VE_VMS_INTERRUPTS::setINT2(){
	INT2 = 1;
}
void VE_VMS_INTERRUPTS::clearINT2(){
	INT2 = 0;
}

void VE_VMS_INTERRUPTS::setINT3(){
	INT3 = 1;
}
void VE_VMS_INTERRUPTS::clearINT3(){
	INT3 = 0;
}

void VE_VMS_INTERRUPTS::setT0HOV(){
	T0HOV = 1;
}
void VE_VMS_INTERRUPTS::clearT0HOV(){
	T0HOV = 0;
}

void VE_VMS_INTERRUPTS::setT1HLOV(){
	T1HLOV = 1;
}
void VE_VMS_INTERRUPTS::clearT1HLOV(){
	T1HLOV = 0;
}

void VE_VMS_INTERRUPTS::setSIO0(){
	SIO0 = 1;
}
void VE_VMS_INTERRUPTS::clearSIO0(){
	SIO0 = 0;
}

void VE_VMS_INTERRUPTS::setSIO1(){
	SIO1 = 1;
}
void VE_VMS_INTERRUPTS::clearSIO1(){
	SIO1 = 0;
}

void VE_VMS_INTERRUPTS::setRFB(){
	RFB = 1;
}
void VE_VMS_INTERRUPTS::clearRFB(){
	RFB = 0;
}

void VE_VMS_INTERRUPTS::setP3(){
	P3_data = 1;
}
void VE_VMS_INTERRUPTS::clearP3(){
	P3_data = 0;
}

//Getters
byte VE_VMS_INTERRUPTS::getReset()
{
	return Reset;
}

byte VE_VMS_INTERRUPTS::getINT0()
{
	return  INT0;
}

byte VE_VMS_INTERRUPTS::getINT1()
{
	return INT1;
}

byte VE_VMS_INTERRUPTS::getINT2()
{
	return INT2;
}

byte VE_VMS_INTERRUPTS::getINT3()
{
	return  INT3;
}

byte VE_VMS_INTERRUPTS::getT0HOV()
{
	return T0HOV;
}

byte VE_VMS_INTERRUPTS::getT1HLOV()
{
	return T1HLOV;
}

byte VE_VMS_INTERRUPTS::getSIO0()
{
	return  SIO0;
}

byte VE_VMS_INTERRUPTS::getSIO1()
{
	return SIO1;
}

byte VE_VMS_INTERRUPTS::getRFB()
{
	return RFB;
}

byte VE_VMS_INTERRUPTS::getP3()
{
	return P3_data;
}
