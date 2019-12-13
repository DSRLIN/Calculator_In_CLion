#include <utility>

#include "allHeaders.h"

fluidItems::fluidItems()
{
	this->strItemName = "NULL";
	this->nLengthofSC = 0;
	this->nLengthofFC = 0;
	this->aSolidCrafttable = nullptr;
	this->aFluidCrafttable = nullptr;
	this->nSingleTimeReturn = 0;
}

fluidItems::fluidItems(std::string strItemName, solidItems* aSolidCrafttable, fluidItems* aFluidCrafttable, int nLengthofSC, int nLengthofFC, int nSingleTimeReturn)
{
	this->strItemName = std::move(strItemName);
	this->nLengthofSC = nLengthofSC;
	this->nLengthofFC = nLengthofFC;
	this->aSolidCrafttable = aSolidCrafttable;
	this->aFluidCrafttable = aFluidCrafttable;
	this->nSingleTimeReturn = nSingleTimeReturn;
}

fluidItems::fluidItems(fluidItems& fluid)
{
	this->strItemName = fluid.strItemName;
	this->nLengthofSC = fluid.nLengthofSC;
	this->nLengthofFC = fluid.nLengthofFC;
	this->aSolidCrafttable = fluid.aSolidCrafttable;
	this->aFluidCrafttable = fluid.aFluidCrafttable;
	this->nSingleTimeReturn = fluid.nSingleTimeReturn;
}

std::string fluidItems::getItemName()
{
	return this->strItemName;
}

solidItems* fluidItems::getSolidCrafttable()
{
	return this->aSolidCrafttable;
}

fluidItems* fluidItems::getFluidCrafttable()
{
	return this->aFluidCrafttable;
}

int fluidItems::getSCLength()
{
	return this->nLengthofSC;
}

int fluidItems::getFCLength()
{
	return this->nLengthofFC;
}

int fluidItems::getSingleTimeReturn()
{
	return this->nSingleTimeReturn;
}

void fluidItems::replaceItemName(std::string strNewItemName)
{
	this->strItemName = std::move(strNewItemName);
}

void fluidItems::replaceSolidCrafttable(int nNewLengthofSC, solidItems* aNewSolidCrafttable)
{
	this->nLengthofSC = nNewLengthofSC;
	this->aSolidCrafttable = aNewSolidCrafttable;
}

void fluidItems::replaceFluidCrafttable(int nNewLengthofFC, fluidItems* aNewFluidCrafttable)
{
	this->nLengthofFC = nNewLengthofFC;
	this->aFluidCrafttable = aNewFluidCrafttable;
}

void fluidItems::replaceSingleTimeReturn(int nNewSingleTimeReturn)
{
	this->nSingleTimeReturn = nNewSingleTimeReturn;
}

fluidItems::~fluidItems()
{
	delete this->aFluidCrafttable;
	delete this->aSolidCrafttable;
}
