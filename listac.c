#include <stdio.h>
#include <stdlib.h>

struct no {
	int item;
	struct no *prox;
};
typedef struct no Node;

Node* aloca(){
	Node *no = (Node*)malloc(sizeof(Node));
	return no;
}

Node* newNode(){
	Node *node = aloca();
	int num;
	printf("Type a new item:  ");
	scanf("%d",&node->item);
	node->prox = NULL;
}

void add(Node *prim){
	Node *no = prim;
	while (no->prox!=NULL){
		no = no->prox;
	}
	no->prox = newNode();
}

int check(Node *node, int p){
	while (node->prox!=NULL){
		if(node->prox->item==p){
			return 1;
			break;
		}
		node = node->prox;
	}
	return 0;
}

void search(Node *prim){
	int p;
	printf("Type the item to be searched: ");
	scanf("%d",&p);
	(check(prim,p))?printf("\nItem found!!!\n"):printf("\nItem not found!!!\n");
}

void delete(Node *prim){
	int r; Node *node = prim; Node *p;
	printf("Type the item to be removed: ");
	scanf("%d",&r);
	while (node->prox->item!=r){
		node = node->prox;
	}
	p = node->prox;
	node->prox = p->prox;
	free(p);
}

void print(Node *no){
	Node *aux = no->prox;
	printf("\nPrinting items...\n");
	while(aux!=NULL){
		printf("Item: %d \n",aux->item );
		aux = aux->prox;
	}
}

int main(){
	int op;
	Node *list = aloca();
	do{
		printf("\n\tMenu:\n");
		printf( "- Type 0 to leave\n"
				"- Type 1 do add a new item\n"
				"- Type 2 to print the list\n"
				"- Type 3 to delete an item\n"
				"- Type 4 to search for an item\n"
				"\nChoose an option:  ");
		scanf("%d",&op);
		if(op == 1)
			add(list);
		else if(op==2)
			print(list);
		else if(op==3)
			delete(list);
		else if(op==4)
			search(list);
		else if(op==0)
			printf("\nFim da operacao...\n");
		else printf("Invalid option...\n");
	}while(op!=0);
	return 0;
}