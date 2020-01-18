#include "allHeaders.h"
int nNumOfSolidItems = 0;
solidItems** allSolidItems;
std::list<solidItems*> listAllSolidItems;
std::list<solidCraftMark> solidWaitingList;
int main() {
    system("chcp 65001 > nul");
    Initializer in;
    Initializer::solidWaitingListHandler();
    Initializer::lastHandler();
    //到这里整体初始化完毕
    system("pause");
    return 0;
}