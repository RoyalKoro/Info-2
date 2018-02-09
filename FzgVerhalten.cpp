#include "FzgVerhalten.h"

FzgVerhalten::FzgVerhalten(Weg* pWeg):p_pWeg(pWeg)
{
}

FzgVerhalten::~FzgVerhalten()
{
}

double FzgVerhalten::dLimit() const
{
	return p_pWeg->getLimit();
}