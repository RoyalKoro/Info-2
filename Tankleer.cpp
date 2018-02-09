#include "Tankleer.h"

Tankleer::Tankleer(Fahrzeug* pFahrzeug, Weg* pWeg)
	:FahrAusnahme(pFahrzeug, pWeg)
{
}


Tankleer::~Tankleer()
{
}

void Tankleer::vBearbeiten()
{
	p_pWeg->vTankleer(p_pFahrzeug);
}

