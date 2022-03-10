#ifndef LIST_H
#define LIST_H
#include "portmacro.h"
struct xLIST_ITEM
{
	TickType_t xItem_Value;     		/*辅助用于节点做顺序排列*/
	struct xLIST_ITEM *pxNext;			/*指向下一个节点*/
	struct xLIST_ITEM *pxPrevious;	/*指向下一个节点*/
	void *pvOwner;									/*指向节点的内核对象*/
	void *pvContainer;							/*指向节点所在的链表*/
	
};

	
typedef struct xLIST_ITEM ListItem_t; //节点数据类型重定义



struct xMINT_LIST_ITEM
{
	TickType_t xItemValue;
	struct xLIST_ITEM *pxNext;
	struct xLIST_ITEM *pxPrevious;
};
typedef struct xMINT_LIST_ITEM MiniListItem_t;

typedef struct xLIST
{
	UBaseType_t uxNumberofItems;    		/*计数器*/
	ListItem_t *pxIndex;								/*索引指针*/
	MiniListItem_t xListEnd;						/*最后一个节点*/
	
}List_t;

void vListInitialiseItem( ListItem_t * const pxItem );
void vListInitialise(List_t * const pxList);
void xListInsertEnd(List_t * const pxList, ListItem_t * const pxNewListItem);
void xListInsert( List_t * const pxList, ListItem_t * const pxNewListItem);

#endif