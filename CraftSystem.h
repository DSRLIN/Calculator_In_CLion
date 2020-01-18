//
// Created by Lin Yu on 2020/1/18.
//

#ifndef CALCULATOR_IN_CLION_CRAFTSYSTEM_H
#define CALCULATOR_IN_CLION_CRAFTSYSTEM_H

#include <iostream>
#include <list>
#include <stack>
#include <string>

class solidItems;
class fluidCraftMark;
class CraftSystem {
private:
    std::stack <solidItems> craftStack;
public:
    static void pushStack(solidItems* craftSolidItem); //根据合成物品 入栈
};


#endif //CALCULATOR_IN_CLION_CRAFTSYSTEM_H
