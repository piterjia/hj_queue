# hj_queue
c语言实现的强大队列缓存：
包括的功能主要用：
（1）可以存储任何数据，基本类型，自定义类型等；

（2）包含的函数如下：

创建队列
//create queue
FT_QUE_PTR MMIFT_QueCreate(uint32 len, DestructElement func);

清空队列
//empty queue
BOOLEAN MMIFT_QueEmpty(FT_QUE_PTR queue_ptr);

销毁队列
//destroy queue
BOOLEAN MMIFT_QueDestory(FT_QUE_PTR queue_ptr);

获取队列中索引为index的元素
//get element of queue
uint32 MMIFT_QueGetAt(FT_QUE_PTR queue_ptr, uint32 index);

向队列的前面添加元素
//append element of queue in the front
BOOLEAN MMIFT_QueFrontAppend(FT_QUE_PTR queue_ptr, uint32 elem);

向队列的尾部添加元素
//append element of queue in the rear
BOOLEAN MMIFT_QueRearAppend(FT_QUE_PTR queue_ptr, uint32 elem);

获取队列的元素个数
//get the elem num of the queue
uint32 MMIFT_QueGetElemNum(FT_QUE_PTR queue_ptr);

//get queue total length(capacity)
uint32 MMIFT_QueGetCapacity(FT_QUE_PTR queue_ptr);

//is queue full
BOOLEAN MMIFT_QueIsFull (FT_QUE_PTR queue_ptr);

//is queue empty
BOOLEAN MMIFT_QueIsEmpty (FT_QUE_PTR queue_ptr);

//get the front of the queue
uint32 MMIFT_QueFrontGet (FT_QUE_PTR queue_ptr);

//get the rear of the queue
uint32 MMIFT_QueRearGet (FT_QUE_PTR queue_ptr);
