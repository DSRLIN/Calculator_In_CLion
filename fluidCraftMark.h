//
// Created by Lin Yu on 2020/1/15.
//

#pragma once

#include <iostream>
#include <string>

class solidItems;
class fluidCraftMark {
private:
    std::string _strFluidName;
    int _nCraftDosage; //这个地方应该要改一下用词 dosage是医学那个方向（？的用词
public:
    fluidCraftMark();
    fluidCraftMark(std::string strFluidName,int nCraftDosage);
    std::string getFluidName();
    int getCraftDosage();
    void outputCraftMark();
    ~fluidCraftMark() = default;
};
