//
//  hj_queue.c
//  DctCache
//
//  Created by hongjunjia on 15/12/8.
//  Copyright © 2015年 hongjunjia. All rights reserved.
//


/**---------------------------------------------------------------------------*
 **                         Dependencies                                      *
 **---------------------------------------------------------------------------*/
#include "hj_queue.h"
#include "hj_queue_ext.h"

/**--------------------------------------------------------------------------*
 **                         MACRO DEFINITION                                 *
 **--------------------------------------------------------------------------*/

/**--------------------------------------------------------------------------*
 **                         EXTERNAL DECLARE                                 *
 **--------------------------------------------------------------------------*/

/**-------------------------------------------------------------------------*
 **                         GLOBAL DEFINITION                                *
 **--------------------------------------------------------------------------*/

/**--------------------------------------------------------------------------*
 **                         FUNCTION DEFINITION                              *
 **--------------------------------------------------------------------------*/
/*****************************************************************************/
//  Description :  create queue
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note: return ft_que_ptr if create succ, else return PNULL
/*****************************************************************************/
FT_QUE_PTR MMIFT_QueCreate(uint32 len, DestructElement func)
{
    FT_QUE_PTR queue_ptr = PNULL;
    queue_ptr = (FT_QUE_PTR)MEM_ALLOC(sizeof(FT_QUE_T));
    
    if (queue_ptr)
    {
        queue_ptr->buffer = (uint32*)MEM_ALLOC(sizeof(uint32) * len);
        if (queue_ptr->buffer)
        {
            queue_ptr->capacity = len;
            queue_ptr->front = queue_ptr->rear = 0;
            queue_ptr->elem_num = 0;
            queue_ptr->destruct_func = func;
        }
        else
        {
            MEM_FREE(queue_ptr);
        }
    }
    
    return queue_ptr;
}

/*****************************************************************************/
//  Description :  empty queue
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueEmpty(FT_QUE_PTR queue_ptr)
{
    if (!queue_ptr || !queue_ptr->buffer)
    {
        return FALSE;
    }
    //先析构节点内的对象
    if (queue_ptr->destruct_func)
    {
        uint32 i = 0;
        uint32  obj_ptr = 0;
        for (i=0; i < queue_ptr->elem_num; i++)
        {
            obj_ptr = MMIFT_QueGetAt(queue_ptr, i);
            if (obj_ptr)
            {
                queue_ptr->destruct_func((void*)obj_ptr);
            }
        }
    }
    //queue的状态reset
    queue_ptr->front = queue_ptr->rear = 0;
    queue_ptr->elem_num = 0;
    //SCI_MEMSET(queue_ptr->buffer, NULL, queue_ptr->buffer_len);
    
    return TRUE;
}

/*****************************************************************************/
//  Description :  destroy queue
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueDestory(FT_QUE_PTR queue_ptr)
{
    if (!queue_ptr || !queue_ptr->buffer)
    {
        return FALSE;
    }
    MMIFT_QueEmpty(queue_ptr);
    //析构节点缓冲
    MEM_FREE(queue_ptr->buffer);
    //析构queue对象
    MEM_FREE(queue_ptr);
    
    return TRUE;
}

/*****************************************************************************/
//  Description :  get element of queue
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:  这个index为对外的，0 即为queue front
/*****************************************************************************/
uint32 MMIFT_QueGetAt(FT_QUE_PTR queue_ptr, uint32 index)
{
    int i = 0;
    
    if (index >= queue_ptr->elem_num)
    {
        return -1;
    }
    i = (queue_ptr->front + index) % queue_ptr->capacity;
    
    return queue_ptr->buffer[i];
}

/*****************************************************************************/
//  Description :  add a element to the queue buffer
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note: index对应queue buffer 的物理索引，0 对应buffer第一个obj，
//        quene_ptr->len-1对应buffer最后一个obj
/*****************************************************************************/
BOOLEAN ObjAdd(FT_QUE_PTR queue_ptr, uint32 index, uint32 elem)
{
    if (!queue_ptr || index > queue_ptr->capacity - 1)
    {
        return FALSE;
    }
    /* if we empty the queue first, we must can add data*/
    //     if (!queue_ptr->buffer[index])
    //     {
    queue_ptr->buffer[index] = elem;
    
    return TRUE;
    //    }
}

