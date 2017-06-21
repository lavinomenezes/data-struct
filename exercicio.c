#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef int vetor;
 typedef struct{
 	 vetor V[MAX];//criar um elemento de vetores, por isso a declaração mais cedo
 	int n;
 }tlista;

void criarLista(tlista *lista){
	lista->n=0;
}
int tamanho(tlista lista){
	return lista.n;
}
void inserirFinal(tlista *lista, vetor Z){
 	lista->V[lista->n] = Z;
 	lista->n=lista->n+1;
 }
void inserirpos(tlista*lista, int pos, vetor Z){
	int i;
		if(pos>=lista->n){
			inserirFinal(lista,Z);// perguntar sobre lixo de memoria;
		}
		else{
			for(i=lista->n;i>pos;i--){
				lista->V[i]=lista->V[i-1];
			}
		
		lista->V[pos] = Z;
		lista->n = lista->n + 1;
		}
}

void inseririnicio(tlista*lista, vetor Z){
	inserirpos(lista,0,Z);
}
void imprimir(tlista * lista){
	vetor Z;
	int i;
	for(i=0;i<lista->n;i++){
		Z = lista->V[i];
		printf("%d\n", Z);
	}
}
void destruir(tlista * lista){
	lista->n=0;
}
void exibirElem(tlista * lista, int pos){
	vetor Z;
	Z = lista->V[pos];
	printf("o elemento na posicao %d  -> %d\n", pos, Z);
}
void exibirpos(tlista * lista, vetor Z){
	int i;
	for(i=0;i<lista->n;i++){
		if(Z==lista->V[i])
		printf("a posicao do elmento -> %d\n", i);
		
	}
}












int main(){
	tlista lista;
	int x=0, Z, pos;
	
	do{
	
		printf("digite 1 para criar lista\n");
		printf("digite 2 para verificar tamanho\n");
		printf("digite 3 para Inserir final\n");
		printf("digite 4 para Imprimir\n");
		printf("digite 5 para inserir em determinada posicao\n");
		printf("digite 6 para inserir no inicio\n");
		printf("digite 7 para eliminar a lista\n");
		printf("digite 8 Exibir elemento\n");
		printf("digite 9 Exibir posicao\n");
		scanf("%d", &x);
		switch(x){
			case 1:
				criarLista(&lista);
				break;
			case 2:
				printf("o tamanho da lista -> %d\n",tamanho(lista));
				break;
			case 3:
				printf("Insira: ");
				scanf("%d", &Z);
				inserirFinal(&lista,Z);
				break;
			case 4:
				imprimir(&lista);
				break;
			case 5:
				printf("insira a posicao: ");
				scanf("%d", &pos);
				fflush(stdin);
				printf("insira o elemento: ");
				scanf("%d", &Z);
				inserirpos(&lista, pos, Z);
				break;
			case 6:
				printf("insira o elemento: ");
				scanf("%d", &Z);
				inseririnicio(&lista,Z);
				break;	
			case 7:
				destruir(&lista);
				printf("\n");
				printf("lista destruida\n");
				break;
			case 8:
				printf("insira a posicao: ");
				scanf("%d", &pos);
				exibirElem(&lista,pos);
				break;
			case 9:
				printf("insira o elemento que deseja descrobrir a posicao: ");
				scanf("%d", &Z);
				exibirpos(&lista,Z);
				break;
		}
	}
	while(x!=15);
	
	
	return 0;
}
