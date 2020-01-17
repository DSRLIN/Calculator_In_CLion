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
	//现在考虑的思路是
	//流体名字＋空格+流体数量大概就可以解决
	//大概。。。不会有名字里带空格的流体吧。。？
	//（你起名字带 空 格

	//TODO：
	//对流体进行写入
	//由于流体一般不需要再次向下合成（是么
	//所以只需要根据流体名字及流体数量对数组进行写入即可
	//那么这就意味着。。。fluidItems的整体推倒重做。。。？
	//（大概罢

	//所以按这个思路写下去的话
	//这个合成就没流体合成什么事情了
	//或者可以新为固体初始化器的05再开一个类？
	//（开罢
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
    static solidItems* findSolidItemByString(const std::string& strFind);  //根据物品名称在整个初始化好的数组内检索同名物品 如果不搞事情的话只会有一个物品
    static solidItems* getNullSolidItemByName(const std::string& strName); //根据物品名称 返回一个仅有名字的对象用来占位
    static void solidWaitingListHandler();
    static fluidCraftMark* generateFluidByString(const std::string& strFluid);
};

