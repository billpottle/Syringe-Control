// printercontroller.h: interface for the printercontroller class.
//
//////////////////////////////////////////////////////////////////////

#include "nidaqex.h"

#if !defined(AFX_PRINTERCONTROLLER_H__CB11FFB3_3282_11D6_A450_00105A0CA6B4__INCLUDED_)
#define AFX_PRINTERCONTROLLER_H__CB11FFB3_3282_11D6_A450_00105A0CA6B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class printercontroller  
{
public:
	printercontroller();
	
void	run();
void setValues(i16, i16, i16, i16,i16);
};

#endif // !defined(AFX_PRINTERCONTROLLER_H__CB11FFB3_3282_11D6_A450_00105A0CA6B4__INCLUDED_)
