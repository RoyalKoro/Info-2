#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "AktivesVO.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include "stdlib.h"
#include "Kreuzung.h" 
#include "Welt.h"
#include <vector>



double dGlobaleZeit = 0.0;

void vAufabe_1()
{
	string sName = "";//String Variable für die Eingabe durch cin des Namens
					  /*Fahrzeug* Fzg1 = new Fahrzeug();

					  cout << "Geben sie den Namen des Fahrzeugs ein:" << endl;
					  cin >> sName;
					  Fahrzeug* Fzg2 = new Fahrzeug(sName);
					  Fahrzeug Fz3();
					  Fahrzeug Fz4("Peter");
					  */

	Fahrzeug* pFahrzeug[4];//Feld mit Zeigern auf ein Objekt der Klasse Fahrzeug
	for (int i = 0; i <= 3; i++)//erstellt 4 Fahrzeuge mit manueller Eingabe für die Namen
	{
		cout << "Geben sie den Namen des Fahrzeugs ein:" << endl;
		cin >> sName;
		pFahrzeug[i] = new Fahrzeug(sName);
	}

	cout << "ID Name      : MaxKmh    Gesamtstrecke" << endl;//Überschrift
	cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	for (dGlobaleZeit = 0; dGlobaleZeit <= 3; dGlobaleZeit += 0.2)//Zeitspanne 3std, alle 0.2std wird abgfertigt
	{
		cout << "GlobaleZeit = " << dGlobaleZeit << endl;
		for (int i = 0; i <= 3; i++)//Rufe für jedes erstelltes Fahrzeug im Feld pFahrzeug auf 
		{

			pFahrzeug[i]->vAbfertigung();
			pFahrzeug[i]->vAusgabe();
			cout << endl;
		}
	}

	for (int i = 0; i <= 3; i++)//Löschen der dynamisch erstellten Objekte
	{
		delete pFahrzeug[i];
	}
}

void vAufgabe_1_deb()
{
	string sName = "";//String Variable für die Eingabe durch cin des Namens
	Fahrzeug* pFahrzeug[4];//Feld mit Zeigern auf ein Objekt der Klasse Fahrzeug
	for (int i = 0; i <= 3; i++)//erstellt 4 Fahrzeuge mit manueller Eingabe für die Namen
	{
		cout << "Geben sie den Namen des Fahrzeugs ein:" << endl;
		cin >> sName;
		pFahrzeug[i] = new Fahrzeug(sName);
	}

	for (int i = 0; i <= 3; i++)//Gibt die Fahrzeuge im Feld aus
	{
		pFahrzeug[i]->vAusgabe();
		cout << endl;
	}

	pFahrzeug[2] = 0;//Weißt dem Feld 2 die Speicheradresse 0 zu, Fehler

	for (int i = 0; i <= 3; i++)//Gibt die Fahrzeuge im Feld aus
	{
		pFahrzeug[i]->vAusgabe();
		cout << endl;
	}

	for (int i = 0; i <= 3; i++)//Löschen der dynamisch erstellten Objekte
	{
		delete pFahrzeug[i];
	}
}

