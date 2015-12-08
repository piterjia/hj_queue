# hj_queue
c语言实现的强大队列缓存：
包括的功能主要用：
（1）可以存储任何数据，基本类型，自定义类型等
（2）包含的函数有：

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
//  Note: 
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
