#include "AktivesVO.h"

int AktivesVO::p_iMaxID = 0;
map<string, AktivesVO*> AktivesVO::p_mVO;

AktivesVO::AktivesVO()
{
	vInitialisierung();
}


AktivesVO::~AktivesVO()
{
	p_mVO.erase(p_sName);
}

AktivesVO::AktivesVO(const string sName)
{
	vInitialisierung();
	p_sName = sName;
	if (p_mVO.find(p_sName) != p_mVO.end())
	{
		throw string("Objekteintrag existiert bereits");
	}
	p_mVO[p_sName] = this;
}

void AktivesVO::vInitialisierung()
{
	p_iID = ++p_iMaxID;
	p_dZeit = 0;
	p_sName = "";
}

void AktivesVO::vAusgabe() const
{
	cout << setprecision(2) << fixed	//Auf 2 Nachkommastellen runden 
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(2) << p_iID << " "
		<< resetiosflags(ios::right) << setiosflags(ios::left) << setw(10) << p_sName << ":";

}

ostream & AktivesVO::ostreamAusgabe(ostream & out) const
{
	out << setprecision(2) << fixed//Auf 2 Nachkommastellen runden
		<< resetiosflags(ios::left) << setiosflags(ios::right) << setw(2) << p_iID << " "
		<< resetiosflags(ios::right) << setiosflags(ios::left) << setw(10) << p_sName << ":";
	return out;
}

istream& AktivesVO::istreamEingabe(istream& in)
{
	//if (p_sName != "")
	//{
	//	throw string("Objekt exisiert bereits");
	//}
	in >> p_sName;
	if (p_mVO.find(p_sName) != p_mVO.end())
	{
		throw string("Objekteintrag existiert bereits");
	}
	p_mVO[p_sName] = this;
	return in;
}

AktivesVO & AktivesVO::operator=(const AktivesVO & AVO)
{
	p_sName = AVO.p_sName;
	p_dZeit = AVO.p_dZeit;
	if (p_mVO.find(p_sName) != p_mVO.end())
	{
		throw string("Objekteintrag existiert bereits");
	}
	p_mVO[p_sName] = this;
	return *this;

}

string AktivesVO::getName() const
{
	return p_sName;
}

AktivesVO * AktivesVO::ptObjekt(string sName)
{
	map<string, AktivesVO*>::iterator it = p_mVO.find(sName);
	if (it == p_mVO.end())
	{
		cout << sName << endl;
		throw string("Objekteintrag existiert nicht");
	}
	else
	{
		return it->second;
	}
}

ostream& operator<<(ostream& out, const AktivesVO& AVO)
{
	return AVO.ostreamAusgabe(out);
}

istream & operator >> (istream& in, AktivesVO & AVO)
{
	return AVO.istreamEingabe(in);
}
