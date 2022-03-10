#include "list.h"
void vListInitialiseItem(ListItem_t *const pxItem)  //����ڵ��ʼ��
{
	pxItem -> pvContainer = NULL;  //��ʼ���ýڵ����ڵ�����λ�գ��ýڵ�û�в����κ�����
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
	//ListItem_t const * pxIndex = pxList -> pxIndex;   //Դ�룬��const������Ϊ��ֵ��
	pxNewListItem->pxNext = pxIndex;
	pxNewListItem->pxPrevious = pxIndex->pxPrevious;
	pxNewListItem->pvContainer = ( void * ) pxList;
	( pxList->uxNumberofItems)++;
}
void vListInsert(List_t * const pxList, ListItem_t * const pxNewListItem)
{
 
}