#pragma once
#include "FzgVerhalten.h"
class FzgFahren :
	public FzgVerhalten//Legt das Verhalten für fahrende Fahrzeuge fest
{
public:
	FzgFahren(Weg* pWeg);//Konstruktor, speichert einen Zeiger auf einen Weg
	virtual ~FzgFahren();//Destruktor
	virtual double dStrecke(Fahrzeug * pFahrzeug, double dZeit) const;//Gibt die maximale möglich Strecke auf dem aktuellen Weg für das Fahrzeug zurück
};