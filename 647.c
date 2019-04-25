void LevelTraversal(BinaryTree *pTree)
{
	if(pTree == NULL)return;

	//申请辅助队列
	Queue *pQueue = NULL;
	q_Init(&pQueue);

	//根入队
	q_Push(pQueue,pTree);

	while(!q_IsEmpty(pQueue)){
		//弹出
		pTree = q_Pop(pQueue);
		//打印
		printf("%d ",pTree->nValue);
		//非空左右入队
		if(pTree->pLeft != NULL){
			q_Push(pQueue,pTree->pLeft);
		}

		if(pTree->pRight != NULL){
			q_Push(pQueue,pTree->pRight);
		}
	}
