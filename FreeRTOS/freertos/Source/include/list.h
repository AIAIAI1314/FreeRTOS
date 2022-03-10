#ifndef LIST_H
#define LIST_H
#include "portmacro.h"
struct xLIST_ITEM
{
	TickType_t xItem_Value;     		/*�������ڽڵ���˳������*/
	struct xLIST_ITEM *pxNext;			/*ָ����һ���ڵ�*/
	struct xLIST_ITEM *pxPrevious;	/*ָ����һ���ڵ�*/
	void *pvOwner;									/*ָ��ڵ���ں˶���*/
	void *pvContainer;							/*ָ��ڵ����ڵ�����*/
	
};

	
typedef struct xLIST_ITEM ListItem_t; //�ڵ����������ض���



struct xMINT_LIST_ITEM
{
	TickType_t xItemValue;
	struct xLIST_ITEM *pxNext;
	struct xLIST_ITEM *pxPrevious;
};
typedef struct xMINT_LIST_ITEM MiniListItem_t;

typedef struct xLIST
{
	UBaseType_t uxNumberofItems;    		/*������*/
	ListItem_t *pxIndex;								/*����ָ��*/
	MiniListItem_t xListEnd;						/*���һ���ڵ�*/
	
}List_t;

void vListInitialiseItem( ListItem_t * const pxItem );
void vListInitialise(List_t * const pxList);
void xListInsertEnd(List_t * const pxList, ListItem_t * const pxNewListItem);
void xListInsert( List_t * const pxList, ListItem_t * const pxNewListItem);

#endif