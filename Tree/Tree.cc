#include"Tree.h"

Tree::Tree(int size)//size表示数组中树的容量，表示数组分配大小
{
    m_iSize = size;
    m_pTree = new int[size];
    for(int i = 0; i< size; i ++)//数组置零
    {
        m_pTree[i] = 0;
    }
}
Tree::~Tree()
{
    delete []m_pTree;
    m_pTree = NULL;
}

int *Tree::SearchNode(int nodeIndex)//按照数组下标进行搜索
{
    //合法判断
    if(nodeIndex < 0||nodeIndex >= m_iSize)
    {
        return NULL;
    }
    if(m_pTree[nodeIndex] == 0)
    {
        return NULL;
    }
    return &m_pTree[nodeIndex];//返回一个地址
}
bool Tree:: AddNode(int nodeIndex,int direction,int *pNode)
{
    //合法判断
    if(nodeIndex < 0||nodeIndex >= m_iSize)
    {
        return false;
    }
    if(m_pTree[nodeIndex] == 0)
    {
        return false;
    }
    if(direction == 0)//判断插入是左孩子还是右孩子，0代表左
    {
        //判断插入的节点是否合法
        if(nodeIndex * 2 + 1 >= m_iSize)
    {
        return false;
    }
    if(m_pTree[nodeIndex * 2 + 1] != 0)//不等于0说明这个节点已经被插入过了
    {
        return false;
    }
        m_pTree[nodeIndex * 2 + 1] = *pNode;
    }
    if(direction == 1)//判断插入是左孩子还是右孩子，0代表左，1代表右
    {
        //判断插入的节点是否合法
        if(nodeIndex * 2 + 2 >= m_iSize)
    {
        return false;
    }
    if(m_pTree[nodeIndex * 2 + 2] != 0)//不等于0说明这个节点已经被插入过了
    {
        return false;
    }

        m_pTree[nodeIndex * 2 + 2] = *pNode;
    }

}
bool Tree:: DeleteNode(int nodeIndex,int *pNode)
{
    //合法判断
    if(nodeIndex < 0||nodeIndex >= m_iSize)
    {
        return false;
    }
    if(m_pTree[nodeIndex] == 0)
    {
        return false;
    }
    *pNode = m_pTree[nodeIndex];
    m_pTree[nodeIndex] = 0;
    return true;//删除成功
}
void Tree::TreeTraverse()//树的遍历
{
    for(int i = 0; i<m_iSize;i++)
    {
        cout << m_pTree[i] << " ";
    }
}