typedef struct node
{
	DataEntry data;
	struct node *next;
	
}Node;

typedef struct queue
{
	int size;
    Node *front ;
    Node *rear  ;

}Queue;

void CreateQueue(Queue *pq)
{	
	//This Function to initialization Queue
	//param : Address of Queue
	//return: void
	pq->front = NULL ; 
	pq->rear  = NULL ;
	pq->size  = 0;
}

int EnQueue(int e , Queue *pq)
{
	// This Function to Push Element in Queue
	// param : element Which you want to push  
	// return: 0 if mission faild or 1 if mission suc
	Node *hand = (Node*)malloc(sizeof(Node)); 
	if(!hand)
		return 0;
	else{

	hand->data = e;

	if (pq->size == 0)
	{
		pq->rear  = hand ;
		pq->front = hand;
		++pq->size;
	}
	else{ 
	pq->rear->next = hand;
	pq->rear = hand;
	++pq->size;
	}
}
}
int QueueEmpty(Queue *pq)
{
	// This Function to return if Queue is Empty
	return pq->size == 0;

}
int QueueFull(Queue *pq)
{
	// This Function always return 1
	return 1;
}
int DeQueue(DataEntry *pe , Queue *pq)
{   
	// This Function to get The Front element in the Queue
	// param : ADDRESS of Element , address of Queue 
	// return: 0 if mission faild , 1 if mission suc
    if(!QueueEmpty(pq))
    {
    Node *pn = pq->front;
    *pe = pn->data;
    pq->front = pq->front->next;
    free(pn);
    if (!pq->front)
    {
    	pq->rear = NULL ;
    } 
    --pq->size;
    return 1;
    }  
    else
    {
        return 0;
    }
}

void ClearQueue(Queue *pq)
{
	// Function To Clear passing Queue
while(pq->front)
{
	pq->rear = pq->front;
	free(pq->front);
	pq->front = pq->rear;
}
pq->size = 0;

}

void TraverQueue(DataEntry(*pf)(DataEntry) , Queue *pq)
{
	// Function to applay onther function on every element in the queue
for(Node *pn = pq->front ; pn ; pn = pn->next)
{
	(*pf) (pn->data);
}

}
