#include <utility>

#include "allHeaders.h"
#include "solidItems.h"


solidItems::solidItems(){
	this->strItemName = "NULL";
	this->nLengthofSC = 0;
	this->nLengthofFC = 0;
	this->aSolidCrafttable = nullptr;
	this->aFluidCraftMarks = nullptr;
	this->nSingleTimeReturn = 0;
	this->bIsRawMaterial = false;
}

solidItems::solidItems(std::string strItemName, solidItems** aSolidCrafttable, fluidCraftMark** aFluidCraftMarks, int nLengthofSC, int nLengthofFC, int nSingleTimeReturn,bool bIsRawMaterial){
	this->strItemName = strItemName;
    this->bIsRawMaterial = bIsRawMaterial;
    if(!bIsRawMaterial){
        this->nLengthofSC = nLengthofSC;
        this->nLengthofFC = nLengthofFC;
        this->aSolidCrafttable = aSolidCrafttable;
        this->aFluidCraftMarks = aFluidCraftMarks;
        this->nSingleTimeReturn = nSingleTimeReturn;
    }
}

solidItems::solidItems(std::string strItemName){
    this->strItemName = strItemName;
    this->nLengthofSC = 0;
    this->nLengthofFC = 0;
    this->aSolidCrafttable = nullptr;
    this->aFluidCraftMarks = nullptr;
    this->nSingleTimeReturn = 0;
    this->bIsRawMaterial = true;
};

solidItems::solidItems(const solidItems& item){
	this->strItemName = item.strItemName;
	this->nLengthofSC = item.nLengthofSC;
	this->nLengthofFC = item.nLengthofFC;
	this->aSolidCrafttable = item.aSolidCrafttable;
	this->aFluidCraftMarks = item.aFluidCraftMarks;
	this->nSingleTimeReturn = item.nSingleTimeReturn;
	this->bIsRawMaterial = item.bIsRawMaterial;
}

std::string solidItems::getItemName(){
	return this->strItemName;
}

solidItems** solidItems::getSolidCrafttable(){
	return this->aSolidCrafttable;
}

fluidCraftMark** solidItems::getFluidCraftMarks(){
	return this->aFluidCraftMarks;
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
	this->strItemName = strNewItemName;
}

void solidItems::replaceSolidLength(int nNewLengthofSC) {
    this->nLengthofSC = nNewLengthofSC;
}

void solidItems::replaceSolidCrafttable(solidItems** aNewSolidCrafttable){
	this->aSolidCrafttable = aNewSolidCrafttable;
}

void solidItems::replaceFluidLength(int nNewLengthofFC) {
    this->nLengthofFC = nNewLengthofFC;
}

void solidItems::replaceFluidCraftMarks(fluidCraftMark** aNewFluidCraftMarks){
	this->aFluidCraftMarks = aNewFluidCraftMarks;
}

void solidItems::replaceSingleTimeReturn(int nNewSingleTimeReturn){
	this->nSingleTimeReturn = nNewSingleTimeReturn;
}

void solidItems::replaceIsRawMaterial(bool bNewIsRawMaterial)
{
	this->bIsRawMaterial = bNewIsRawMaterial;
}

void solidItems::solidOutput() {
    if(!this->strItemName.empty()){
        std::cout<<"本物品的名字为："<<this->getItemName()<<std::endl;
    }else{
        std::cout<<"这是一个空物品 没有名字"<<std::endl;
        return;
    }
    if(this->bIsRawMaterial){
        std::cout<<"本物品为基本材料 无法继续向下展开"<<std::endl;
    }else {
        std::cout<<"本物品非基本材料"<<std::endl;
        std::cout << "固体合成表长度为：" << this->getSCLength() << std::endl;
        if (this->aSolidCrafttable) {
            for (int i = 0; i < this->nLengthofSC; i++) {
                std::cout << aSolidCrafttable[i]->getItemName() << std::endl;
            }
        } else {
            std::cout << "空固体合成数组！请考虑是否已经加入了固体合成数组？" << std::endl;
        }
        std::cout << "流体合成表长度为：" << this->getFCLength() << std::endl;
        if (this->aFluidCraftMarks) {
            for (int i = 0; i < this->nLengthofFC; i++) {
                aFluidCraftMarks[i]->outputCraftMark();
            }
        } else {
            std::cout << "空流体合成数组！请考虑是否已经加入了流体合成数组？" << std::endl;
        }
        std::cout << "单次输出最少得到" << this->getSingleTimeReturn() << "个物品" << std::endl;
    }
}

solidItems::~solidItems(){
	delete this->aFluidCraftMarks;
	delete this->aSolidCrafttable;
}

void solidItems::replaceItemsInSC(solidItems *pNewSolidItem) {
    for (int i = 0; i < this->nLengthofSC; ++i) {
        if(this->aSolidCrafttable[i]->strItemName == pNewSolidItem->getItemName()){
            //相同则替换
            this->aSolidCrafttable[i] = pNewSolidItem;
        }
    }
}