void vAufgabe_2()
{
	int iAnzahlPKW;//Variable zur Speicherung der Anzahl der PKW's die erstellt werden sollen
	int iAnzahlFrd;//Variable zur Speicherung der Anzahl der Fahrräder die erstellt werden sollen
	cout << "Wie viele PKW's sollen erzeugt werden?" << endl;
	cin >> iAnzahlPKW;
	cout << "Wie viele Fahrräder sollen erzeugt werden?" << endl;
	cin >> iAnzahlFrd;
	string sName = "";//String Variable für die Eingabe durch cin des Namens
	double dMaxGeschwindigkeit = 0, dVerbrauch = 0;//Variaben für die Eingabe fer Maxgeschwindigkeit und des Verbrauchs
	vector<Fahrzeug*> vecFzg;//Vektor der stl, prinzipiell wie ein Feld, braucht aber nicht zwingend eine feste größe bei der Deaklaration, dynamische Länge

	for (int i = 0; i < iAnzahlPKW; i++)//Es werden so viele PKW's erstellt wie vorher durch die Eingabe definiert wurde und fragt nach Namen, Maxgeschwindigkeit und Verbrauch
	{
		cout << "Geben sie den Namen, MaxKmh und Verbrauch des PKW ein:" << endl;
		cin >> sName,
			cin >> dMaxGeschwindigkeit;
		cin >> dVerbrauch;
		PKW* TempPKW = new PKW(sName, dMaxGeschwindigkeit, dVerbrauch);//Temporäre Variable zur zwischenSpeicherung bevor das Objekt dem Vector hinzugefügt wird
		vecFzg.push_back(TempPKW);//Fügt das Objekt an letzter Stelle des Vektors ein
	}

	for (int i = 0; i < iAnzahlFrd; i++)//Es werden so viele PKW's erstellt wie vorher durch die Eingabe definiert wurde und fragt nach Namen und Maxgeschwindigkeit
	{
		cout << "Geben sie den Namen und MaxKmh des Fahrrads ein:" << endl;
		cin >> sName,
			cin >> dMaxGeschwindigkeit;
		Fahrrad* TempFrd = new Fahrrad(sName, dMaxGeschwindigkeit);//Temporäre Variable zur zwischenSpeicherung bevor das Objekt dem Vector hinzugefügt wird
		vecFzg.push_back(TempFrd);//Fügt das Objekt an letzter Stelle des Vektors ein
	}

	cout << "ID Name      :    MaxKmh      Kmh      Gesamtstrecke   Verbrauch   Tankinhalt" << endl;//Überschrift
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	for (dGlobaleZeit = 0; dGlobaleZeit <= 5; dGlobaleZeit += 0.5)//Zeitspanne 5std, alle 0.5std wird abgfertigt
	{
		cout << "GlobaleZeit = " << dGlobaleZeit << endl;
		for (vector<Fahrzeug*>::iterator it = vecFzg.begin(); it != vecFzg.end(); it++)//Durchläuft den vector vom ersten bis zum Letzen Objekt
		{


			if (dGlobaleZeit >= 2.99 && dGlobaleZeit <= 3.01)//GlobaleZeit = 3 nicht möglich da Fließkommawerte nicht genau verglichen werden können
			{
				(*it)->dTanken();
			}
			(*it)->vAbfertigung();
			(*it)->vAusgabe();
			cout << endl;
		}


	}
	for (vector<Fahrzeug*>::iterator it = vecFzg.begin(); it != vecFzg.end(); it++)//Löscht alle Elemente im Vector
	{
		delete *it;
	}

	/*
	string sName = "";
	double dMaxGeschwindigkeit = 0, dVerbrauch = 0, dTankvolumen = 55;
	PKW* pPKW[2];
	Fahrrad* Frd = new Fahrrad("Marc", 25);
	for (int i = 0; i <= 1; i++)
	{
	cout << "Geben sie den Namen, MaxKmh und Verbrauch des PKW ein:" << endl;
	cin >> sName,
	cin >> dMaxGeschwindigkeit;
	cin >> dVerbrauch;
	pPKW[i] = new PKW(sName, dMaxGeschwindigkeit, dVerbrauch);
	}

	cout << "ID Name      :    MaxKmh      Kmh      Gesamtstrecke   Verbrauch   Tankinhalt" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	for (dGlobaleZeit = 0; dGlobaleZeit <= 3; dGlobaleZeit += 0.2)
	{
	cout << "GlobaleZeit = " << dGlobaleZeit << endl;
	for (int i = 0; i <= 1; i++)
	{

	pPKW[i]->vAbfertigung();
	pPKW[i]->vAusgabe();
	cout << endl;
	}
	Frd->vAbfertigung();
	Frd->vAusgabe();
	cout << endl;
	}

	for (int i = 0; i <= 1; i++)
	{
	delete pPKW[i];
	}
	*/
}

