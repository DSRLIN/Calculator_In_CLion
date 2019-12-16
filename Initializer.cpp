#include "allHeaders.h"
#include "Initializer.h"


Initializer::Initializer() {
    std::list<solidItems> solidItemList;
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
                        case 3:
                            /*TODO:
                             * 把字符串塞进数组
                             * 之后再议 因为还要从树里走一层
                             * */
                            if(tempElement->NextSiblingElement()) {
                                tempElement = tempElement->NextSiblingElement();
                            }
                            break;
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
                            }
                            break;
                        default:
                            //std::cout << "Error member name!" << std::endl;
                            break;
                    }

                }
                solidItemList.push_back(*tmpSolidItem);
                nNumOfSolidItems++;
                break;
            }
            allSolidItems = new solidItems *[nNumOfSolidItems];
            for (int i = 0; i < nNumOfSolidItems; i++) {
                allSolidItems[i] = new solidItems(solidItemList.front());
                solidItemList.pop_front();
            }
            solidElements = solidElements->NextSiblingElement();
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