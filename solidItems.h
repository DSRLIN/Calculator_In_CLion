#pragma once
class fluidCraftMark;
class solidItems
{
private:
	std::string strItemName;                 //物品名称
	int nLengthofSC;                         //固体物品的合成表长度
	solidItems** aSolidCrafttable;	         //该物品合成所用到的固体物品
	int nLengthofFC;						 //流体的合成表长度
	fluidCraftMark** aFluidCraftMarks;       //该物品合成所用到的流体物品 可以理解成一个假标记
	int nSingleTimeReturn;                   //单次合成能得到的最少物品数量
	bool bIsRawMaterial;                     //是否是不能继续向下拆分的原材料
public:
	//构造（巨大抽象）
	solidItems();
	solidItems(std::string strItemName,solidItems** aSolidCrafttable, fluidCraftMark** aFluidCraftMarks, int nLengthofSC,int nLengthofFC,int nSingleTimeReturn,bool bIsRawMaterial);
	//为名字特化的构造函数
	solidItems(std::string strItemName);
	solidItems(const solidItems& item);
	//一切的接口与修改……
	std::string getItemName();
	solidItems** getSolidCrafttable();
	fluidCraftMark** getFluidCraftMarks();
	int getSCLength();
	int getFCLength();
	int getSingleTimeReturn();
	bool getIsRawMaterial();
	void replaceItemName(std::string strNewItemName);
    void replaceSolidLength(int nNewLengthofSC);
	void replaceSolidCrafttable(solidItems** aNewSolidCrafttable);
    void replaceFluidLength(int nNewLengthofFC);
	void replaceFluidCraftMarks(fluidCraftMark** aNewFluidCraftMarks);
	void replaceSingleTimeReturn(int nNewSingleTimeReturn);
	void replaceIsRawMaterial(bool bNewIsRawMaterial);
	void solidOutput();
	void replaceItemsInSC(solidItems* pNewSolidItem);
	~solidItems();
};

