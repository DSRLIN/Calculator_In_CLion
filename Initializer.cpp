#include "allHeaders.h"
#include "Initializer.h"


Initializer::Initializer() {
    std::list<solidItems*> solidItemList;
    this->_solidInitXML.LoadFile(R"(solidBlocks.xml)");
    //接下来只需要把树里的所有内容全部收进非流体数组里
    if(_solidInitXML.Error()){
        _solidInitXML.PrintError();
    }
    XMLElement* rootElement = _solidInitXML.RootElement();
    if(!rootElement){
        std::cout<<"empty"<<std::endl;
        return;
    }else {
        XMLElement *solidElements = rootElement->FirstChildElement();
        while (solidElements) {
            XMLElement *tempElement = solidElements->FirstChildElement();
            while (tempElement) {
                auto *tmpSolidItem = new solidItems;
                while(tempElement){
                    switch (solidStrToSwitchNum(tempElement->Name())) {
                        case 0:
                            tmpSolidItem->replaceItemName(tempElement->GetText());
                            //std::cout << "名字修改成功" << std::endl;
                            if(tempElement->NextSiblingElement()) {
                                tempElement = tempElement->NextSiblingElement();
                            }
                            break;
                        case 1:
                            tmpSolidItem->replaceIsRawMaterial(strcmp(tempElement->GetText(), "true"));
                            //std::cout << "bool修改成功" << std::endl;
                            if(tempElement->NextSiblingElement()) {
                                tempElement = tempElement->NextSiblingElement();
                            }
                            break;
                        case 2:
                            int nNum2;
                            nNum2 = strtol(tempElement->GetText(), nullptr, 10);
                            tmpSolidItem->replaceSolidLength(nNum2);
                            //std::cout << "长度1修改成功" << std::endl;
                            if(tempElement->NextSiblingElement()) {
                                tempElement = tempElement->NextSiblingElement();
                            }
                            break;
                        case 3: {
                            /*TODO:
                             * 把字符串塞进数组
                             * 之后再议 因为还要从树里走一层
                             * */
                            //固体合成数组
                            auto *solidCraftTable = tempElement->FirstChildElement();
                            auto **aCurSolidItemList = new solidItems* [tmpSolidItem->getSCLength()];
                            for (int i = 0; i < tmpSolidItem->getSCLength(); i++) {
                                if(!solidCraftTable){
                                    break;
                                }
                                aCurSolidItemList[i] = new solidItems();
                                //在这里我们得到了一个纯NULL的固体物品数组 也可以看成是开辟空间使用的手段
                                //必要性存疑 不需要的话把这句删了就可

                                //（我为什么不直接把处理过程放进这里来
                                //（我是sb
                                //如果写入xml内容的人没有搞事情的话那么xml子树的长度应该和SCLength是一致的
                                //所以循环次数也应该是一致的
                                //（这里的注释是从下面拿来的）
                                //这里是对xml带来的字符串进行处理
                                //先去写一个匹配函数来 输入字符串 得到固体物品
                                /*基本思想已经很明确了
                                 * 先把所有的输入内容生成的仅有名字的元素作为自身的合成表
                                 * 并且将所有输入内容入队列
                                 * 最后在所有物品初始化完毕后对队列进行逐个处理
                                 * 最后由于所有物品全部使用初始化数组中对象的指针
                                 * 可以保证修改后的对象可以反映到每个物品中去
                                 * */
                                //对每个数组内容进行修改
                                aCurSolidItemList[i] = getNullSolidItemByName(solidCraftTable->GetText());
                                //别急 这里还要往solidCraftMarkList里录一次东西
                                //条件是这个东西没有往队列里录过
                                bool bTestFlag = false;
                                for (auto & iter : solidWaitingList) {
                                    if(iter == solidCraftMark(solidCraftTable->GetText(),tmpSolidItem->getItemName())){
                                        bTestFlag = true;
                                    }
                                }
                                if(!bTestFlag){
                                    solidWaitingList.emplace_back(solidCraftTable->GetText(),tmpSolidItem->getItemName());
                                }


                                //修改完了指向下一项
                                solidCraftTable = solidCraftTable->NextSiblingElement();
                            }

                            tmpSolidItem->replaceSolidCrafttable(aCurSolidItemList);
                            if (tempElement->NextSiblingElement()) {
                                tempElement = tempElement->NextSiblingElement();
                            }
                            break;
                        }
                        case 4:
                            int nNum4;
                            nNum4 = strtol(tempElement->GetText(), nullptr, 10);
                            tmpSolidItem->replaceFluidLength(nNum4);
                            //std::cout << "长度2修改成功" << std::endl;
                            if(tempElement->NextSiblingElement()) {
                                tempElement = tempElement->NextSiblingElement();
                            }
                            break;
                        case 5:
                            /*TODO:
                             * 同3
                             * */
                            if(tempElement->NextSiblingElement()) {
                                tempElement = tempElement->NextSiblingElement();
                            }
                            break;
                        case 6:
                            int nNum6;
                            nNum6 = strtol(tempElement->GetText(), nullptr, 10);
                            tmpSolidItem->replaceSingleTimeReturn(nNum6);
                            //std::cout << "合成量修改成功" << std::endl;
                            if(tempElement->NextSiblingElement()) {
                                tempElement = tempElement->NextSiblingElement();
                            }else{
                                tempElement = nullptr;
                            }
                            break;
                        default:
                            //std::cout << "Error member name!" << std::endl;
                            break;
                    }

                }
                solidItemList.push_back(tmpSolidItem);
                nNumOfSolidItems++;
                //solidElements = solidElements->NextSiblingElement();
                break;
            }
            //初始化这步放到最后做
            solidElements = solidElements->NextSiblingElement();
        }
        allSolidItems = new solidItems *[nNumOfSolidItems];
        for (int i = 0; i < nNumOfSolidItems; i++) {
            allSolidItems[i] = solidItemList.front();
            solidItemList.pop_front();
        }
    }
}
void Initializer::solidReadFromFile(const std::string& strCommentString) {
    //我自己目前都不知道这个玩意有没有用了
    std::fstream solidText;
    solidText.open("solidBlocks.txt",std::ios::in);
    if(!solidText) {
        std::cout << "Open Failed" << std::endl;
        return;
    }
    while(!solidText.eof()){
        std::string strTemp;
        std::getline(solidText,strTemp);
        //这一步是对注释进行处理
        for(char &c:strTemp){
            if(c == '\t' || c == '\r' || c == '\n'){
                //抹去单行的任意制表符以及换行、回车
                c = ' ';
            }
            strTemp.erase(0,strTemp.find_first_not_of(' '));
            strTemp.erase(strTemp.find_last_not_of(' ') + 1);
            int nCommentStartPos = strTemp.find_first_of(strCommentString);
            if(nCommentStartPos != std::string::npos){
                strTemp.erase(nCommentStartPos);
            }
        }
        //现在的字符串应该是去掉了注释的
        for(size_t i = 0; i < strTemp.length(); i++){
            //复制第一个字符串

        }
        //测试用
        std::cout<<strTemp<<std::endl;
    }

}
solidItems *Initializer::findSolidItemByString(const std::string& strFind) {
    for(int i = 0;i < nNumOfSolidItems;i++){
        if(strFind == allSolidItems[i]->getItemName()){
            return allSolidItems[i];
        }
    }
    //如果遍历完整个数组但什么都没找到 则返回一个空指针
    return nullptr;
}

