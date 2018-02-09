#pragma once
#include "FzgVerhalten.h"
class FzgParken :
	public FzgVerhalten//Legt das Verhalten für parkende Fahrzeuge fest
{
public:
	FzgParken(Weg* pWeg, double dStartzeitpunkt);//Konstrukor, Zeiger auf den Weg auf dem das Fahrzeug sich befindet und den Zeitpunkt zu dem das Fahrzeug los fährt
	virtual ~FzgParken();//Destruktor
	virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit) const;//Gibt die maximale möglich Strecke auf dem aktuellen Weg für das Fahrzeug zurück
private:
	double p_dStartzeitpunkt;//Zeitpunkt zu dem das Fahrzeug los fährt
};
