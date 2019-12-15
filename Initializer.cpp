#include "allHeaders.h"
#include "Initializer.h"


Initializer::Initializer() {
    this->_solidInitXML.LoadFile(R"(F:\Custom Mod\Calculator In CLion\cmake-build-debug\solidBlocks.xml)");
    //接下来只需要把树里的所有内容全部收进非流体数组里
    if(_solidInitXML.Error()){
        _solidInitXML.PrintError();
    }
    XMLElement* rootElement = _solidInitXML.RootElement();
    if(!rootElement){
        std::cout<<"empty"<<std::endl;
        return;
    }else{
        XMLElement* solidElements = rootElement->FirstChildElement();
        for(XMLElement* tempElement = solidElements->FirstChildElement();tempElement->NextSiblingElement() == nullptr;
        solidElements = solidElements->NextSiblingElement()){
            allSolidItems[nNumOfSolidItems] = new solidItems;
            for(;tempElement->NextSiblingElement() != nullptr;tempElement = tempElement->NextSiblingElement()){
                switch (solidStrToSwitchNum(tempElement->Name())){
                    case 0:
                        allSolidItems[nNumOfSolidItems]->replaceItemName(tempElement->GetText());
                        break;
                    case 1:
                        allSolidItems[nNumOfSolidItems]->replaceIsRawMaterial(strcmp(tempElement->GetText(),"true"));
                        break;
                    case 2:
                        int nNum;
                        nNum = strtol(tempElement->GetText(),nullptr,10);
                        allSolidItems[nNumOfSolidItems]->replaceSolidLength(nNum);
                        break;
                    case 3:

                        break;
                    case 4:

                        break;
                    case 5:

                        break;
                    case 6:

                        break;
                    default:
                        std::cout<<"Error member name!"<<std::endl;
                        break;
                }
            }
            nNumOfSolidItems++;

        }
    }
    /*std::cout<<tempElement->Name()<<std::endl;
    std::cout<<tempElement->FirstChildElement()->Name()<<std::endl;*/
    /*基本结构如下：
     *这个基本结构有问题 需要重新考量
     */
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