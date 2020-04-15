#define QueueEntry int
#define MaxSize 100

#define Linked_Queue

#ifdef Linked_Queue
/************************************************************************************************************************/
/*												LINKED BASED                                                             /
/************************************************************************************************************************/
typedef struct node
{
	QueueEntry data;
	struct node *next;

}Node;

typedef struct queue
{
	int size;
    Node *front ;
    Node *rear  ;

}Queue;


#else
/************************************************************************************************************************/
/*												ARRAY BASED                                                              /
/************************************************************************************************************************/


typedef struct  queue{
// Queue Struct

	QueueEntry arr[MaxQueue];
	int front;
	int rear;
	int size;

}Queue;


#endif

void CreateQueue(Queue *);

int EnQueue(QueueEntry  , Queue *);

int QueueEmpty(Queue *);

int QueueFull(Queue *);

int DeQueue(QueueEntry * , Queue *);

void ClearQueue(Queue *);

void TraverQueue(QueueEntry(*)(QueueEntry) , Queue *);