void vAufgabe_3()
{
	PKW PKW1("PKW1", 100, 10);//Statische Erzeugung 
	PKW PKW2("PKW2", 200, 15);
	Fahrrad Frd1("Frd1", 25);
	PKW* PKW3 = new PKW("PKW3", 150, 10);//Dynamische Erzeugung


	cout << "ID Name      :    MaxKmh      Kmh      Gesamtstrecke   Verbrauch   Tankinhalt" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;//Überschrift
	for (dGlobaleZeit = 0; dGlobaleZeit <= 5; dGlobaleZeit += 0.5)//Zeitspanne 5std, alle 0.5std wird abgfertigt
	{


		PKW1.vAbfertigung();//Fertigt alle PKW's und Fahrräder ab
		PKW2.vAbfertigung();
		PKW3->vAbfertigung();
		Frd1.vAbfertigung();
		cout << "GlobaleZeit = " << dGlobaleZeit << endl;
		cout << PKW1 << endl;//Ausgabeoperator Test
		cout << PKW2 << endl;
		cout << *PKW3 << endl;
		cout << Frd1 << endl;
		if (dGlobaleZeit >= 2.99 && dGlobaleZeit <= 3.01)
		{
			PKW1.dTanken();
			PKW2.dTanken();
			PKW3->dTanken();
		}

	}
	if (PKW1 < PKW2)//Vergleichsoperator Test
	{
		cout << "PKW1 hat weniger Strecke zurückgelegt als PKW2" << endl;
	}
	else
	{
		cout << "PKW1 hat nicht weniger Strecke zurückgelegt als PKW2" << endl;
	}
	PKW2 = *PKW3;// Zuweisungsoperator Test
	cout << PKW2 << endl << *PKW3 << endl;
}

void vAufgabe_4()
{
	Weg* weg1 = new Weg("Weg1", 500, Weg::Autobahn);
	PKW* pkw1 = new PKW("PKW1", 50, 10);
	PKW* pkw2 = new PKW("PKW2", 150, 10);
	PKW* pkw3 = new PKW("PKW3", 100, 10);
	PKW* pkw4 = new PKW("PKW4", 125, 15);
	weg1->vAnnahme(pkw1);
	weg1->vAnnahme(pkw2, 1);//Parkendes Fahrzeg, Startzeit 1
	weg1->vAnnahme(pkw3);
	weg1->vAnnahme(pkw4, 2);//Parkendes Fahzeug, Startzeit 2
	cout << *weg1 << endl;
	cout << "ID Name      :     MaxKmh      Kmh        Gstrecke     Astrecke    Verbrauch    Tankinhalt" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;//Überschrift
	for (dGlobaleZeit = 0; dGlobaleZeit <= 5; dGlobaleZeit += 0.3)//Zeitspanne 5std, alle 0.5std wird abgfertigt
	{
		cout << "GlobaleZeit = " << dGlobaleZeit << endl;
		weg1->vAbfertigung();
		cout << *pkw1 << endl;
		cout << *pkw2 << endl;
		cout << *pkw3 << endl;
		cout << *pkw4 << endl;
	}
	delete weg1;
	delete pkw1;
	delete pkw2;
	delete pkw3;
	delete pkw4;
}

