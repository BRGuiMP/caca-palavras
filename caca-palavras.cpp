#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>

#define limInferior 0
#define limSuperior 7

#define limInferiorSort 65
#define limSuperiorSort 90

#define TamPala 30
#define QuantPala 25
#define MaxCol 30
#define MaxLinha 30

FILE *nomeArq;

int maxTamPalavra = 0;

enum enumOrientacao{
	paraCima = 0,
	paraCimaDireita = 1,
	paraDireita = 2,
	paraBaixoDireita = 3,
	paraBaixo = 4,
	paraBaixoEsquerda = 5,
	paraEsquerda = 6,
	paraCimaEsquerda = 7
};

struct stPalavrasOcultas{
	char palavra [99]; 
	int linha;
	int coluna;
	enumOrientacao orientacao;
};



int menuEscolha();

int escolheMaxLinha();

int escolheMaxCol();

int escolheMaxPala();

void delay(int);


int main()
{
	SetConsoleOutputCP(1252);
	
	srand(time(NULL));

    int escolha = menuEscolha();
	 
	bool escolhaBool = false;
	
	int maxLinha;
	
	int maxCol;
	
	int maxPala;
	
	int maior;
	
	char palavra[TamPala];
	
	stPalavrasOcultas cacaPalavrasOcultas[QuantPala];
	
	char cacaPalavra[MaxLinha][MaxCol];
	
	bool palavraBool = false;
	
	char escolhaArq[80];
	
	bool estouroBool = false;
	
	char letra = '\0';
	

	
	
    while (!escolhaBool){
        switch (escolha){
            case 1:
                
                
                maxLinha = escolheMaxLinha();
                
                maxCol = escolheMaxCol();
                
                maxPala = escolheMaxPala();
                
               
                
                
                //INICIA MATRIZ COM CARACTER /0
                for(int i = 0; i<maxLinha;i++){
        			for(int j=0; j<maxCol; j++){
            			cacaPalavra[i][j] = letra;//'\0';
            			//printf("%c",cacaPalavra[i][j]);
                	}
				}
				
				
				//VERIFICA QUAL É O LADO MENOR, COLUNA OU LINHA | NA HORA Q ESTAVA FAZENDO ME ENGANEI, AI DEIXEI O MESMO NOME DE VARIAVEL
				if(maxLinha>maxCol){
					maior = maxCol;
				}
				else{
					maior = maxLinha;
				}
				
				
				
				
				
				//SELECIONA AS PALAVRAS QUE TEREMOS NO CAÇA PALAVRA
				for(int i = 0; i<maxPala; i++){
					palavraBool = false;	
					while(!palavraBool){
						printf("Informe a %d° Palavra: ", i+1);
						scanf("%s", &palavra);
						
						fflush(stdin);
						
						
						int tamanho = strlen(palavra);
						
						
						if(tamanho>=maior){
							printf("A palavra informada tem %d letras, ela deve ter menos de %d letras.\n", tamanho, maior);
							system("pause");
						}
						else{
							palavraBool = true;	
						}
						system("cls");
						strcpy(cacaPalavrasOcultas[i].palavra, palavra);
					}
				}
				
				
				//INICIO DO PROGRAMA PARA SETAR E COLOCAR AS PALAVRAS NA MATRIZ
				for(int i = 0; i<maxPala; i++){
	
					bool palavraSetada = false; 
					bool sorteioBool = false;
					bool colisao;
					int tentativas = 0; 
					int sortLinha;
					int sortCol;
					int sortOrie;
					int tamanho;
					
				
					while(!sorteioBool){
						
						sortLinha = (rand() % ((maxLinha-1) - limInferior + 1) + limInferior);
						sortCol = (rand() % ((maxCol-1) - limInferior + 1) + limInferior);
						sortOrie = (rand() % (limSuperior - limInferior + 1) + limInferior);
						colisao = false;
						
						
						tamanho = strlen(cacaPalavrasOcultas[i].palavra);
						
						
						if(sortOrie == 0){
							if((sortLinha-tamanho)>=0){
								
								int k = 0;
								for(int j=sortLinha; j>sortLinha-tamanho; j--){ 
									
									strcpy(palavra, cacaPalavrasOcultas[i].palavra);
									
									if(cacaPalavra[j][sortCol]==letra || cacaPalavra[j][sortCol]==palavra[k]){
										cacaPalavra[j][sortCol]=palavra[k];
									}
									else{
										colisao = true;
									}
									
									
									k++;
								}
								
								if(!colisao){
									palavraSetada = true;
								}
							}
						}
						
						else if(sortOrie == 1){
							if((sortLinha-tamanho)>=0 && (sortCol+tamanho)<=maxCol){
								
								int k = 0;
								int auxCol = sortCol;
								for(int j=sortLinha; j>sortLinha-tamanho; j--){ 
									
									strcpy(palavra, cacaPalavrasOcultas[i].palavra);
									
									if(cacaPalavra[j][auxCol]==letra || cacaPalavra[j][auxCol]==palavra[k]){
										cacaPalavra[j][auxCol]=palavra[k];
									}
									else{
										colisao = true;
									}
									
									auxCol++;
									k++;
								}
								
								if(!colisao){
									palavraSetada = true;
								}
							}
						}
						
						
						else if(sortOrie == 2){
							if((sortCol+tamanho)<=maxCol){
								
								int k = 0;

								for(int j=sortCol; j<sortCol+tamanho; j++){ 
									
									strcpy(palavra, cacaPalavrasOcultas[i].palavra);
									
									if(cacaPalavra[sortCol][j]==letra || cacaPalavra[sortCol][j]==palavra[k]){
										cacaPalavra[sortCol][j]=palavra[k];
									}
									else{
										colisao = true;
									}
									

									k++;
								}
								
								if(!colisao){
									palavraSetada = true;
								}
							}
						}
						
						
						else if(sortOrie == 3){
							if((sortLinha+tamanho)<=maxCol && (sortCol+tamanho)<=maxCol){
								
								int k = 0;
								int auxCol = sortCol;
								
								for(int j=sortLinha; j<sortLinha+tamanho; j++){ 
									
									strcpy(palavra, cacaPalavrasOcultas[i].palavra);
									
									if(cacaPalavra[j][auxCol]==letra || cacaPalavra[j][auxCol]==palavra[k]){
										cacaPalavra[j][auxCol]=palavra[k];
									}
									else{
										colisao = true;
									}
									
									auxCol++;
									k++;
								}
								
								if(!colisao){
									palavraSetada = true;
								}
							}
						}
						
						
						
						else if(sortOrie == 4){
							if((sortLinha+tamanho)<=maxCol){
								
								int k = 0;
								for(int j=sortLinha; j<sortLinha+tamanho; j++){ 
									
									strcpy(palavra, cacaPalavrasOcultas[i].palavra);
									
									if(cacaPalavra[j][sortCol]==letra || cacaPalavra[j][sortCol]==palavra[k]){
										cacaPalavra[j][sortCol]=palavra[k];
									}
									else{
										colisao = true;
									}
									
									
									k++;
								}
								
								if(!colisao){
									palavraSetada = true;
								}
							}
						}
						
						
						else if(sortOrie == 5){
							if((sortLinha+tamanho)<=maxCol && (sortCol-tamanho)>=0){
								
								int k = 0;
								int auxCol = sortCol;
								
								for(int j=sortLinha; j<sortLinha+tamanho; j++){ 
									
									strcpy(palavra, cacaPalavrasOcultas[i].palavra);
									
									if(cacaPalavra[j][auxCol]==letra || cacaPalavra[j][auxCol]==palavra[k]){
										cacaPalavra[j][auxCol]=palavra[k];
									}
									else{
										colisao = true;
									}
									
									auxCol--;
									k++;
								}
								
								if(!colisao){
									palavraSetada = true;
								}
							}
						}
						
						
						else if(sortOrie == 6){
							if((sortCol-tamanho)>=0){
								
								int k = 0;

								for(int j=sortCol; j>sortCol-tamanho; j--){ 
									
									strcpy(palavra, cacaPalavrasOcultas[i].palavra);
									
									if(cacaPalavra[sortCol][j]==letra || cacaPalavra[sortCol][j]==palavra[k]){
										cacaPalavra[sortCol][j]=palavra[k];
									}
									else{
										colisao = true;
									}
									

									k++;
								}
								
								if(!colisao){
									palavraSetada = true;
								}
							}
						}
						
						else if(sortOrie == 7){
							if((sortLinha-tamanho)>=0 && (sortCol-tamanho)>=0){
								
								int k = 0;
								int auxCol = sortCol;
								for(int j=sortLinha; j>sortLinha-tamanho; j--){ 
									
									strcpy(palavra, cacaPalavrasOcultas[i].palavra);
									
									if(cacaPalavra[j][auxCol]==letra || cacaPalavra[j][auxCol]==palavra[k]){
										cacaPalavra[j][auxCol]=palavra[k];
									}
									else{
										colisao = true;
									}
									
									auxCol--;
									k++;
								}
								
								if(!colisao){
									palavraSetada = true;
								}
							}
						}
						
						
						
						if(palavraSetada){
							cacaPalavrasOcultas[i].linha = sortLinha;
							cacaPalavrasOcultas[i].coluna = sortCol;
							cacaPalavrasOcultas[i].orientacao = enumOrientacao(sortOrie);
							sorteioBool = true;
							
						}
						else if(tentativas == 1500){
							estouroBool = true;
							break;
						}
						tentativas++;
					}
           		}
           		
           		
           		if(!estouroBool){
           			
           			printf("Gerando o Caça-Palavras.\n");
           			delay(1000);
           			system("cls");
           			
           			//COLOCA AS LETRAS ALEATORIAS NO CACA PALAVRA
           			for(int i = 0; i<maxLinha;i++){
        				for(int j=0; j<maxCol; j++){
            				if(cacaPalavra[i][j]==letra){
            					cacaPalavra[i][j]= (rand() % (limSuperiorSort - limInferiorSort + 1) + limInferiorSort);
							}	
                		}
					}
				
           		
           		
           			//INICIO PARA GRAVAR NO ARQUIVO A PARTE O CAÇA PALAVRA
           			printf("Informe o nome do arquivo: ");
           			scanf("%s", &escolhaArq);
           			
           			system("cls");
           		
           			nomeArq = fopen(escolhaArq,"w");
           		
           			for(int i=0; i<maxPala;i++){
           				fprintf(nomeArq, "%2.0d - %s\n", i+1, cacaPalavrasOcultas[i].palavra);
					}
           			fprintf(nomeArq, "\n");
           		
           		
           			for(int i = 0; i<maxLinha;i++){
           				for(int aux = 0; aux<maxCol; aux++){
           					fprintf(nomeArq, "+---");
						}
           				fprintf(nomeArq, "+\n|");
        				for(int j=0; j<maxCol; j++){
            				if(j<maxCol)
								fprintf(nomeArq, "%2c |",cacaPalavra[i][j]);
							else
								fprintf(nomeArq, "%2c",cacaPalavra[i][j]);
						}
                		fprintf(nomeArq, "\n");
                	
					}
               		for(int aux = 0; aux<maxCol; aux++){
           				fprintf(nomeArq, "+---");
           				if(aux+1==maxCol){
           					fprintf(nomeArq, "+\n");
						   }
					}
                
                	fprintf(nomeArq, "\n");
                
               		for(int i=0; i<maxPala; i++){
               			fprintf(nomeArq, "%d;%s;%d;%d;%d;\n",i+1, cacaPalavrasOcultas[i].palavra, cacaPalavrasOcultas[i].linha, cacaPalavrasOcultas[i].coluna, cacaPalavrasOcultas[i].orientacao);
					}
					
           			fclose(nomeArq);

           		
           		
           		
           			for(int i = 0; i<maxLinha;i++){
           				for(int aux = 0; aux<maxCol; aux++){
           					printf("+---");
						}
           				printf("+\n|");
        				for(int j=0; j<maxCol; j++){
            				if(j<maxCol)
								printf("%2c |",cacaPalavra[i][j]);
							else
								printf("%2c",cacaPalavra[i][j]);
						}
                		printf("\n");
                	
					}
                	for(int aux = 0; aux<maxCol; aux++){
           				printf("+---");
           				if(aux+1==maxCol){
           					printf("+");
						   }
					}
					
                	printf("\n");
                	
                	for(int i=0; i<maxPala; i++){
               			printf("%d - %s\n",i+1, cacaPalavrasOcultas[i].palavra);
					}
					system("pause");
                	
                	escolha = menuEscolha();
                }
                else{
                	printf("Não foi possível criar uma tabela de caça-palavras que acomode as palavras escolhidas.\n");
                	system("pause");
                	escolha = menuEscolha();
				}
				
				break;
            case 2:
                printf("Escolheu %d", escolha);
                break;
            case 3:
                escolhaBool=true;
                break;
            default:
                printf("Atenção:\nEscolha uma opção válida entre 1 e 3\n\n");
                delay(3000);
                escolha = menuEscolha();
        }
	}
    
	
	return 0;
}

