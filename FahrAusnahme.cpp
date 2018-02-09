#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"

//Standardkonstruktor mit Fahrzeug und zugehörigem Weg
FahrAusnahme::FahrAusnahme(Fahrzeug * pFahrzeug, Weg * pWeg) : p_pFahrzeug(pFahrzeug), p_pWeg(pWeg)
{
}

FahrAusnahme::~FahrAusnahme()
{
}
