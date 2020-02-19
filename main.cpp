#include "allHeaders.h"
int nNumOfSolidItems = 0;
solidItems** allSolidItems;
std::list<solidItems*> listAllSolidItems;
std::list<solidCraftMark> solidWaitingList;
solidItems* getItemInList(const std::string& strItemName);
void outputAllItems();
int main() {
    system("chcp 65001 > nul");
    std::string strName;
    Initializer in;
    Initializer::solidWaitingListHandler();
    Initializer::lastHandler();
    //到这里整体初始化完毕
    CraftSystem cr;
    std::cout<<"输入内容名称"<<std::endl;
    std::cin>>strName;
    //outputAllItems();
    cr.pushStack(getItemInList(strName));
    cr.testOutput();
    system("pause");
    return 0;
}
solidItems* getItemInList(const std::string& strItemName){
    bool bItemNotGet = true;
    auto iter = listAllSolidItems.begin();
    while(bItemNotGet){
        if((*iter)->getItemName() == strItemName) {
            bItemNotGet = false;
        }else{
            iter++;
        }
    }
    return (*iter);
}
void outputAllItems(){
    auto iter = listAllSolidItems.begin();
    while(iter != listAllSolidItems.end()){
        (*iter)->solidOutput();
        iter++;
    }

}
