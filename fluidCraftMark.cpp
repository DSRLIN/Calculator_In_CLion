//
// Created by Lin Yu on 2020/1/15.
//
#include "allHeaders.h"
#include "fluidCraftMark.h"

fluidCraftMark::fluidCraftMark() {
    this->_strFluidName = "NULL";
    this->_nCraftDosage = 0;
}

fluidCraftMark::fluidCraftMark(std::string strFluidName, int nCraftDosage) {
    this->_strFluidName = strFluidName;
    this->_nCraftDosage = nCraftDosage;
}

std::string fluidCraftMark::getFluidName() {
    return this->_strFluidName;
}

int fluidCraftMark::getCraftDosage() {
    return this->_nCraftDosage;
}

void fluidCraftMark::outputCraftMark() {
    std::cout<<"流体名字为："<<this->_strFluidName<<std::endl;
    std::cout<<"用量为："<<this->_nCraftDosage<<std::endl;
}
