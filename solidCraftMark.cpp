//
// Created by Lin Yu on 2020/1/13.
//

#include "solidCraftMark.h"

solidCraftMark::solidCraftMark(std::string strItemName, std::string strWaitingItemName) {
    this->strItemName = strItemName;
    this->strWaitingItemName = strWaitingItemName;
}

std::string solidCraftMark::getItemName() {
    return this->strItemName;
}

std::string solidCraftMark::getWaitingItemName() {
    return this->strWaitingItemName;
}

void solidCraftMark::testOutput() {
    std::cout<<"这是一条测试信息:"<<std::endl;
    std::cout<<"目前项的内容为：";
    std::cout<<"被置空项的名称为："<<this->strItemName<<std::endl;
    std::cout<<"等待被修改的物品名称为："<<this->strWaitingItemName<<std::endl;
}

bool solidCraftMark::operator==(const solidCraftMark &solidCraftMark1) {
    return (this->strItemName == solidCraftMark1.strItemName) &&
           (this->strWaitingItemName == solidCraftMark1.strWaitingItemName);
}


