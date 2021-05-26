
#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"
#define TAM 10

//Aluno: Victor Macedo
//Matrícula: 2018216039
//Disciplina: Laboratório de programação

//Estrutura Principal Do programa
typedef struct{

    int *listaAuxiliar;
    int *aux;
    int *tam; 

}EstruturaGeral;

//Criando estrutura de tamanho definido 10 para compor as estruturas auxiliares
EstruturaGeral VetorPrincipal[TAM];

No *lista = NULL;

//inicialização de variaveis
void inicializar(){

    int i;

    EstruturaGeral vetor[TAM];

    for(i=0;i<TAM;i++){

        vetor[i].listaAuxiliar = NULL;
        vetor[i].tam = 0;
        vetor[i].aux = 0;

    }
}

//verifica se posiçao do vetor é valida 1-10
int ehPosicaoValida(int posicao){

    int retorno = 0;

    if (posicao < 1 || posicao > 10){

        retorno = POSICAO_INVALIDA;

    }else{
    
    retorno = SUCESSO;

    }

    return retorno;
}

void dobrar(int *x){
    *x = *x * 2;
}

//confere se já existe estrutura auxiliar criada em determinada posição do vetor
int verificarEstruturaAuxiliar(int posicao){

    int retorno;

    //ponteiro para lista principal
    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal[posicao];

    if(ponteiroEstruturaPrincipal->listaAuxiliar != NULL){

        return JA_TEM_ESTRUTURA_AUXILIAR;   
    } 
    else{

        return SEM_ESTRUTURA_AUXILIAR;
    }
}

//Confere a struct e se existe alguns impedimentos para criação de uma estrutura auxiliar dentro da estrutura principal
int verificaEstrutura(int tam, EstruturaGeral *ponteiroX){

    int i;

    if(ponteiroX->listaAuxiliar == NULL){

        ponteiroX->listaAuxiliar = (int *) malloc(tam * sizeof(int *));

        if(ponteiroX->listaAuxiliar == NULL){

            return SEM_ESPACO_DE_MEMORIA;
        }
        else
        {
            ponteiroX->aux = 0;
            ponteiroX->tam = tam;

            return SUCESSO;
        }    
    }
    else{

        return JA_TEM_ESTRUTURA_AUXILIAR;

    }
}

//cria a estrutura auxiliar necessaria
int criarEstruturaAuxiliar(int tam, int posicao){

    int verificador, retorno = 0;

    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal[posicao]; 

    if(ehPosicaoValida(posicao) == SUCESSO){

        if(tam>0){

            verificador = verificaEstrutura(tam, ponteiroEstruturaPrincipal);
        }
        else{

            return TAMANHO_INVALIDO; 

        }
    }
    else{

        return POSICAO_INVALIDA;

    }
        
    if(verificador == SUCESSO){

        retorno = SUCESSO;

    }
    else if(verificador == JA_TEM_ESTRUTURA_AUXILIAR){

        retorno = JA_TEM_ESTRUTURA_AUXILIAR;

    }
    else{

        retorno = SEM_ESPACO_DE_MEMORIA;

    }

    return retorno;
}


