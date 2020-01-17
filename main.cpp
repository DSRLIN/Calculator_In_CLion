#include "allHeaders.h"
int nNumOfSolidItems = 0;
solidItems** allSolidItems;
std::list<solidItems> listAllSolidItems;
std::list<solidCraftMark> solidWaitingList;
int main() {
    system("chcp 65001 > nul");
    /*tinyxml2::XMLDocument doc;
    doc.LoadFile("test.xml");
    XMLElement *scene=doc.RootElement();
    XMLElement *surface=scene->FirstChildElement();
    while (surface)
    {
        XMLElement *surfaceChild=surface->FirstChildElement();
        const char* content;
        const XMLAttribute *attributeOfSurface = surface->FirstAttribute();
        cout<< attributeOfSurface->Name() << ":" << attributeOfSurface->Value() << endl;
        while(surfaceChild)
        {
            content=surfaceChild->GetText();
            surfaceChild=surfaceChild->NextSiblingElement();
            cout<<content<<endl;
        }
        surface=surface->NextSiblingElement();
    }*/
    Initializer in;
    for (int i = 0; i < nNumOfSolidItems; ++i) {
        if(allSolidItems[i]){
            allSolidItems[i]->solidOutput();
        }else{
            std::cout<<"空指针！"<<std::endl;
        }
    }
    std::cout<<std::endl;

    std::cout<<"等待被修改合成表的队列信息如下："<<std::endl;
    for (auto & iter : solidWaitingList) {
        iter.testOutput();
    }
    Initializer::solidWaitingListHandler();
    for (auto & iter : solidWaitingList) {
        iter.testOutput();
    }
    system("pause");
    return 0;
}