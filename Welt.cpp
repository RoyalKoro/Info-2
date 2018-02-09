#include "Welt.h"
#include "Fahrrad.h"
#include "PKW.h"
#include "SimuClient.h"

Welt::Welt()
{
}


Welt::~Welt()
{
}

void Welt::vEinlesen(istream & in)
{
	while (!in.eof())
	{
		string sKey = "";
		in >> sKey;
		if (sKey == "KREUZUNG")
		{
			Kreuzung* kr = new Kreuzung();
			in >> *kr;
			p_pKreuzungen.push_back(kr);
		}
		else if (sKey == "STRASSE")
		{
			string sNameQ, sNameZ, sNameW1, sNameW2;
			double dLaenge;
			int iLimit, iUeberholverbot;
			Weg::Begrenzung eLimit;
			bool bUeberholverbot;
			in >> sNameQ >> sNameZ >> sNameW1 >> sNameW2 >> dLaenge >> iLimit >> iUeberholverbot;

			switch (iLimit)
			{
			case 1: eLimit = Weg::Innerorts; break;
			case 2: eLimit = Weg::Landstrasse; break;
			case 3: eLimit = Weg::Autobahn; break;
			default: throw string("Geschwindigkeitsbegrenzung nicht lesbar"); break;
			}

			switch (iUeberholverbot)
			{
			case 0: bUeberholverbot = false; break;
			case 1: bUeberholverbot = true; break;
			default: throw string("Ueberholverbot nicht lesbar"); break;
			}
			Kreuzung* pQuell = dynamic_cast<Kreuzung*> (AktivesVO::ptObjekt(sNameQ));
			Kreuzung* pZiel = dynamic_cast<Kreuzung*> (AktivesVO::ptObjekt(sNameZ));
			if (pQuell == 0 || pZiel == 0)
			{
				cout << sNameQ << endl << sNameZ << endl;
				throw string("Verbinden der Kreuzungen nicht möglich");
			}
			pQuell->vVerbinde(sNameW1, sNameW2, pZiel, dLaenge, eLimit, bUeberholverbot);
		}
		else if (sKey == "PKW")
		{
			PKW* pkw = new PKW();
			string sNameS = "";
			double dStartzeitpunkt;
			in >> *pkw >> sNameS >> dStartzeitpunkt;
			Kreuzung* pStart = dynamic_cast<Kreuzung*> (AktivesVO::ptObjekt(sNameS));
			if (pStart == 0)
			{
				cout << sNameS << endl;
				throw string("PKW kann auf der Kreuzung nicht angenommen werden");
			}
			pStart->vAnnahme(pkw, dStartzeitpunkt);
		}
		else if (sKey == "FAHRRAD")
		{
			Fahrrad* frd = new Fahrrad();
			string sNameS;
			double dStartzeitpunkt;
			in >> *frd >> sNameS >> dStartzeitpunkt;
			Kreuzung* pStart = dynamic_cast<Kreuzung*> (AktivesVO::ptObjekt(sNameS));
			if (pStart == 0)
			{
				cout << sNameS << endl;
				throw string("Fahrrad kann auf der Kreuzung nicht angenommen werden");
			}
			pStart->vAnnahme(frd, dStartzeitpunkt);
		}
		else
		{
			throw string("unbekannter Datentyp");
		}
	}
}

void Welt::vEinlesenMitGrafik(istream & in)
{
	while (!in.eof())
	{
		string sKey = "";
		in >> sKey;
		if (sKey == "KREUZUNG")
		{
			Kreuzung* kr = new Kreuzung();
			int coordX, coordY;
			in >> *kr >> coordX >> coordY;
			bZeichneKreuzung(coordX, coordY);
			p_pKreuzungen.push_back(kr);
		}
		else if (sKey == "STRASSE")
		{
			string sNameQ, sNameZ, sNameW1, sNameW2;
			double dLaenge;
			int iLimit, iUeberholverbot, iAnzahl;
			Weg::Begrenzung eLimit;
			bool bUeberholverbot;
			in >> sNameQ >> sNameZ >> sNameW1 >> sNameW2 >> dLaenge >> iLimit >> iUeberholverbot >> iAnzahl;

			switch (iLimit)
			{
			case 1: eLimit = Weg::Innerorts; break;
			case 2: eLimit = Weg::Landstrasse; break;
			case 3: eLimit = Weg::Autobahn; break;
			default: throw string("Geschwindigkeitsbegrenzung nicht lesbar"); break;
			}

			switch (iUeberholverbot)
			{
			case 0: bUeberholverbot = false; break;
			case 1: bUeberholverbot = true; break;
			default: throw string("Ueberholverbot nicht lesbar"); break;
			}
			Kreuzung* pQuell = dynamic_cast<Kreuzung*> (AktivesVO::ptObjekt(sNameQ));
			Kreuzung* pZiel = dynamic_cast<Kreuzung*> (AktivesVO::ptObjekt(sNameZ));
			if (pQuell == 0 || pZiel == 0)
			{
				cout << sNameQ << endl << sNameZ << endl;
				throw string("Verbinden der Kreuzungen nicht möglich");
			}
			int* iCoords = new int[2 * iAnzahl];
			for (int i = 0; i < iAnzahl; i++)
			{
				in >> iCoords[2 * i] >> iCoords[2 * i + 1];
			}
			bZeichneStrasse(sNameW1, sNameW2, dLaenge, iAnzahl, iCoords);

			pQuell->vVerbinde(sNameW1, sNameW2, pZiel, dLaenge, eLimit, bUeberholverbot);
		}
		else if (sKey == "PKW")
		{
			PKW* pkw = new PKW();
			string sNameS = "";
			double dStartzeitpunkt;
			in >> *pkw >> sNameS >> dStartzeitpunkt;
			Kreuzung* pStart = dynamic_cast<Kreuzung*> (AktivesVO::ptObjekt(sNameS));
			if (pStart == 0)
			{
				cout << sNameS << endl;
				throw string("PKW kann auf der Kreuzung nicht angenommen werden");
			}
			pStart->vAnnahme(pkw, dStartzeitpunkt);
		}
		else if (sKey == "FAHRRAD")
		{
			Fahrrad* frd = new Fahrrad();
			string sNameS;
			double dStartzeitpunkt;
			in >> *frd >> sNameS >> dStartzeitpunkt;
			Kreuzung* pStart = dynamic_cast<Kreuzung*> (AktivesVO::ptObjekt(sNameS));
			if (pStart == 0)
			{
				cout << sNameS << endl;
				throw string("Fahrrad kann auf der Kreuzung nicht angenommen werden");
			}
			pStart->vAnnahme(frd, dStartzeitpunkt);
		}
		else
		{
			throw string("unbekannter Datentyp");
		}
	}
}


void Welt::vSimulation()
{
	for (list<Kreuzung*>::const_iterator it = p_pKreuzungen.begin(); it != p_pKreuzungen.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}

void Welt::vZeichnen()
{
	for (list<Kreuzung*>::const_iterator it = p_pKreuzungen.begin(); it != p_pKreuzungen.end(); it++)
	{
		(*it)->vZeichnen();
	}
}

ostream & Welt::ostreamAusgabe(ostream & out) const
{
	for (list<Kreuzung*>::const_iterator it = p_pKreuzungen.begin(); it != p_pKreuzungen.end(); it++)
	{
		out << **it << endl;
	}
	return out;
}

ostream & operator<<(ostream & out, const Welt & w)
{
	return w.ostreamAusgabe(out);
}
