#pragma once
#include "AktivesVO.h"
#include "Weg.h"
#include "Fahrzeug.h"

class Kreuzung :
	public AktivesVO
{
public:
	Kreuzung();
	Kreuzung(const string sName, const double dTankstelle = 0);
	virtual ~Kreuzung();
	void vVerbinde(const string sNameHin, const string sNameZurueck, Kreuzung* pKreuzung, const double dLaenge, const Weg::Begrenzung eLimit, const bool bUeberholverbot);
	void vTanken(Fahrzeug* pFahrzeug);
	void vAnnahme(Fahrzeug* pFahrzeug, double dStartzeit, Weg* pNeuerWeg = 0);
	void vAnnahme(Fahrzeug* pFahrzeug, Weg* pVorherigerWeg = 0, Weg* pWeg = 0);
	void vNeuerWeg(Weg* pWeg);
	void vZeichnen() const;
	virtual void vAbfertigung();
	Weg* ptZufaelligerWeg(Weg* pWeg);
	virtual ostream& ostreamAusgabe(ostream& out) const;
	virtual istream& istreamEingabe(istream& in);
	double getTankstelle() const;
private:
	double p_dTankstelle;
	list<Weg*> p_pWege;
};

