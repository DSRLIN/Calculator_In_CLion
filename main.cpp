#include "allHeaders.h"
int nNumOfSolidItems = 0;
solidItems**allSolidItems;
using namespace std;
using namespace tinyxml2;
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
    system("pause");
    return 0;
}