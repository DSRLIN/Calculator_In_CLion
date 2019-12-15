#pragma once
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<stack>
#include <windows.h>
#include "tinyxml2.h"
#include "fluidItems.h"
#include "solidItems.h"
#include "Initializer.h"

extern solidItems** allSolidItems;
extern int nNumOfSolidItems;

int solidStrToSwitchNum(const std::string& strSolid){
    if(strSolid == "name"){
        return 0;
    }else if(strSolid == "separable"){
        return 1;
    }else if(strSolid == "scLength"){
        return 2;
    }else if(strSolid == "solidCraftTable"){
        return 3;
    }else if(strSolid == "fcLength"){
        return 4;
    }else if(strSolid == "fluidCraftTable"){
        return 5;
    }else if(strSolid == "singleTimeReturn"){
        return 6;
    }else{
        return -1;
    }
}