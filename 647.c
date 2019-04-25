void LevelTraversal(BinaryTree *pTree)
{
	if(pTree == NULL)return;

	//���븨������
	Queue *pQueue = NULL;
	q_Init(&pQueue);

	//�����
	q_Push(pQueue,pTree);

	while(!q_IsEmpty(pQueue)){
		//����
		pTree = q_Pop(pQueue);
		//��ӡ
		printf("%d ",pTree->nValue);
		//�ǿ��������
		if(pTree->pLeft != NULL){
			q_Push(pQueue,pTree->pLeft);
		}

		if(pTree->pRight != NULL){
			q_Push(pQueue,pTree->pRight);
		}
	}
