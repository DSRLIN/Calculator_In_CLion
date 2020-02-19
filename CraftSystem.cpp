//
// Created by Lin Yu on 2020/1/18.
//

#include "CraftSystem.h"
#include "solidItems.h"

void CraftSystem::pushStack(solidItems *craftSolidItem) {
    //基本思想就是个对整个树的类似后序遍历的操作方式
    //将整个树递归入栈即可
    //想了想还是用指针好一点 方便一些
    //递归写法 非递归实在难顶

    //刚刚想到的 只需要依次使用数字把合成表往下走即可
    //没有必要到了本层然后访问兄弟结点
    if(!craftSolidItem->getIsRawMaterial()){
        //如果非原材料则继续进行递归
        for (int i = 0; i < craftSolidItem->getSCLength(); ++i) {
            pushStack(craftSolidItem->getSolidCrafttable()[i]);
        }
    }
    //递归结束后本物品入栈
    craftStack.push(craftSolidItem);
}

void CraftSystem::testOutput() {
    while(!craftStack.empty()){
        craftStack.top()->solidOutput();
        craftStack.pop();
    }
}
