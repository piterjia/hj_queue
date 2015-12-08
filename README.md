# hj_queue
c语言实现的强大队列缓存：

包括的功能主要用：

1、可以存储任何数据，基本类型，自定义类型等；

2、包含的函数以及功能如下：

（1）//create queue

FT_QUE_PTR MMIFT_QueCreate(uint32 len, DestructElement func);

（2）//empty queue

BOOLEAN MMIFT_QueEmpty(FT_QUE_PTR queue_ptr);

（3）//destroy queue

BOOLEAN MMIFT_QueDestory(FT_QUE_PTR queue_ptr);

（4）//get element of queue

uint32 MMIFT_QueGetAt(FT_QUE_PTR queue_ptr, uint32 index);

（5）//append element of queue in the front

BOOLEAN MMIFT_QueFrontAppend(FT_QUE_PTR queue_ptr, uint32 elem);

（6）//append element of queue in the rear

BOOLEAN MMIFT_QueRearAppend(FT_QUE_PTR queue_ptr, uint32 elem);

（7）//get the elem num of the queue

uint32 MMIFT_QueGetElemNum(FT_QUE_PTR queue_ptr);

（8）//get queue total length(capacity)

uint32 MMIFT_QueGetCapacity(FT_QUE_PTR queue_ptr);

（9）//is queue full

BOOLEAN MMIFT_QueIsFull (FT_QUE_PTR queue_ptr);

（10）//is queue empty

BOOLEAN MMIFT_QueIsEmpty (FT_QUE_PTR queue_ptr);

（11）//get the front of the queue

uint32 MMIFT_QueFrontGet (FT_QUE_PTR queue_ptr);


（12）//get the rear of the queue

uint32 MMIFT_QueRearGet (FT_QUE_PTR queue_ptr);
