#pragma once
#include "FahrAusnahme.h"
class Streckenende :public FahrAusnahme //Legt das Verhalten am Streckenende fest
{
public:
	Streckenende(Fahrzeug* pFahrzeug, Weg* pWeg);//Konstruktor, weist einen Zeiger auf ein Fahrzeug und einen Weg zu
	virtual ~Streckenende();//Destruktor
	virtual void vBearbeiten();//Bearbeiungsfunktion der Fahrausnahme
};