void vAufgabe_5()
{
	Weg* Rueckweg = new Weg("Rueckweg", 500, Weg::Autobahn);
	Weg* Hinweg = new Weg("Hinweg", 500, Weg::Landstrasse);
	PKW* pkw1 = new PKW("PKW1", 50, 10);
	PKW* pkw2 = new PKW("PKW2", 150, 10);
	PKW* pkw3 = new PKW("PKW3", 100, 10);
	PKW* pkw4 = new PKW("PKW4", 125, 15);
	Hinweg->vAnnahme(pkw1);
	Hinweg->vAnnahme(pkw2, 1);//Parkendes Fahrzeug wird angenommen, Startzeitpunkt 1
	Rueckweg->vAnnahme(pkw3);
	Rueckweg->vAnnahme(pkw4, 3);//Parkendes Fahrzeug wird angenommen, Startzeitpunkt 3
	cout << *Hinweg << endl;
	cout << *Rueckweg << endl;


	if (!bInitialisiereGrafik(800, 500))//Initialisierung des Grafikservers
	{
		cout << "Server geht nicht";
	}
	int iKoordinaten[] = { 700, 250, 100, 250 };//Koordinaten der Strasse
	bZeichneStrasse(Hinweg->getName(), Rueckweg->getName(), (int)Hinweg->getLaenge(), 2, iKoordinaten);//Zeichnet die Strasse mit hin und Rueckweg
	cout << "ID Name      :     MaxKmh      Kmh        Gstrecke     Astrecke    Verbrauch    Tankinhalt" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;//Überschrift
	for (dGlobaleZeit = 0; dGlobaleZeit <= 10; dGlobaleZeit += 0.3)//Zeitspanne 5std, alle 0.5std wird abgfertigt
	{
		cout << "GlobaleZeit = " << dGlobaleZeit << endl;
		Hinweg->vAbfertigung();
		Rueckweg->vAbfertigung();
		vSetzeZeit(dGlobaleZeit);//Gibt die Globale Zeit in der Grafikausgabe aus
		pkw1->vZeichnen(Hinweg);
		pkw2->vZeichnen(Hinweg);
		pkw3->vZeichnen(Rueckweg);
		pkw4->vZeichnen(Rueckweg);

		cout << *pkw1 << endl;
		cout << *pkw2 << endl;
		cout << *pkw3 << endl;
		cout << *pkw4 << endl;
		if (dGlobaleZeit > 5.9 && dGlobaleZeit < 6.01)//Tanken zum Zeitpunkt 6
		{
			pkw1->dTanken();
			pkw2->dTanken();
			pkw3->dTanken();
			pkw4->dTanken();
		}
		vSleep(500);
	}
	//bLoescheFahrzeug(pkw1->getName());
	//bLoescheFahrzeug(pkw2->getName());
	//bLoescheFahrzeug(pkw3->getName());
	//bLoescheFahrzeug(pkw4->getName());
	//vBeendeGrafik();

	delete Hinweg;
	delete Rueckweg;
	delete pkw1;
	delete pkw2;
	delete pkw3;
	delete pkw4;
}

void vAufgabe_6()
{
	Weg* Rueckweg = new Weg("Rueckweg", 500, Weg::Autobahn);
	Weg* Hinweg = new Weg("Hinweg", 500, Weg::Landstrasse);
	PKW* pkw1 = new PKW("PKW1", 50, 10);
	PKW* pkw2 = new PKW("PKW2", 150, 10);
	PKW* pkw3 = new PKW("PKW3", 100, 10);
	PKW* pkw4 = new PKW("PKW4", 125, 15);
	Hinweg->vAnnahme(pkw1);
	Hinweg->vAnnahme(pkw2, 1);
	Rueckweg->vAnnahme(pkw3);
	Rueckweg->vAnnahme(pkw4, 3);
	cout << *Hinweg << endl;
	cout << *Rueckweg << endl;


	if (!bInitialisiereGrafik(800, 500))
	{
		cout << "Server geht nicht";
	}
	int iKoordinaten[] = { 700, 250, 100, 250 };
	bZeichneStrasse(Hinweg->getName(), Rueckweg->getName(), (int)Hinweg->getLaenge(), 2, iKoordinaten);
	cout << "ID Name      :     MaxKmh      Kmh        Gstrecke     Astrecke    Verbrauch    Tankinhalt" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;//Überschrift
	for (dGlobaleZeit = 0; dGlobaleZeit <= 20; dGlobaleZeit += 0.25)//Zeitspanne 10Std, alle 0.25std wird abgfertigt
	{
		cout << "GlobaleZeit = " << dGlobaleZeit << endl;
		Hinweg->vAbfertigung();
		Rueckweg->vAbfertigung();
		vSetzeZeit(dGlobaleZeit);//Gibt die Globale Zeit in der Grafikausgabe aus
		pkw1->vZeichnen(Hinweg);
		pkw2->vZeichnen(Hinweg);
		pkw3->vZeichnen(Rueckweg);
		pkw4->vZeichnen(Rueckweg);

		/*cout << *pkw1 << endl;
		cout << *pkw2 << endl;
		cout << *pkw3 << endl;
		cout << *pkw4 << endl;*/
		if (dGlobaleZeit > 5.99 && dGlobaleZeit < 6.01)//Tanken zum Zeitpunkt 6
		{
			pkw1->dTanken();
			pkw2->dTanken();
			pkw3->dTanken();
			pkw4->dTanken();
		}
		vSleep(500);
	}
	cout << *Hinweg << endl << *Rueckweg << endl;
	//bLoescheFahrzeug(pkw1->getName());
	//bLoescheFahrzeug(pkw2->getName());
	//bLoescheFahrzeug(pkw3->getName());
	//bLoescheFahrzeug(pkw4->getName());
	//vBeendeGrafik();

	delete Hinweg;
	delete Rueckweg;
	delete pkw1;
	delete pkw2;
	delete pkw3;
	delete pkw4;
}

