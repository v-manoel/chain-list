#include <stdlib.h>
#include <stdio.h>

typedef struct Gomo{
	int dado;
	struct Gomo *proxgomo;
	struct Gomo *pastgomo;
}Gomo;

void InserirGomos(Gomo **inicio, int dado);
void RetirarGomos(Gomo **inicio);
void ListarGomos(Gomo **inicio);

int main(){
	int dado;
	Gomo *inicio = NULL;
	char Opcao = 'e';
	do{
		printf("\t\tEscolha uma opcao:\ni - Para inserir;\n\ne - Para sair;\n\nl - Para listar;\n\n:");
		scanf(" %c",&Opcao);
		system("cls");
		if(Opcao == 'i'){
			printf("Digite o dado a ser inserido:\t");
			scanf("%d",&dado);
			InserirGomos(&inicio,dado);
		}
		else if(Opcao == 'l')
			ListarGomos(&inicio);
	}while(Opcao != 'e');
	
}

void InserirGomos(Gomo **inicio, int dado){
	Gomo *gomoatual,*gomo = NULL;
	gomo = (Gomo*)malloc(sizeof(Gomo));
	if(gomo == NULL)
		return;
	(*gomo).dado = dado;
	
	if(*inicio == NULL){
		(*gomo).proxgomo = NULL;
		(*gomo).pastgomo = NULL;
		*inicio = gomo;
	}
	else{
		gomoatual = *inicio;
	
	//Encadeamento no inicio da corrente;
		if((*gomo).dado <= (*(*inicio)).dado){
			(*(*inicio)).pastgomo = gomo;
			(*gomo).pastgomo = NULL;
			(*gomo).proxgomo = *inicio;
			*inicio = gomo;
	    }
	    else{
		
			while(((*gomoatual).proxgomo != NULL) && ((*gomo).dado > (*gomoatual).dado))
				gomoatual = (*gomoatual).proxgomo;
		//Encadeamento no final da corrente;
		 	if(((*gomoatual).proxgomo == NULL) && ((*gomo).dado > (*gomoatual).dado)){
				(*gomoatual).proxgomo = gomo;
				(*gomo).proxgomo = NULL; 
				(*gomo).pastgomo = gomoatual;
			}
			else{	
		//Encadeamento entre gomos existentes;
				(*gomo).pastgomo = (*gomoatual).pastgomo;
				gomoatual->pastgomo->proxgomo = gomo;
				(*gomo).proxgomo = gomoatual;
				(*gomoatual).pastgomo = gomo;
				
			}
		}	
   }
	
}

void ListarGomos(Gomo **inicio){
	Gomo *printargomo = *inicio;
	do{
		printf("\t%d\t", (*printargomo).dado);
		printargomo = (*printargomo).proxgomo;
	}while((*printargomo).proxgomo != NULL);
}
