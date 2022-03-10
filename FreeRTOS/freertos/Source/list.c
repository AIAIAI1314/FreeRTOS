#include "list.h"
void vListInitialiseItem(ListItem_t *const pxItem)  //链表节点初始化
{
	pxItem -> pvContainer = NULL;  //初始化该节点所在的链表位空，该节点没有插入任何链表
}
void vListInitialise(List_t *const pxList)
{
	pxList -> pxIndex = (ListItem_t *)&(pxList -> xListEnd);
	pxList -> xListEnd.xItemValue = portMAX_DELAY;
	pxList -> xListEnd.pxNext = (ListItem_t *)&(pxList -> xListEnd );
	pxList -> xListEnd.pxPrevious = (ListItem_t *)&(pxList -> xListEnd);
	pxList -> uxNumberofItems = (UBaseType_t) 0U;
	
}
void vListInsertEnd(List_t * const pxList,ListItem_t * const pxNewListItem)
{
	ListItem_t * pxIndex = pxList -> pxIndex;
	//ListItem_t const * pxIndex = pxList -> pxIndex;   //源码，但const不能作为左值？
	pxNewListItem->pxNext = pxIndex;
	pxNewListItem->pxPrevious = pxIndex->pxPrevious;
	pxNewListItem->pvContainer = ( void * ) pxList;
	( pxList->uxNumberofItems)++;
}
void vListInsert(List_t * const pxList, ListItem_t * const pxNewListItem)
{
 
}