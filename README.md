# hj_queue
c语言实现的强大队列缓存：
包括的功能主要用：
（1）可以存储任何数据，基本类型，自定义类型等；

（2）包含的函数如下：

FT_QUE_PTR MMIFT_QueCreate(uint32 len, DestructElement func);

BOOLEAN MMIFT_QueEmpty(FT_QUE_PTR queue_ptr);

BOOLEAN MMIFT_QueDestory(FT_QUE_PTR queue_ptr);

uint32 MMIFT_QueGetAt(FT_QUE_PTR queue_ptr, uint32 index);

BOOLEAN MMIFT_QueFrontAppend(FT_QUE_PTR queue_ptr, uint32 elem);

BOOLEAN MMIFT_QueRearAppend(FT_QUE_PTR queue_ptr, uint32 elem);

uint32 MMIFT_QueGetElemNum(FT_QUE_PTR queue_ptr);

uint32 MMIFT_QueGetCapacity(FT_QUE_PTR queue_ptr);

BOOLEAN MMIFT_QueIsFull (FT_QUE_PTR queue_ptr);

BOOLEAN MMIFT_QueIsEmpty (FT_QUE_PTR queue_ptr);

uint32 MMIFT_QueFrontGet (FT_QUE_PTR queue_ptr);

uint32 MMIFT_QueRearGet (FT_QUE_PTR queue_ptr);
