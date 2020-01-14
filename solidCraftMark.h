﻿//
// Created by Lin Yu on 2020/1/13.
//

#ifndef CALCULATOR_IN_CLION_SOLIDCRAFTMARK_H
#define CALCULATOR_IN_CLION_SOLIDCRAFTMARK_H

#include <string>

//简单来说 这个东西就是个存放缺失物品名称和存放缺失物品名称容器的一个类
//写这个类的目的就是把一堆这种东西放进一个队列里 每当有新物品对整体数组进行修改的时候
//对这个队列进行检测并更新 如果队列里含有此物品 那么就对此物品所标记的物品的合成表内容进行修改
//并且由于检索函数的存在 这个类不需要存放物品 仅需要存放代表物品名称的字符串
class solidCraftMark {
public:
    std::string strItemName;
    std::string strWaitingItemName;
    solidCraftMark(std::string strItemName,std::string strWaitingItemName);
    ~solidCraftMark()= default;
};


#endif //CALCULATOR_IN_CLION_SOLIDCRAFTMARK_H