/*****************************************************************************/
//  Description :  free a element of queue buffer
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note: index对应queue buffer的物理索引，0 对应buffer第一个obj，
//        quene_ptr->len-1对应buffer最后一个obj
/*****************************************************************************/
BOOLEAN ObjFree(FT_QUE_PTR queue_ptr, uint32 index)
{
    if (!queue_ptr || index > queue_ptr->capacity - 1)
    {
        return FALSE;
    }
    if (queue_ptr->buffer[index] && queue_ptr->destruct_func)
    {
        queue_ptr->destruct_func((void*)queue_ptr->buffer[index]);
        queue_ptr->buffer[index] = PNULL;
    }
    //清空节点数据
    //queue_ptr->buffer[index] = NULL;
    
    return TRUE;
}

/*****************************************************************************/
//  Description :  append element of queue in the front
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueFrontAppend(FT_QUE_PTR queue_ptr, uint32 elem)
{
    BOOLEAN result = FALSE;
    
    if (!queue_ptr)
    {
        return FALSE;
    }
    
    if (0 != queue_ptr->elem_num)
    {
        //front 调整
        if (!queue_ptr->front)
        {
            queue_ptr->front = queue_ptr->capacity - 1;
        }
        else
        {
            queue_ptr->front--;
        }
        
        //判断队满
        if (queue_ptr->rear == queue_ptr->front)
        {
            //free rear
            ObjFree(queue_ptr, queue_ptr->rear);
            if (!queue_ptr->rear)
            {
                queue_ptr->rear = queue_ptr->capacity - 1;
            }
            else
            {
                queue_ptr->rear--;
            }
        }
        else
        {
            queue_ptr->elem_num++;
        }
    }
    else
    {
        queue_ptr->elem_num++;
    }
    
    //写新节点
    result = ObjAdd(queue_ptr, queue_ptr->front, elem);

    
    return result;
    
}
/*****************************************************************************/
//  Description :  append element of queue in the rear
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueRearAppend(FT_QUE_PTR queue_ptr, uint32 elem)
{
    BOOLEAN result = FALSE;
    
    if (!queue_ptr)
    {
        return FALSE;
    }
    
    if (0 != queue_ptr->elem_num)
    {
        //rear 调整
        queue_ptr->rear = (++queue_ptr->rear) % queue_ptr->capacity;
        
        //判断队满
        if (queue_ptr->front == queue_ptr->rear)
        {
            ObjFree(queue_ptr, queue_ptr->front);
            queue_ptr->front = (++queue_ptr->front) % queue_ptr->capacity;
        }
        else
        {
            queue_ptr->elem_num++;
        }
    }
    else
    {
        queue_ptr->elem_num++;
    }
    
    //添加节点
    result = ObjAdd(queue_ptr,queue_ptr->rear, elem);
    
    
    return result;
}

/*****************************************************************************/
//  Description :  get the elem num of the queue
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
uint32 MMIFT_QueGetElemNum(FT_QUE_PTR queue_ptr)
{
    if (queue_ptr)
    {
        return queue_ptr->elem_num;
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************/
//  Description :  get queue total length(capacity)
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
uint32 MMIFT_QueGetCapacity(FT_QUE_PTR queue_ptr)
{
    if (queue_ptr)
    {
        return queue_ptr->capacity;
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************/
//  Description :  is queue full
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueIsFull (FT_QUE_PTR queue_ptr)
{
    if (queue_ptr)
    {
        return (0 != queue_ptr->elem_num && queue_ptr->elem_num == queue_ptr->capacity);
    }
    else
    {
        return TRUE;
    }
}

/*****************************************************************************/
//  Description :  is queue full
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueIsEmpty (FT_QUE_PTR queue_ptr)
{
    if (queue_ptr)
    {
        return (0 == queue_ptr->elem_num );
    }
    else
    {
        return FALSE;
    }
}

/*****************************************************************************/
//  Description :  get the front of the queue
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note: just for test
/*****************************************************************************/
uint32 MMIFT_QueFrontGet (FT_QUE_PTR queue_ptr)
{
    if (queue_ptr)
    {
        return queue_ptr->front;
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************/
//  Description :  get the rear of the queue
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
uint32 MMIFT_QueRearGet (FT_QUE_PTR queue_ptr)
{
    if (queue_ptr)
    {
        return queue_ptr->rear;
    }
    else
    {
        return 0;
    }	
}

