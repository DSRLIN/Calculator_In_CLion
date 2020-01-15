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