void vAufgabe_6a()
{
	LazyListe<int> Liste;//LazyListe mit int Werten

	for (int i = 0; i < 10; i++)
	{
		Liste.push_back(rand() % 11);//fuegt 10 zufaellige Werte zwischen 0 und 10 am Ende der Liste ein
	}
	Liste.vAktualisieren();

	for (LazyListe<int>::iterator it = Liste.begin(); it != Liste.end(); it++)
	{
		cout << *it << ";";//Ausgabe der Liste
	}
	cout << endl;

	for (LazyListe<int>::iterator it = Liste.begin(); it != Liste.end(); it++)
	{
		if ((*it) > 5)
		{
			Liste.erase(it);//Loescht alle Werte ueber 5
		}
	}

	for (LazyListe<int>::iterator it = Liste.begin(); it != Liste.end(); it++)
	{
		cout << *it << ";";//Ausgabe der Liste
	}
	cout << endl;
	Liste.vAktualisieren();
	for (LazyListe<int>::iterator it = Liste.begin(); it != Liste.end(); it++)
	{
		cout << *it << ";";//Ausgabe der Liste
	}
	cout << endl;
	Liste.push_front(11);//Fuegt den Wert 11 am Anfang der Liste ein
	Liste.push_back(11);//Fuegt den Wert 11 am Ende der Liste ein
	for (LazyListe<int>::iterator it = Liste.begin(); it != Liste.end(); it++)
	{
		cout << *it << ";";//Ausgabe der Liste
	}
	cout << endl;
	Liste.vAktualisieren();
	for (LazyListe<int>::iterator it = Liste.begin(); it != Liste.end(); it++)
	{
		cout << *it << ";";//Ausgabe der Liste
	}
	cout << endl;
} // Block 1 + Block 2



