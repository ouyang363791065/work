/*����ʵ�����пյ�ͷ����д��*/
#include <stdio.h>
#include <malloc.h>
typedef struct Node
{
	char date;     //������
	Node * prior;   //ͷָ��
	Node * next;   //βָ��
}Node;
void insertNode(Node * pHead, int pos, char date);  //����һ���ڵ�������Ϊdate
void deleteNode(Node * pHead, int pos);//ɾ����pos��λ���ϵĽڵ㣬pos��1��ʼ
void replaceNode(Node * pHead, int pos, char date);//�滻��pos��λ���ϵ������򣬽��������滻Ϊdate��pos��1��ʼ
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
void insertNode(Node * pHead, int pos, char date)  //����һ���ڵ�������Ϊdate,ǰ�����
{
	Node *p, *s;
	int i = 0;
	p = pHead->prior; //pʼ��ָ��β�ڵ� 
	s = (Node *)malloc(sizeof(Node));
	s->date=date;
	while(i < pos - 1) 
	{ 
		i++; 
		p = p->next; 
	} 
	s->prior = p; 
	s->next = p->next;  //��������ʵ���ˡ�
	p->next->prior = s; 
	p->next = s; 
}
void deleteNode(Node * pHead, int pos)//ɾ����pos��λ���ϵĽڵ㣬pos��1��ʼ
{
	Node * L = pHead;
	for (int i = 0; i<pos - 1; i++)  //ѭ������ʱpָ���ɾ���ڵ�
		L = L->next;
	L->prior->next = L->next;
	L->next->prior = L->prior;
	free(L);
}
void replaceNode(Node * pHead, int pos, char date)//�滻��pos��λ���ϵ������򣬽��������滻Ϊdate��pos��1��ʼ
{
	Node * L = pHead;
	for (int i = 0; i<pos - 1; i++)  //ѭ������ʱpָ����滻�ڵ�
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