/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node { //����ü node����
	int key;
	struct node *left; //node ������ ���� left����
	struct node *right; //node ������ ���� right����
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("---------------- [Byeun jaeyun] [2022041046] -------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z': //z or Z�϶�
			initializeBST(&head); //initializeBST�Լ� ȣ��
			break;
		case 'q': case 'Q': //q or Q�϶�
			freeBST(head); //freeBST�Լ� ȣ��
			break;
		case 'n': case 'N': //n or N�϶�
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key); //insert�Լ� ȣ��
			break;
		case 'd': case 'D': //d or D�϶�
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key); //deleteLeafNode�Լ� ȣ��
			break;
		case 'f': case 'F': //f or F�϶�
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key); //
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S': //s or S�϶�
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I': //i or I�϶�
			inorderTraversal(head->left); //inorderTraversal�Լ� ȣ��
			break;
		case 'p': case 'P': //p or P�϶�
			preorderTraversal(head->left); //preorderTraversal�Լ� ȣ��
			break;
		case 't': case 'T': //t or T�϶�
			postorderTraversal(head->left); //postorderTraversal�Լ� ȣ��
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) { //BST�� �ʱ�ȭ ���ִ� �Լ�

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL) //h��尡 ���������
		freeBST(*h); //h ����

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));	//h�� �����޸� �Ҵ�
	(*h)->left = NULL;	//h�� left-child�� NULL�� ����
	(*h)->right = *h;	//h�� right_childe�� �ڽ����� ����
	(*h)->key = -9999;	//h�� key���� -9999�� ����
	return 1;	//1 ��ȯ
}



void inorderTraversal(Node* ptr) //BST�� ������ȸ�ϴ� �Լ�
{
	if(ptr) { //ptr�� NULL�� �ƴҶ�
		inorderTraversal(ptr->left);	//ptr�� left-child�� ������ȸ 
		printf(" [%d] ", ptr->key);		//ptr�� key�� ��� 
		inorderTraversal(ptr->right);	//ptr�� right-childe�� ������ȸ 
	}
}

void preorderTraversal(Node* ptr) //BST�� ������ȸ �ϴ� �Լ�
{
	if(ptr) { //ptr�� NULL�� �ƴҶ�
		printf(" [%d] ", ptr->key); 	//ptr�� key�� ��� 
		preorderTraversal(ptr->left);	//ptr�� left-child�� ������ȸ 
		preorderTraversal(ptr->right);	//ptr�� right-childe�� ������ȸ 
	}
}

void postorderTraversal(Node* ptr) //BST�� ������ȸ �ϴ� �Լ�
{
	if(ptr) { //ptr�� NULL�� �ƴҶ�
		postorderTraversal(ptr->left);	//ptr�� left-child�� ������ȸ 
		postorderTraversal(ptr->right);	//ptr�� right-childe�� ������ȸ 
		printf(" [%d] ", ptr->key);		//ptr�� key�� ��� 
	}
}


int insert(Node* head, int key) //BST�� ��带 �߰��ϴ� �Լ�
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	//Node ������ ���� newNode�� ������ �����޸� �Ҵ�
	newNode->key = key;	//����ڷκ��� �Է¹��� key�� newNode�� key�� ����
	newNode->left = NULL;	
	newNode->right = NULL;
	//newNode�� left-child�� right-childe�� NULL�� �ʱ�ȭ

	if (head->left == NULL) {	//headnode�� left-child�� ������
		head->left = newNode;	//headnode�� left-child�� newNode ����
		return 1;	//1 ��ȯ
	}

	/* head->left is the root */
	Node* ptr = head->left;
	//Node������ ���� ptr�� head�� left-child ����

	Node* parentNode = NULL;
	//Node ������ ���� parentNode ���� �� �ʱ�ȭ
	while(ptr != NULL) 	//ptr�� ���� NULL�϶����� �ݺ��ϴ� while��
	{
		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;	//ptr�� key���� ����ڷκ��� �Է¹��� key�� ������ 1 ��ȯ

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;
		//parentNode�� ptr ����

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)	//ptr�� key�� ����ڷκ��� �Է¹��� key���� ������
			ptr = ptr->right;	//ptr�� ptr�� right-child�� �Ƶ�
		else	//ptr�� key�� ����ڷκ��� �Է¹��� key���� Ŭ��
			ptr = ptr->left;	//ptr�� ptr�� left-child�� �Ƶ�
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)	//parentNode�� key�� ����ڷκ��� �Է¹��� key���� Ŭ��
		parentNode->left = newNode;	//parentNode�� left-child�� newNode ����
	else	//parentNode�� key�� ����ڷκ��� �Է¹��� key���� ������
		parentNode->right = newNode; //parentNode�� right-child�� newNode ����
	return 1;	//1 ��ȯ
}