void vAufgabe_7()
{
	Weg* Rueckweg = new Weg("Rueckweg", 500, Weg::Autobahn);
	Weg* Hinweg = new Weg("Hinweg", 500, Weg::Landstrasse);
	PKW* pkw1 = new PKW("PKW1", 100, 10);
	PKW* pkw2 = new PKW("PKW2", 50, 10);
	PKW* pkw3 = new PKW("PKW3", 50, 5);
	Fahrrad* frd1 = new Fahrrad("FRD1", 25);
	Hinweg->vAnnahme(pkw1);
	Hinweg->vAnnahme(frd1);
	cout << *Hinweg << endl;
	cout << *Rueckweg << endl;


	if (!bInitialisiereGrafik(800, 500))
	{
		cout << "Server geht nicht";
	}

	int iKoordinaten[] = { 700, 250, 100, 250 };
	bZeichneStrasse(Hinweg->getName(), Rueckweg->getName(), (int)Hinweg->getLaenge(), 2, iKoordinaten);
	cout << "ID Name      :     MaxKmh      Kmh        Gstrecke     Astrecke    Verbrauch    Tankinhalt" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;//Überschrift


	for (dGlobaleZeit = 0; dGlobaleZeit <= 50; dGlobaleZeit += 0.25)//Zeitspanne 10Std, alle 0.25std wird abgfertigt
	{
		//cout << "GlobaleZeit = " << dGlobaleZeit << endl;
		Hinweg->vAbfertigung();
		Rueckweg->vAbfertigung();
		vSetzeZeit(dGlobaleZeit);//Gibt die Globale Zeit in der Grafikausgabe aus
		pkw1->vZeichnen(Hinweg);
		pkw2->vZeichnen(Hinweg);
		pkw3->vZeichnen(Hinweg);
		frd1->vZeichnen(Hinweg);

		/*cout << *pkw1 << endl;
		cout << *pkw2 << endl;*/
		if (dGlobaleZeit > 9.99 && dGlobaleZeit < 10.01)
		{
			Hinweg->vAnnahme(pkw2, 15);
		}
		if (dGlobaleZeit > 19.99 && dGlobaleZeit < 20.01)
		{
			pkw2->dTanken();
		}
		if (dGlobaleZeit > 24.99 && dGlobaleZeit < 25.01)
		{
			Hinweg->vAnnahme(pkw3);
			pkw1->dTanken();
		}
		//vSleep(10);
	}
	cout << *Hinweg << endl << *Rueckweg << endl;
	//vBeendeGrafik();

	delete Hinweg;
	delete Rueckweg;
	delete pkw1;
	delete pkw2;
	delete pkw3;
}

void vAufgabe_8()
{
	Kreuzung* kr1 = new Kreuzung("kr1");
	Kreuzung *kr2 = new Kreuzung("kr2", 1000);
	Kreuzung *kr3 = new Kreuzung("kr3");
	Kreuzung *kr4 = new Kreuzung("kr4");

	kr1->vVerbinde("W12", "W21", kr2, 40, Weg::Innerorts, true);
	kr2->vVerbinde("W23a", "W32a", kr3, 115, Weg::Autobahn, false);
	kr2->vVerbinde("W23b", "W32b", kr3, 40, Weg::Innerorts, true);
	kr2->vVerbinde("W24", "W42", kr4, 55, Weg::Innerorts, true);
	kr3->vVerbinde("W34", "W43", kr4, 40, Weg::Autobahn, false);
	kr4->vVerbinde("W44a", "W44b", kr4, 40, Weg::Landstrasse, false);

	PKW* pkw1 = new PKW("PKW1", 100, 10);
	PKW* pkw2 = new PKW("PKW2", 50, 10);
	PKW* pkw3 = new PKW("PKW3", 50, 5);
	Fahrrad* frd1 = new Fahrrad("FRD1", 25);

	kr2->vAnnahme(pkw1);
	kr2->vAnnahme(frd1);
	kr2->vAnnahme(pkw2);
	kr2->vAnnahme(pkw3);


	if (!bInitialisiereGrafik(1000, 700))
	{
		cout << "Server geht nicht" << endl;
	}

	int iCoords1[] = { 680,  40, 680, 300 };
	int iCoords2[] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
	int iCoords3[] = { 680, 300, 680, 570 };
	int iCoords4[] = { 680, 300, 320, 300 };
	int iCoords5[] = { 680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	int iCoords6[] = { 320, 300, 320, 150, 200,  60,  80,  90,  70, 250, 170, 300, 320, 300 };

	bZeichneStrasse("W12", "W21", 40, 2, iCoords1);
	bZeichneStrasse("W23a", "W32a", 115, 6, iCoords2);
	bZeichneStrasse("W23b", "W32b", 40, 2, iCoords3);
	bZeichneStrasse("W24", "W42", 55, 2, iCoords4);
	bZeichneStrasse("W34", "W43", 85, 5, iCoords5);
	bZeichneStrasse("W44a", "W44b", 130, 7, iCoords6);
	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300);

	for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += 0.25)
	{
		cout << "dGlobaleZeit" << dGlobaleZeit << endl << endl;
		vSetzeZeit(dGlobaleZeit);
		kr1->vAbfertigung();
		kr2->vAbfertigung();
		kr3->vAbfertigung();
		kr4->vAbfertigung();
		kr1->vZeichnen();
		kr2->vZeichnen();
		kr3->vZeichnen();
		kr4->vZeichnen();
		cout << *kr1 << endl << *kr2 << endl << *kr3 << endl << *kr4 << endl;
	}
	//vBeendeGrafik();
}

