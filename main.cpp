#include "allHeaders.h"
int nNumOfSolidItems = 0;
solidItems** allSolidItems;
int main() {
    system("chcp 65001 > nul");
    Initializer in;
    for (int i = 0; i < nNumOfSolidItems; ++i) {
        if(allSolidItems[i]){
            allSolidItems[i]->solidOutput();
        }else{
            std::cout<<"空指针！"<<std::endl;
        }
    }
    system("pause");
    return 0;
}