int menuEscolha(){
	system("cls");
    int escolhaMenu;

    printf("1) Gerar Caça-Palavras\n2) Revelar Palavras do Caça-Palavras\n3) Encerrar Programa\n\n");
    printf("Qual a opção desejada: ");
    scanf("%d", &escolhaMenu);
    
    system("cls");

    return escolhaMenu;
}

int escolheMaxLinha(){
	
	int maxLinha;
	
	printf("Informe o numero de linhas do Caça-palavra: ");
    scanf("%d", &maxLinha);
    
    if(maxLinha<4 || maxLinha>31){
        printf("Por favor, informe um tamanho entre 5 e 30\n\n");
        
        maxLinha = escolheMaxLinha();
	}
	
	system("cls");
	
	return maxLinha;
}

int escolheMaxCol(){
	
	int maxCol;
	
	printf("Informe o numero de colunas do Caça-palavra: ");
    scanf("%d", &maxCol);
    
    if(maxCol<4 || maxCol>31){
        printf("Por favor, informe um tamanho entre 5 e 30\n\n");
        
        maxCol = escolheMaxCol();
	}
	
	system("cls");
	
	return maxCol;
}

int escolheMaxPala(){
	
	int maxPala;
	
	printf("Informe o numero de palavras a serem ocultados no Caça-palavra: ");
    scanf("%d", &maxPala);
    
    if(maxPala<1 || maxPala>26){
        printf("Por favor, informe um numero entre 2 e 26\n\n");
        
        maxPala = escolheMaxPala();
	}
	
	system("cls");
	
	return maxPala;	
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