void vAufgabe_9_1()
{
	ifstream infile("VO.dat");
	if (!infile.good())
	{
		cout << "Datei konnte nicht geoeffnet werden" << endl;
		return;
	}

	try
	{
		PKW* pkw1 = new PKW();
		Fahrrad* frd1 = new Fahrrad();
		Kreuzung* kr1 = new Kreuzung();
		infile >> *pkw1 >> *frd1 >> *kr1;
		cout << "ID Name      :     MaxKmh      Kmh        Gstrecke     Astrecke    Verbrauch    Tankinhalt" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;//Überschrift
		cout << *pkw1 << endl << *frd1 << endl << *kr1 << endl;

		string sName = "";
		cout << "Namenseingabe" << endl;
		cin >> sName;
		AktivesVO* pAVO = AktivesVO::ptObjekt(sName);
		cout << *pAVO << endl;

		
	}
	catch (string &error)
	{
		cout << error << endl;
	}
}

void vAufgabe_9_5()
{
	ifstream infile("Simu.dat");
	if (!infile.good())
	{
		cout << "Datei konnte nicht geoeffnet werden" << endl;
		return;
	}
	Welt* Welt1 = new Welt();
	try
	{
		Welt1->vEinlesen(infile);
	}
	catch (string& e)
	{
		cout << e << endl;
	}
	cout << *Welt1 << endl;
	for (dGlobaleZeit = 0; dGlobaleZeit <= 100; dGlobaleZeit += 0.25)
	{
		cout << "++++++++++++++++++++++++++++++++++++++++++" << endl << dGlobaleZeit << endl;
		Welt1->vSimulation();
	}
	cout << *Welt1 << endl;
}

void vAufgabe_9_6()
{
	ifstream infile("SimuDisplay.dat");
	if (!infile.good())
	{
		cout << "Datei konnte nicht geoeffnet werden" << endl;
		return;
	}
	if (!bInitialisiereGrafik(1000, 1000))
	{
		cout << "Server geht nicht" << endl;
	}
	Welt* Welt1 = new Welt();
	try
	{
		Welt1->vEinlesenMitGrafik(infile);
	}
	catch (string& e)
	{
		cout << e << endl;
	}
	cout << *Welt1 << endl;
	for (dGlobaleZeit = 0; dGlobaleZeit <= 10; dGlobaleZeit += 0.25)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "++++++++++++++++++++++++++++++++++++++++++" << endl << dGlobaleZeit << endl;
		Welt1->vSimulation();
		Welt1->vZeichnen();
		vSleep(10);
	}
	//vBeendeGrafik();
	cout << *Welt1 << endl;
}




int main()
{
	//vAufgabe_1();
	//system("pause");
	//vAufgabe_1_deb();
	//system("pause");
	//vAufgabe_2();
	//system("pause");
	//vAufgabe_3();
	//system("pause");
	/*vAufgabe_4();
	system("pause");*/
	//vAufgabe_5();
	//system("pause");
	/*vAufgabe_6();
	system("pause");*/
	/*vAufgabe_6a();
	system("pause");*/ //Block 1 + Block 2



	//vAufgabe_7();
	//system("pause");

	//vAufgabe_8();
	//system("pause");

	//vAufgabe_9_1();
	//system("pause");

	//vAufgabe_9_5();
	//system("pause");
	
	vAufgabe_9_6();
	//system("pause");

}

