#include "allHeaders.h"
#include "Initializer.h"

Initializer::Initializer() {
    this->_solidInitXML.LoadFile("solidBlocks.xml");
    //接下来只需要把树里的所有内容全部收进非流体数组里

}
void Initializer::solidReadFromFile(const std::string& strCommentString) {
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