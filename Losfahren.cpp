#include "Losfahren.h"



Losfahren::Losfahren(Fahrzeug * pFahrzeug, Weg * pWeg)
	:FahrAusnahme(pFahrzeug, pWeg)
{
}

Losfahren::~Losfahren()
{
}

void Losfahren::vBearbeiten()
{
	cout << "Losfahren" << endl << "Fahrzeug:" << endl << *p_pFahrzeug << endl << "Weg:" << endl << *p_pWeg << endl;
	p_pWeg->vAbgabe(p_pFahrzeug);//Loescht das parkende Fahrzeug vom Weg
	p_pWeg->vAnnahme(p_pFahrzeug);//Fuegt das Fahrzeug dann als fahrendes Fahrzeug wieder hinzu

}

