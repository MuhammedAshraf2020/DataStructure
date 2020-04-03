#define MaxQueue 
#define QueueEntry

typedef struct  queue{
// Queue Struct 

	QueueEntry arr[MaxQueue];
	int front;
	int rear;
	int size;
	
}Queue;


void CreateQueue(Queue*pq)
{
	// This Function to initialize Queue
	// param : Adress of The Queue 
	// return: void
	pq->front = 0 ;
	pq->rear  = -1;
	pq->size  = 0 ;

}


void EnQueue(QueueEntry e , Queue*pq)
{
	// This Function to Add elements in Queue
	// param : element which you want to enter
	// return: 1 if mission suc : 0 if mission field
	if (!QueueFull(pq)){

	pq->rear = (pq->rear+1) % MaxQueue;
	pq->arr[pq->rear] = e;
	++pq->size;
	return 1;
	                   }
	else
	{return 0;}
}


void DeQueue(QueueEntry *pe , Queue *pq )
{
	//This Function to Get The First element in the Queue
	//param : address of Queue , Address of variable which you want to store in
	//return:1 if mission Suc  , 0 if the mission faild 
    if(!QueueFull(pq))
    {
    *pe = pq->arr[pq->front];
    pq->front = (pq->front+1) % MaxQueue ;
    --pq->size;
    return 1;}

    else
    {return 0;}
}

int QueueFull(Queue *pq)
{
	//This Function to return if the Queue if Full
    return pq->size == 0; 
}

int QueueEmpty(Queue *pq)
{
	//This Function to return if the Queue if Empty 
    return pq->size == MaxQueue - 1;
}

void ReverseQueue( Queue *pq , void(*pf)(QueueEntry) )
{
	for(int i = pq->front , int s = 0; s<pq->size ; s++)
	{
		(*pf)(pq->arr[i]);
		i = (i+1) % MaxSize;

	}

void ClearQueue(Queue*pq)
{
	//This Function To Clear Queue
	pq->front = 0 ;
	pq->rear  = -1;
	pq->size  = 0 ;
}
}
