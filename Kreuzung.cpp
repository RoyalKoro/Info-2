#include "Kreuzung.h"


Kreuzung::Kreuzung():AktivesVO()
{
}

Kreuzung::Kreuzung(const string sName, const double dTankstelle): AktivesVO(sName), p_dTankstelle(dTankstelle)
{
}

Kreuzung::~Kreuzung()
{
}

void Kreuzung::vVerbinde(const string sNameHin, const string sNameZurueck, Kreuzung * pKreuzung, const double dLaenge, const Weg::Begrenzung eLimit, const bool bUeberholverbot)
{
	Weg* pHin = new Weg(sNameHin, dLaenge, eLimit, bUeberholverbot);
	Weg* pZurueck = new Weg(sNameZurueck, dLaenge, eLimit, bUeberholverbot);

	pHin->setRueckweg(pZurueck);
	pHin->setKreuzung(pKreuzung);
	pZurueck->setKreuzung(this);
	p_pWege.push_back(pHin);
	pKreuzung->vNeuerWeg(pZurueck);
}

void Kreuzung::vTanken(Fahrzeug* pFahrzeug)
{
	if (p_dTankstelle > 0)
	{
		double dMenge = pFahrzeug->dTanken();
		p_dTankstelle -= dMenge;
		if (p_dTankstelle < 0)
		{
			p_dTankstelle = 0;
		}
	}
}

void Kreuzung::vAnnahme(Fahrzeug * pFahrzeug, double dStartzeit, Weg* pNeuerWeg)
{
	vTanken(pFahrzeug);
	if (pNeuerWeg == 0)
	{
		pNeuerWeg = p_pWege.front();
	}
	pNeuerWeg->vAnnahme(pFahrzeug, dStartzeit);
}

void Kreuzung::vAnnahme(Fahrzeug * pFahrzeug, Weg* pVorherigerWeg, Weg * pNeuerWeg)
{
	vTanken(pFahrzeug);
	if (pNeuerWeg == 0)
	{
		if (pVorherigerWeg == 0)
		{
			pNeuerWeg = p_pWege.front();
		}
		else
		{
			pNeuerWeg = ptZufaelligerWeg(pVorherigerWeg);
		}

	}
	pNeuerWeg->vAnnahme(pFahrzeug);
}

void Kreuzung::vNeuerWeg(Weg * pWeg)
{
	p_pWege.push_back(pWeg);
}

void Kreuzung::vZeichnen() const
{
	for (list<Weg*>::const_iterator it = p_pWege.begin(); it != p_pWege.end(); it++)
	{
		(*it)->vZeichnen();
	}
}

void Kreuzung::vAbfertigung()
{
	for (list<Weg*>::const_iterator it = p_pWege.begin(); it != p_pWege.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}

Weg* Kreuzung::ptZufaelligerWeg(Weg* pVorherigerWeg)
{
	if (p_pWege.size() == 1)
	{
		return p_pWege.front();
	}
	Weg* pWeg = pVorherigerWeg->getRueckweg();
	do
	{
		int iRnd = rand() % (p_pWege.size() + 1);
		list<Weg*>::iterator it = p_pWege.begin();
		for (int i = 0; i < iRnd; i++)
		{
			pWeg = (*it);
			it++;
		}
	} while (pWeg == pVorherigerWeg->getRueckweg());
	return pWeg;
}

ostream & Kreuzung::ostreamAusgabe(ostream& out) const
{
	AktivesVO::ostreamAusgabe(out)
		<< setprecision(2) << fixed
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(12) << p_dTankstelle
		<< resetiosflags(ios::right) << "Liter sind noch vorhanden" << endl;
		

	for (list<Weg*>::const_iterator it = p_pWege.begin(); it != p_pWege.end(); ++it)
	{
		out << *(*it) << endl;
	}
	out << endl;
	return out;
}

istream & Kreuzung::istreamEingabe(istream& in)
{
	AktivesVO::istreamEingabe(in);
	in >> p_dTankstelle;
	return in;
}

double Kreuzung::getTankstelle() const
{
	return p_dTankstelle;
}
