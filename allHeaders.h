#pragma once
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<stack>
#include <list>
#ifdef __CYGWIN__
#include <unistd.h>
#else
#include <windows.h>
#endif
#include "tinyxml2.h"
#include "fluidItems.h"
#include "solidItems.h"
#include "Initializer.h"
#include "solidCraftMark.h"
#include "fluidCraftMark.h"
#include "CraftSystem.h"
extern solidItems** allSolidItems;
extern int nNumOfSolidItems;
extern std::list<solidItems*> listAllSolidItems;
extern std::list<solidCraftMark> solidWaitingList;