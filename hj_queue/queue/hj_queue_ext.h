//
//  hj_queue_ext.h
//  DctCache
//
//  Created by hongjunjia on 15/12/8.
//  Copyright © 2015年 hongjunjia. All rights reserved.
//

#ifndef hj_queue_ext_h
#define hj_queue_ext_h


/*----------------------------------------------------------------------------*/
/*                         Include Files                                	  */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include "hj_common.h"

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
/* queue 中元素析构函数类型声明*/
typedef void (*DestructElement)(void *ptr);

/*  quque 结构体与指针声明*/
typedef struct _FT_QUEUE_T FT_QUE_T, *FT_QUE_PTR;


/*----------------------------------------------------------------------------*/
/*                         MACRO DEFINITION                                   */
/*----------------------------------------------------------------------------*/
/* used for debug of FT task*/
#define   FT_DEBUG
/*----------------------------------------------------------------------------*/
/*                         FUNCTION DECLARATION                               */
/*----------------------------------------------------------------------------*/
/*****************************************************************************/
//  Description :  create queue
//  Global resource dependence :
//  Author: hongjun.jia
//  Note:
/*****************************************************************************/
FT_QUE_PTR MMIFT_QueCreate(uint32 len, DestructElement func);

/*****************************************************************************/
//  Description :  empty queue
//  Global resource dependence :
//  Author: hongjun.jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueEmpty(FT_QUE_PTR queue_ptr);

/*****************************************************************************/
//  Description :  destroy queue
//  Global resource dependence :
//  Author: hongjun.jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueDestory(FT_QUE_PTR queue_ptr);

/*****************************************************************************/
//  Description :  get element of queue
//  Global resource dependence :
//  Author: hongjun.jia
//  Note:
/*****************************************************************************/
uint32 MMIFT_QueGetAt(FT_QUE_PTR queue_ptr, uint32 index);

/*****************************************************************************/
//  Description :  append element of queue in the front
//  Global resource dependence :
//  Author: hongjun.jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueFrontAppend(FT_QUE_PTR queue_ptr, uint32 elem);

/*****************************************************************************/
//  Description :  append element of queue in the rear
//  Global resource dependence :
//  Author: hongjun.jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueRearAppend(FT_QUE_PTR queue_ptr, uint32 elem);

/*****************************************************************************/
//  Description :  get the elem num of the queue
//  Global resource dependence :
//  Author: hongjun.jia
//  Note:
/*****************************************************************************/
uint32 MMIFT_QueGetElemNum(FT_QUE_PTR queue_ptr);

/*****************************************************************************/
//  Description :  get queue total length(capacity)
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
uint32 MMIFT_QueGetCapacity(FT_QUE_PTR queue_ptr);

/*****************************************************************************/
//  Description :  is queue full
//  Global resource dependence :
//  Author: hongjun.jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueIsFull (FT_QUE_PTR queue_ptr);

/*****************************************************************************/
//  Description :  is queue full
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
BOOLEAN MMIFT_QueIsEmpty (FT_QUE_PTR queue_ptr);

#ifdef FT_DEBUG
/*****************************************************************************/
//  Description :  get the front of the queue
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note: just for test
/*****************************************************************************/
uint32 MMIFT_QueFrontGet (FT_QUE_PTR queue_ptr);

/*****************************************************************************/
//  Description :  get the rear of the queue
//  Global resource dependence :
//  Author: Hongjun.Jia
//  Note:
/*****************************************************************************/
uint32 MMIFT_QueRearGet (FT_QUE_PTR queue_ptr);
#endif

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif


#endif /* hj_queue_ext_h */
