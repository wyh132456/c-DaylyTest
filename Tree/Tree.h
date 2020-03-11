#include <iostream>
using std:: cout;

/*
用数组表示二叉树
1.树的创建和销毁
2.树中结点的搜索
3.树中节点的添加和删除
4.树中节点的遍历
关于数组与树之间的算法转换

int tree[n] 3 58 2679  父亲结点下表*2+1 该结点左
                       父亲节点下标*2+2 该节点右
            3(0)
        5(1)      8(2)
    2(3)   6(4) 7(5)  9(6)




*/











 class Tree
{
private:
    int *m_pTree;//通过此指针指向数组
    int m_iSize;//记录数组大小
public:
    Tree(int size); //创建树
    ~Tree();//销毁树
    int *SearchNode(int nodeIndex);//根据索引寻找节点
    bool AddNode(int nodeIndex,int direction,int *pNode);//添加节点
    bool DeleteNode(int nodeIndex,int *pNode);//删除节点
    void TreeTraverse();//遍历节点
};



