#include <utility>

#include "allHeaders.h"

solidItems::solidItems(){
	this->strItemName = "NULL";
	this->nLengthofSC = 0;
	this->nLengthofFC = 0;
	this->aSolidCrafttable = nullptr;
	this->aFluidCrafttable = nullptr;
	this->nSingleTimeReturn = 0;
	this->bIsRawMaterial = false;
}

solidItems::solidItems(std::string strItemName, solidItems* aSolidCrafttable, fluidItems* aFluidCrafttable, int nLengthofSC, int nLengthofFC, int nSingleTimeReturn,bool bIsRawMaterial){
	this->strItemName = std::move(strItemName);
    this->bIsRawMaterial = bIsRawMaterial;
    if(!bIsRawMaterial){
        this->nLengthofSC = nLengthofSC;
        this->nLengthofFC = nLengthofFC;
        this->aSolidCrafttable = aSolidCrafttable;
        this->aFluidCrafttable = aFluidCrafttable;
        this->nSingleTimeReturn = nSingleTimeReturn;
    }
}

solidItems::solidItems(solidItems& item){
	this->strItemName = item.strItemName;
	this->nLengthofSC = item.nLengthofSC;
	this->nLengthofFC = item.nLengthofFC;
	this->aSolidCrafttable = item.aSolidCrafttable;
	this->aFluidCrafttable = item.aFluidCrafttable;
	this->nSingleTimeReturn = item.nSingleTimeReturn;
	this->bIsRawMaterial = item.bIsRawMaterial;
}

std::string solidItems::getItemName(){
	return this->strItemName;
}

solidItems* solidItems::getSolidCrafttable(){
	return this->aSolidCrafttable;
}

fluidItems* solidItems::getFluidCrafttable(){
	return this->aFluidCrafttable;
}

int solidItems::getSCLength(){
	return this->nLengthofSC;
}

int solidItems::getFCLength(){
	return this->nLengthofFC;
}

int solidItems::getSingleTimeReturn(){
	return this->nSingleTimeReturn;
}

bool solidItems::getIsRawMaterial()
{
	return this->bIsRawMaterial;
}

void solidItems::replaceItemName(std::string strNewItemName){
	this->strItemName = std::move(strNewItemName);
}

void solidItems::replaceSolidCrafttable(int nNewLengthofSC, solidItems* aNewSolidCrafttable){
	this->nLengthofSC = nNewLengthofSC;
	this->aSolidCrafttable = aNewSolidCrafttable;
}

void solidItems::replaceFluidCrafttable(int nNewLengthofFC, fluidItems* aNewFluidCrafttable){
	this->nLengthofFC = nNewLengthofFC;
	this->aFluidCrafttable = aNewFluidCrafttable;
}

void solidItems::replaceSingleTimeReturn(int nNewSingleTimeReturn){
	this->nSingleTimeReturn = nNewSingleTimeReturn;
}

void solidItems::replaceIsRawMaterial(bool bNewIsRawMaterial)
{
	this->bIsRawMaterial = bNewIsRawMaterial;
}

solidItems::~solidItems(){
	delete this->aFluidCrafttable;
	delete this->aSolidCrafttable;
}
