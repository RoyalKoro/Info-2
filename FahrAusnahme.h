#pragma once
#include "Fahrzeug.h"
#include "Weg.h"
class FahrAusnahme
{
public:
	FahrAusnahme(Fahrzeug* pFahrzeug, Weg* pWeg);//Konstruktor, mit Zeiger auf ein Fahrzeug und einen Weg
	virtual ~FahrAusnahme();//Destruktor
	virtual void vBearbeiten() = 0;//Bearbeitungsfunktion, rein virtuell, wird in Unerklassen überschrieben
protected:
	Fahrzeug* p_pFahrzeug;//Zeiger auf ein Fahrzeug
	Weg* p_pWeg;//Zeiger auf den Weg, auf welchem sich das Fahrzeug befindet

};