int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    int cont; 
    int retorno;

    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal[posicao];

    if(ehPosicaoValida(posicao+1) == SUCESSO){

        if(verificarEstruturaAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR){

            if(ponteiroEstruturaPrincipal->aux > 0){

                retorno = ponteiroEstruturaPrincipal->aux;

            }
            else{

                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else{

            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else

        retorno = POSICAO_INVALIDA;

    return retorno;
}


int verificarTamanhoEstruturaAuxiliar(int posicao){

    int tam; 
    int tamanhoEstrutura;
    int cont;

    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal[posicao];

    cont = getQuantidadeElementosEstruturaAuxiliar(posicao);
    
    tam = ponteiroEstruturaPrincipal->tam;

    tamanhoEstrutura = tam - cont;

    if(tamanhoEstrutura>0){
        return SUCESSO;
    }
    else{
        return SEM_ESPACO;
    }
}

int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;
    int validarestrutura = 0;
    int validarespaco = 0;
    int validarposicao = 0;
    int sContador = 1;
    int ponteiroContador;
    int soma;

    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal[posicao];

    ponteiroContador = ponteiroEstruturaPrincipal->aux;

    validarposicao = ehPosicaoValida(posicao);

    validarestrutura = verificarEstruturaAuxiliar(posicao);

    validarespaco = verificarTamanhoEstruturaAuxiliar(posicao);

    soma = ponteiroContador + sContador;

    if(validarposicao != SUCESSO){

        retorno = POSICAO_INVALIDA;
    }
    else{

        if(validarestrutura == JA_TEM_ESTRUTURA_AUXILIAR){

          if(validarespaco == SUCESSO){

              ponteiroEstruturaPrincipal->listaAuxiliar[ponteiroContador] = valor;

              ponteiroEstruturaPrincipal->aux = soma;

              retorno = SUCESSO;

            }
            else{

              retorno = SEM_ESPACO;

            }

        }else{

          retorno = SEM_ESTRUTURA_AUXILIAR;

        }
    }

    return retorno;
}

//Função para ordenar algum vetor 
void OrdenarVetor(int lista[], int n){

    int i, j, troca, menor;

    for(i=0;i<n;i++){

        menor = i;

        for(j=i+1;j<n;j++){

            if(lista[j]<lista[menor]){

                menor = j;
            }
        }

        if(menor != i){
            troca = lista[i];
            lista[i] = lista[menor];
            lista[menor] = troca;
        }
    }
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0, j;

    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal;

    int len = sizeof(vetorAux)/sizeof(vetorAux[0]);

    if(ehPosicaoValida(posicao) == SUCESSO){

        if(verificarEstruturaAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR){

           for(j=0;j<len;j++){

            vetorAux[j] = ponteiroEstruturaPrincipal[posicao].listaAuxiliar[j];
                 
            retorno = SUCESSO;

           }
        }
        else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else{
        retorno = POSICAO_INVALIDA;
    }

    return retorno;
}


int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0, contadorGeral = 0, i, x=0, j, k, tamanhoListasAuxiliares;

    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal;

    //operador ternario
    for(i=0; i<10;i++)

        contadorGeral += getQuantidadeElementosEstruturaAuxiliar(i) > 0 ? getQuantidadeElementosEstruturaAuxiliar(i) : 0;
    
    if(contadorGeral == 0)

        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    else
        retorno = SUCESSO;

    vetorAux[contadorGeral];

    for(k=0;k<10;k++){

        for(j=0;j<getQuantidadeElementosEstruturaAuxiliar(k);j++){

            for(i=x;i<contadorGeral;i++){

                vetorAux[i] = ponteiroEstruturaPrincipal[k].listaAuxiliar[j];
                x++;
                break;

            }
        }
    }

    return retorno;
}


int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    
    int retorno = 0, j, tj;

    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal;

    if(ehPosicaoValida(posicao) == SUCESSO){

        if(verificarEstruturaAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR){

            int len = sizeof(vetorAux)/sizeof(int);

            for(j=0;j<len;j++){
                vetorAux[j] = ponteiroEstruturaPrincipal[posicao].listaAuxiliar[j]; 
   
            }

            OrdenarVetor(vetorAux, tj);   
            retorno = SUCESSO;    

        }
        else{

            retorno = SEM_ESTRUTURA_AUXILIAR;
            
        }
    }
    else{

        retorno = POSICAO_INVALIDA;

    }

    return retorno;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0, contadorGeral = 0, i, x=0, j, k, tamanhoListasAuxiliares;

    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal;

    //operador ternario
    for(i=0; i<10;i++){

        contadorGeral += getQuantidadeElementosEstruturaAuxiliar(i) > 0 ? getQuantidadeElementosEstruturaAuxiliar(i) : 0;
    }
    if(contadorGeral == 0){

        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else{

        retorno = SUCESSO;
    }

    vetorAux[contadorGeral]; 

    for(k=0;k<10;k++){

        for(j=0;j<getQuantidadeElementosEstruturaAuxiliar(k);j++){

            for(i=x;i<contadorGeral;i++){

                vetorAux[i] = ponteiroEstruturaPrincipal[k].listaAuxiliar[j];

                x++;

                break;
            }
        }
    }

    OrdenarVetor(vetorAux, contadorGeral);

   return retorno;
}

void ordenarEstruturaAuxiliarPosRemocao(int posicaoPrincipal, int posicaoAuxiliar){

    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal;

    int i;

    for(i=posicaoAuxiliar;i<ponteiroEstruturaPrincipal[posicaoPrincipal].tam;i++){

        ponteiroEstruturaPrincipal[posicaoPrincipal].listaAuxiliar[i] = ponteiroEstruturaPrincipal[posicaoPrincipal].listaAuxiliar[i+1];

    }
}

int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){

  int retorno = SUCESSO;

  int i, encontrado = 0, sub = 0;

  EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

  ponteiroEstruturaPrincipal = &VetorPrincipal;

  while (i < ponteiroEstruturaPrincipal->tam && encontrado == 0){

      if(ponteiroEstruturaPrincipal[posicao].listaAuxiliar[i] == valor){

          encontrado = 1;
          ponteiroEstruturaPrincipal->aux = (sub - encontrado);
          ordenarEstruturaAuxiliarPosRemocao(posicao,i);
          break;    

        }
        else{

          encontrado = 0;
          i++;

        }
    }
  
  return retorno;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){

    int retorno = 0, tamanho = 0;

    EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

    ponteiroEstruturaPrincipal = &VetorPrincipal;
    
    tamanho = ponteiroEstruturaPrincipal[posicao].tam;

    if(ehPosicaoValida(posicao) != SUCESSO){

        return POSICAO_INVALIDA;

    }
    if((tamanho + novoTamanho) <= 0){

        return NOVO_TAMANHO_INVALIDO;

    }
    if(ponteiroEstruturaPrincipal[posicao].listaAuxiliar == NULL){

        return SEM_ESTRUTURA_AUXILIAR;
    }
    else{

        novoTamanho += tamanho;

        ponteiroEstruturaPrincipal[posicao].listaAuxiliar = (int *) realloc(ponteiroEstruturaPrincipal[posicao].listaAuxiliar, novoTamanho * sizeof(int *));
        
        if(ponteiroEstruturaPrincipal[posicao].listaAuxiliar == NULL){

            return SEM_ESPACO_DE_MEMORIA;
        }
        else{

            ponteiroEstruturaPrincipal[posicao].tam = novoTamanho;

            if(ponteiroEstruturaPrincipal[posicao].aux > novoTamanho){

                ponteiroEstruturaPrincipal[posicao].aux = novoTamanho;
            }

            return SUCESSO;
        }
    }  

    return retorno;   
}

int excluirNumeroDoFinaldaEstrutura(int posicao){

  int retorno = SUCESSO;

  int i, encontrado = 0, sub = 1, ContadorAtual = 0;

  EstruturaGeral *ponteiroEstruturaPrincipal = NULL;

  ponteiroEstruturaPrincipal = &VetorPrincipal;

  ContadorAtual = ponteiroEstruturaPrincipal[posicao].aux;
  
  if(ehPosicaoValida(posicao) == SUCESSO){

    if(verificarEstruturaAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR){

        if(getQuantidadeElementosEstruturaAuxiliar(posicao) >= 0){

            ponteiroEstruturaPrincipal[posicao].aux = ContadorAtual - sub;
            retorno = SUCESSO;

        }
        else{

            return ESTRUTURA_AUXILIAR_VAZIA;
        }
    }
    else{

        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
}   
    else{

    retorno = POSICAO_INVALIDA;

    }
  
  return retorno;
}

//Função auxiliar criada para lista encadeada

int getQuantidadeTotal(){

  int i, qtdt = 0;

    for(i=0; i<10; i++){

        qtdt = qtdt + VetorPrincipal[i].aux;
    }

  return qtdt;

}

No *montarListaEncadeadaComCabecote(){

  int qtd = 0, i;

  qtd = getQuantidadeTotal();

  if(qtd == 0){

    return NULL;

  }
  int vetorAux[TAM];

  getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);

  for(i=0; i<qtd; i++){

    No *novo =(No*)malloc(sizeof(No));

    novo->conteudo = vetorAux[i];

    novo->prox = lista;

    lista = novo;

  }

  return lista;

}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){

  int i = 0;

  inicio = montarListaEncadeadaComCabecote();

  while(inicio!=NULL){

    vetorAux[i] = inicio->conteudo;

    i++;

    inicio = inicio->prox;

  }

}

void destruirListaEncadeadaComCabecote(No **inicio){

  if(inicio != NULL){

		No *aux;

		while(inicio != NULL){

			aux = inicio;

			inicio = (*inicio)-> prox;

			free(aux);
		}
		free(inicio);
	}
}

void finalizar(){

     int i;

     for(i = 0; i < TAM; i += 1){

         free(VetorPrincipal[i].listaAuxiliar);
     }

     free(VetorPrincipal);
}