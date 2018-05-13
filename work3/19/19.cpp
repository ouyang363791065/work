/*代码实现是有空的头结点的写法*/
#include <stdio.h>
#include <malloc.h>
typedef struct Node
{
	char date;     //数据域
	Node * prior;   //头指针
	Node * next;   //尾指针
}Node;
void insertNode(Node * pHead, int pos, char date);  //插入一个节点数据域为date
void deleteNode(Node * pHead, int pos);//删除第pos个位置上的节点，pos从1开始
void replaceNode(Node * pHead, int pos, char date);//替换第pos个位置上的数据域，将数据域替换为date，pos从1开始
void reserch(Node * pHead);
Node * initNode(Node * pHead);
int length(Node * pHead);
int main()
{
	Node * myList=NULL;
	myList=initNode(myList);
	insertNode(myList, 2, 'a');
	insertNode(myList, 3, 'b');
	replaceNode(myList, 3,'x');
	printf("%d",length(myList));
	reserch(myList);
	return 0;
}
Node * initNode(Node * pHead)
{
	pHead = (Node *)malloc(sizeof(Node));
	pHead->next = pHead;
	pHead->prior = pHead;
	return pHead;
}
void insertNode(Node * pHead, int pos, char date)  //插入一个节点数据域为date,前面插入
{
	Node *p, *s;
	int i = 0;
	p = pHead->prior; //p始终指向尾节点 
	s = (Node *)malloc(sizeof(Node));
	s->date=date;
	while(i < pos - 1) 
	{ 
		i++; 
		p = p->next; 
	} 
	s->prior = p; 
	s->next = p->next;  //就是这里实现了。
	p->next->prior = s; 
	p->next = s; 
}
void deleteNode(Node * pHead, int pos)//删除第pos个位置上的节点，pos从1开始
{
	Node * L = pHead;
	for (int i = 0; i<pos - 1; i++)  //循环结束时p指向待删除节点
		L = L->next;
	L->prior->next = L->next;
	L->next->prior = L->prior;
	free(L);
}
void replaceNode(Node * pHead, int pos, char date)//替换第pos个位置上的数据域，将数据域替换为date，pos从1开始
{
	Node * L = pHead;
	for (int i = 0; i<pos - 1; i++)  //循环结束时p指向待替换节点
		L = L->next;
	L->date = date;
}
void reserch(Node * pHead)
{
	Node * L = pHead->next;
	while (L!= pHead)
	{
		printf("%c", L->date);
		L=L->next;
	}
}
int length(Node * pHead)
{
	Node * L = pHead;
	int cnt = 1;
	while (L->next!= pHead)
	{
		L = L->next;
		cnt++;
	}
	return cnt;
}