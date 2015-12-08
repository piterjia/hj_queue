//
//  hj_queue.h
//  DctCache
//
//  Created by hongjunjia on 15/12/8.
//  Copyright © 2015年 hongjunjia. All rights reserved.
//

#ifndef hj_queue_h
#define hj_queue_h



/*----------------------------------------------------------------------------*/
/*                         Include Files                                	  */
/*----------------------------------------------------------------------------*/

#include "hj_queue_ext.h"
/**---------------------------------------------------------------------------*
**                         Compiler Flag                                     *
**---------------------------------------------------------------------------*/
#ifdef __cplusplus
extern   "C"
{
#endif

/*----------------------------------------------------------------------------*/
/*                         TYPE DEFINITION                                	  */
/*----------------------------------------------------------------------------*/

typedef struct _FT_QUEUE_T
{
    uint32*             buffer;             //buffer
    uint32              capacity;           //queue的总长度
    uint32              elem_num;           //当前queue里面所有元素的长度
    uint32              front;
    uint32              rear;
    DestructElement     destruct_func;      //queue中每个元素的析构函数
};

/**--------------------------------------------------------------------------*
 **                         FUNCTION DEFINITION                              *
 **--------------------------------------------------------------------------*/

/*****************************************************************************/
//  Description :  add a element to the queue buffer
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note: index对应queue buffer 的物理索引，0 对应buffer第一个obj，
//        quene_ptr->len-1对应buffer最后一个obj
/*****************************************************************************/
BOOLEAN ObjAdd(FT_QUE_PTR queue_ptr, uint32 index, uint32 elem);

/*****************************************************************************/
//  Description :  free a element of queue buffer
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note: index对应queue buffer的物理索引，0 对应buffer第一个obj，
//        quene_ptr->len-1对应buffer最后一个obj
/*****************************************************************************/
BOOLEAN ObjFree(FT_QUE_PTR queue_ptr, uint32 index);

/*----------------------------------------------------------------------------*/
/*                         MACRO DEFINITION                                   */
/*----------------------------------------------------------------------------*/


/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif


#endif /* hj_queue_h */
