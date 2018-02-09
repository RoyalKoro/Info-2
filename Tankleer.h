#pragma once
#include "FahrAusnahme.h"
class Tankleer :public FahrAusnahme
{
public:
	Tankleer(Fahrzeug* pFahrzeug, Weg* pWeg);
	virtual ~Tankleer();
	virtual void vBearbeiten();//Bearbeiungsfunktion der Fahrausnahme
};