int deleteLeafNode(Node* head, int key) //Node�� �����ϴ� �Լ�
{
	if (head == NULL) {	//BST�� �������
		printf("\n Nothing to delete!!\n");	
		return -1;	//-1 ��ȯ
	}

	if (head->left == NULL) {	//head�� left-child�� �������
		printf("\n Nothing to delete!!\n");	
		return -1;	//-1 ��ȯ
	}

	/* head->left is the root */
	Node* ptr = head->left;
	//Node ������ ���� ptr ���� �� head�� left-child ����


	/* we have to move onto children nodes,
	 * keep tracking the parent using parentNode */
	Node* parentNode = head;
	//Node ������ ���� parentNode ���� �� head ����

	while(ptr != NULL) {	//ptr�� NULL�϶����� �ݺ��ϴ� while��

		if(ptr->key == key) {	//ptr�� key���� ����ڷκ��� �Է¹��� key���� ���ٸ�
			if(ptr->left == NULL && ptr->right == NULL) {	//ptr�� left-child�� right-child�� ����ִٸ�

				/* root node case */
				if(parentNode == head)	//parentNode�� head�϶�
					head->left = NULL;	//head�� left-child�� NULL�� �ʱ�ȭ

				/* left node case or right case*/
				if(parentNode->left == ptr)	//parentNode�� left-child�� ptr�϶�
					parentNode->left = NULL;	//parentNode�� left-child�� NULL�� �ʱ�ȭ
				else 	//parentNode�� right-child�� ptr�϶�
					parentNode->right = NULL;	//parentNode�� right-childe�� NULL�� �ʱ�ȭ

				free(ptr);	//ptr�� free
			}
			else {	//ptr�� left-child �� �ְų� right-child �� ������
				printf("the node [%d] is not a leaf \n", ptr->key);	
			}
			return 1;	// 1 ��ȯ
		}

		/* keep the parent node */
		parentNode = ptr;
		//parentNode�� ptr�� ����

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)	//ptr�� key�� ����ڷκ��� �Է¹��� key���� ������
			ptr = ptr->right;	//ptr�� ptr�� right-child�� ����
		else	//ptr�� key�� ����ڷκ��� �Է¹��� key���� Ŭ��
			ptr = ptr->left;	//ptr�� ptr�� left-child�� ����
	}

	//BST�� �ش� key���� ��尡 �������� ������
	printf("Cannot find the node for key [%d]\n ", key);	

	return 1;	// 1 ��ȯ
}


Node* searchRecursive(Node* ptr, int key) //Resursive search �Լ�
{
	if(ptr == NULL)	//ptr�� NULL�϶�
		return NULL;	//NULL ��ȯ

	if(ptr->key < key)	//ptr�� key���� ����ڷκ��� �Է¹��� key�� ���� ������
		ptr = searchRecursive(ptr->right, key);	//ptr�� ptr�� right-childe�� Recursive search�� ��� ����
	else if(ptr->key > key)	//ptr�� key���� ����ڷκ��� �Է¹��� key�� ���� ������
		ptr = searchRecursive(ptr->left, key);	//ptr�� ptr�� left-childe�� Recursive search�� ��� ����

	/* if ptr->key == key */
	return ptr;	//ptr ��ȯ

}


Node* searchIterative(Node* head, int key) //Iterative search �Լ�
{
	/* root node */
	Node* ptr = head->left;
	//Node ������ ���� ptr�� head�� left-child ����

	while(ptr != NULL)	//ptr�� NULL�϶����� �ݺ��ϴ� while�� ����
	{
		if(ptr->key == key)	//ptr�� key���� ����ڷκ��� �Է¹��� key���� ������
			return ptr;	//ptr ��ȯ

		if(ptr->key < key) //ptr�� key���� ����ڷκ��� �Է¹��� key�� ���� ������
			ptr = ptr->right;	//ptr�� ptr�� right-child�� �̵�
		else	//ptr�� key���� ����ڷκ��� �Է¹��� key�� ���� Ŭ��
			ptr = ptr->left;	//ptr�� ptr�� left-child�� �̵�
	}

	return NULL;	//NULL ��ȯ
}


void freeNode(Node* ptr)//��带 free���ִ� �Լ�
{
	if(ptr) {	//ptr�� NULL�� �ƴҶ�
		freeNode(ptr->left);	//ptr�� left-child�� free
		freeNode(ptr->right);	//ptr�� right-child�� free
		free(ptr);	//ptr�� free
	}
}


int freeBST(Node* head) //BST�� free���ִ� �Լ�
{

	if(head->left == head)	//head�� left-child�� head�϶�
	{
		free(head);	//head���� 
		return 1;	//1 ��ȯ
	}

	Node* p = head->left; //Node ������ ���� p��  head�� left-child�� ����

	freeNode(p);	//p ����
	free(head);	//head ����
	return 1;	// 1 ��ȯ
}