solidItems *Initializer::getNullSolidItemByName(const std::string &strName) {
    //需要一个特化的构造函数或者把构造函数加上默认参数
    return new solidItems(strName);
}

void Initializer::solidWaitingListHandler() {
    bool bLap = false;
    auto iter = solidWaitingList.begin();
    while((!solidWaitingList.empty()) && (!bLap)){
        //处理队列中的所有信息
        solidItems* tempSolidBaseItem = findSolidItemByString(iter->getWaitingItemName());
        solidItems* tempSolidReplaceItem = findSolidItemByString(iter->getItemName());
        if(tempSolidBaseItem && tempSolidReplaceItem){
           //保证两项都找到了才进入处理过程 只需要对指针进行替换就可以了
           //把baseItem内合成表的空名字替换成replaceItem即可
           //同样 这个东西成立的前提是写入xml的人没有搞事情
           tempSolidBaseItem->replaceItemsInSC(tempSolidReplaceItem);
           auto iterRemove = iter;//这个东西是以指针的形式接下来的吗？是指针就问题大了
           iter++;
           solidWaitingList.remove(*iterRemove);
        }
        //处理完毕本项后的东西
        //debug发现的思路问题：
        //每次处理完后应该移除的是这次处理的内容而不是简单地把头pop掉

        iter++;
        //草 上面的while写成if了
        if(iter == solidWaitingList.end()){
            bLap = true;
        }
    }
    std::cout<<"退出！"<<std::endl;
}
