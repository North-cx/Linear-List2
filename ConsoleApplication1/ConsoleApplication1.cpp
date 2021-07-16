// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define ElementType int
#define MAXSIZE 10

//线性表的顺序存储实现
typedef struct LNode* List;
struct LNode {
    ElementType Data[MAXSIZE];
    int Last;
};
struct LNode L;
List Ptrl;
//访问下标为i的元素：L.Data[i]或PtrL->Data[i]
//线性表的长度：L.Last+1或PtrL->Last+1

//1.初始化（建立空的顺序表）
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

//2.查找
int Find(ElementType X, List PtrL)
{
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != X)
        i++;
    if (i > PtrL->Last) return -1; /*如果没找到，返回-1*/
    else return i;
}
//查找成功的平均比较次数为(n+1)/2,平均时间性能为O(n)。

//3.插入（第i(l<=i<=n+1)个位置上插入一个值为X的新元素）
void Insert(ElementType X, int i, List PtrL)
{   int j;
    if(PtrL->Last == MAXSIZE - 1) {
        printf("表满");
        return;
    }
    if (i < 1 || i > PtrL->Last + 2) {
        printf("位置不合法");
        return;
    }
    for (j = PtrL->Last;j >= i - 1;j--)     /*将ai~an倒序向后移动*/
        PtrL->Data[j + 1] = PtrL->Data[j];  /*新元素插入*/
    PtrL->Data[i - 1] = X;                  /*Last仍指向最后元素*/
    PtrL->Last++;
    return;
}
//平均移动次数为n/2,平均时间性能为O(n)

//4.删除（删除表的第i(l<=i<=n)个位置上的元素）
void Delete(ElementType X, int i, List PtrL)
{   int j;
    if (i < 1 || i > PtrL->Last + 1) {
        printf("不存在第%d个元素", i);
        return;
}
    for (j = i;j <= PtrL->Last;j++)
        PtrL->Data[j-1] = PtrL->Data[j];    /*将ai+1~an顺序向前移动*/
    PtrL->Last--;                           /*Last仍指向最后元素*/
    return;
}
//平均移动次数为(n-1)/2,平均时间性能为O(n)

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
