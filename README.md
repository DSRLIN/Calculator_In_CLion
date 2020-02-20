# [格雷科技计算器](https://github.com/DSRLIN/Calculator_In_CLion/archive/master.zip)
本软件大致使用场景与Just Enough Calculation相似<br>
目的是计算所需的大量合成材料（从顶向底计算）
# 注意！注意！注意！不支持流体合成！

## 修改记录
### v0.1
* 目前支持单个物品的向下运算
* 暂时没有可视化界面（不过很快就会有了）


## 安装要求
* Cmake版本至少3.15
* 非Cygwin的编译器（这个问题从很久前就存在了）
* Windows

## 使用说明
在编译完成后，通过修改exe文件的根目录下的solidBlocks.xml来自定义合成表
### 示例内容如下
```xml
<solid>
    <name>A</name>
    <separable>true</separable>
    <scLength>2</scLength>
    <solidCraftTable>
      <sc01>B</sc01>
      <sc02>C</sc02>
    </solidCraftTable>
    <fcLength>0</fcLength>
    <fluidCraftTable></fluidCraftTable>
    <singleTimeReturn>2</singleTimeReturn>
 </solid>
```
### 内容说明
* name:物品名称，理论上支持各种语言（不过我暂时没对除中英文之外的语言进行测试）
  * 似乎不分大小写（这个可能要去问std string）
  * 同一xml内物品不允许重名 重名可能会导致后面的物品覆盖前面的物品
  
* separable：判断物品是否可向下拆分
  * 最底部的原料物品（即scLength与fcLength均为0）则不需要写入，程序会自动考虑
  * 若scLength或fcLength不为0则为true
  * 你要是真的想加底部原料那就写 反正程序不拦着你

* scLength：合成表中非流体物品的数量

* solidCraftTable:合成表中非流体物品的名字
  * 从sc01开始写到scxx，上下数量应保持一致

* fcLength：合成表中流体物品的数量，应为0

* fluidCraftTable：合成表中流体物品的名字，应留空

* singleTimeReturn：单次合成返回的数量

## 注意
若在编译前需要对xml内容进行修改，则必须在修改xml文件内容后对Cmake.txt进行reload
<br>
方法很简单，随便删掉一行等一等再加回来就可以
<br>
等我找到了更方便的解决方案后会把这处说明改掉
## 下载方式
[点标题或这里下载](https://github.com/DSRLIN/Calculator_In_CLion/archive/master.zip)
<br>
或者在项目的右上角的Clone or Download里下载zip文件
<br>
或者直接在你IDE的版本管理中clone git@github.com:DSRLIN/Calculator_In_CLion.git

## 作者
[@DSRLIN](https://github.com/DSRLIN)

## 友情鸣谢
Pharsalia
