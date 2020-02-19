//
// Created by Lin Yu on 2020/1/18.
//

#pragma once

#include <iostream>
#include <list>
#include <stack>
#include <string>

class solidItems;
class fluidCraftMark;
class CraftSystem {
private:
    std::stack <solidItems*> craftStack;
public:
    void pushStack(solidItems* craftSolidItem); //根据合成物品 入栈
    void testOutput(); //测试出栈顺序 由于会pop掉东西所以务必重新将物品入栈
};
