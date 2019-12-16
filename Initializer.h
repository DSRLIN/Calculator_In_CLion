#pragma once
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<stack>
#include "tinyxml2.h"
using namespace tinyxml2;
class Initializer
    //顺带一提 这个玩意仅初始化一个非流体数组
    //流体数组用另外一个加载器
{
	//这从文件读内容并且根据特定格式初始化类
	//以行为单位统计 每行为一个物品
	//这里仍然留着 以备不时之需



	//有一个极为要命的问题：
	//流体的数量怎么存？



	//计划有变 现在我发现好像用xml更加方便一点？
	//TODO：
	//每个物品写个树 （写完发现并不是很麻烦
	//并且在有了示例模板的情况下修改也不算很难
	//数组的问题大约解决了 只需要挂一个子树就可以了
	//现在唯一的问题就是 流体的数量需要分开存储 我想少了
	//需要拿xml做个测试 试一试能不能把流体名称和流体数量直接写在同一个字符串里并且方便地分开
	//（所以究极问题在于 转子nmsl 你用你emoji焊锡呢 你用你emoji组装机呢 压模器它不香吗
	//然后就是个古老的问题：str转int以及int转str以及不同格式字符串的互相疯狂转换
private:
    tinyxml2::XMLDocument _solidInitXML;
public:
    Initializer(); //tinyXML2这个货不支持=的重载 我能怎么办
    static int solidStrToSwitchNum(const std::string& strSolid){
        if(strSolid == "name"){
            return 0;
        }else if(strSolid == "separable"){
            return 1;
        }else if(strSolid == "scLength"){
            return 2;
        }else if(strSolid == "solidCraftTable"){
            return 3;
        }else if(strSolid == "fcLength"){
            return 4;
        }else if(strSolid == "fluidCraftTable"){
            return 5;
        }else if(strSolid == "singleTimeReturn"){
            return 6;
        }else{
            return -1;
        }
    }
    static void solidReadFromFile(const std::string& strCommentString = "//");
};

