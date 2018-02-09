#pragma once
#include "FahrAusnahme.h"
class Losfahren ://Legt das Verhalten eines losfahrenden Fahrzeugs fest
public FahrAusnahme
{
	public:
		Losfahren(Fahrzeug* pFahrzeug, Weg* pWeg);//Konstruktor, weist einen Zeiger auf ein Fahrzeug und einen Weg zu
		virtual ~Losfahren();//Destruktor
		virtual void vBearbeiten();//Bearbeitungsfunktion der Fahrausnahme
};

