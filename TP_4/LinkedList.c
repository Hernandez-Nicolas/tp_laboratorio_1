#include"LinkedList.h"

eLinkedList* Ll_newLinkedList(void){
	eLinkedList* newLinkedList;
	newLinkedList=(eLinkedList*)malloc(sizeof(eLinkedList));
	newLinkedList->pFirstNode=NULL;
	newLinkedList->size=0;
	return newLinkedList;
}

int Ll_len(eLinkedList* this){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		retorno=this->size;
	}
	return retorno;
}

static Node* GetNode(eLinkedList* this, int nodeIndex){
	Node* aux;
	Node* thisNode;
	thisNode=NULL;
	if(this!=NULL&&nodeIndex>0&&nodeIndex<=this->size){
		aux=this->pFirstNode;
		for(int i=0;i<nodeIndex;i++){
			if(i==nodeIndex-1){
				thisNode=aux;
			}
			else{
				aux=aux->pNetxNode;
			}
		}
	}
	return thisNode;
}

static int AddNode(eLinkedList* this, int nodeIndex, void* pDato){
	int retorno;
	Node* aux;
	Node* aux2;
	Node* newNode;
	retorno=ERROR;
	if(this!=NULL&&nodeIndex>0&&nodeIndex<=this->size){
		newNode=(Node*)malloc(sizeof(Node));
		newNode->pElemento=pDato;
		newNode->pNetxNode=NULL;
		aux=this->pFirstNode;
		for(int i=0;i<this->size;i++){
			if(i==this->size-1){
				aux2=aux->pNetxNode;
				aux->pNetxNode=newNode;
				newNode->pNetxNode=aux2;
				retorno=0;
				break;
			}
			else{
				aux=aux->pNetxNode;
			}
		}
	}
	return retorno;
}

int Ll_add(eLinkedList* this, void* pDato){
	Node* oldNode;
	Node* newNode;
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		newNode=(Node*)malloc(sizeof(Node));
		newNode->pElemento=pDato;
		newNode->pNetxNode=NULL;
		if(this->pFirstNode==NULL){
			this->pFirstNode=newNode;
		}
		else{
			oldNode=this->pFirstNode;
			for(int i=0;i<this->size;i++){
				if(oldNode->pNetxNode==NULL){
					oldNode->pNetxNode=newNode;
					this->size++;
					retorno=0;
				}
				else{
					oldNode=oldNode->pNetxNode;
				}
			}
		}
	}
	return retorno;
}

void* Ll_get(eLinkedList* this, int index){
	Node* aux;
	Node* thisDato;
	thisDato=NULL;
	if(this!=NULL&&index>0&&index<=this->size){
		aux=this->pFirstNode;
		for(int i=0;i<this->size;i++){
			if(i==index-1){
				thisDato->pElemento=aux->pElemento;
				break;
			}
			else{
				aux=aux->pNetxNode;
			}
		}
	}
	return thisDato->pElemento;
}

int Ll_set(eLinkedList* this, int index, void* pDato){
	Node* aux;
	int retorno;
	retorno=ERROR;
	if(this!=NULL&&index>0&&index<=this->size){
		aux=this->pFirstNode;
		for(int i=0;i<this->size;i++){
			if(i==index-1){
				aux->pElemento=pDato;
				retorno=0;
				break;
			}
			else{
				aux=aux->pNetxNode;
			}
		}
	}
	return retorno;
}

int Ll_remove(eLinkedList* this, int index){
	Node* aux;
	Node* aux2;
	Node* remove;
	int retorno;
	retorno=ERROR;
	if(this!=NULL&&index>0&&index<this->size){
		remove=this->pFirstNode;
		for(int i=0;i<this->size;i++){
			if(i==index-1){
				if(i==0){
					aux2=GetNode(this,index+1);
					this->pFirstNode=aux2;
					free(remove);
					retorno=0;
					break;
				}
				else{
					aux=GetNode(this,index-1);
					aux2=GetNode(this,index+1);
					aux->pNetxNode=aux2;
					free(remove);
					retorno=0;
					break;
				}
			}
			else{
				remove=remove->pNetxNode;
			}
		}
	}
	return retorno;
}

int Ll_clear(eLinkedList* this){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		for(int i=0;i<this->size;i++){
			Ll_remove(this,i+1);
		}
		retorno=0;
	}
	return retorno;
}

int Ll_deleteLinkedList(eLinkedList* this){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		Ll_clear(this);
		free(this);
		retorno=0;
	}
	return retorno;
}

int Ll_indexOf(eLinkedList* this, void* pDato){
	int retorno;
	Node* thisNode;
	retorno=ERROR;
	if(this!=NULL){
		thisNode=this->pFirstNode;
		for(int i=0;i<this->size;i++){
			if(thisNode->pElemento==pDato){
				retorno=i+1;
				break;
			}
			else{
				thisNode=thisNode->pNetxNode;
			}
		}
	}
	return retorno;
}

int Ll_isEmty(eLinkedList* this){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		if(this->pFirstNode==NULL){
			retorno=0;
		}
		else{
			retorno=1;
		}
	}
	return retorno;
}

int Ll_push(eLinkedList* this, int index, void* pDato){
	int retorno;
	retorno=ERROR;
	return retorno;
}

void* Ll_pop(eLinkedList* this, int index){
	Node* nodo;
	return nodo->pElemento;
}

int Ll_contain(eLinkedList* this, void* pDato){
	int retorno;
	retorno=ERROR;
	return retorno;
}

int Ll_containsAll(eLinkedList* this, eLinkedList* this2){
	int retorno;
	retorno=ERROR;
	return retorno;
}

eLinkedList* Ll_subList(eLinkedList* this, int from, int to){
	eLinkedList* lista;
	return lista;
}

eLinkedList* Ll_clone(eLinkedList* this){
	eLinkedList* lista;
	return lista;
}

int Ll_sort(eLinkedList* this, int (*pFunc)(void*,void*), int order){
	int retorno;
	retorno=ERROR;
	return retorno;
}
