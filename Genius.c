// @Fabio Zhao
// @Matheus de Souza
// @Murilo Capponi

#include<stdlib.h>
#include<stdio.h>

typedef struct elemento {
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct Fila {
    Elemento *inicio;
    Elemento *fim;
} Fila;


Fila *inicializaFila() {
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void colocaDado( Fila *f,int d) {
    Elemento *novoDado;
    novoDado = (Elemento *)malloc(sizeof(Elemento));
    novoDado->dado = d;
    novoDado->proximo = NULL;
    if (f->inicio == NULL && f->fim == NULL){
        f->fim = f->inicio = novoDado;
    }else{
        f->fim->proximo = novoDado;
        f->fim = novoDado;
    }
}

void retiraDado(Fila *f) {
    int saida = f->inicio->dado;
    Elemento *retirado;
    retirado = (Elemento *)malloc(sizeof(Elemento));
    retirado = f->inicio;
    if (f->fim != f->inicio) {
        f->inicio = f->inicio->proximo;
    }else{
        f->fim = f->inicio = NULL;
    }
    free(retirado);
}

void imprimeFila(Fila *f) {
    Elemento *iterador;
    iterador = (Elemento *)malloc(sizeof(Elemento));
    iterador = f->inicio;
    while (iterador != NULL) {
        printf("%i \n",iterador->dado);
        iterador = iterador->proximo;
    }
	printf("\n");
}

int comparaFila(Fila *f){
  Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
  aux = f -> inicio;
  int digitado;
  printf("Sua vez:\n");
  while (aux != NULL){
    scanf("%i", &digitado);
    if(aux -> dado != digitado){
      printf("Voc%c perdeu \n", 136);
      return 2;
    }else{
      aux = aux -> proximo;
    }
  }
  free(aux);
  return 1;
}

void morreFila(Fila *f, int i){
  for(int count = 0; count < 4+i; count++){
    retiraDado(f);
  }
}


void startup (Fila *f, int a) {
  int i, b;
  for( i = 0 ; i < 4 ; i++ ) {
    b = rand() % a;
    colocaDado(f, b);
  }
}

int main(){
  int estadoJogo = 1, a;
  int pontos = 0;
  char opt;
  Fila *f = inicializaFila();
  printf("================= Genius ================= \n");
  printf("=============== Rodada: %d ================ \n", pontos+1);
  printf("Voc%c deseja jogar entre n%cmeros de 0 a: \n", 136, 163);
  setbuf(stdin, NULL);
  scanf("%d", &a);
  a++; 
  startup(f, a) ;

  //Jogo
  do{
    system("cls");
  printf("================= Genius ================= \n");
  printf("=============== Rodada: %d ================ \n", pontos+1);
    imprimeFila(f);
    system("pause");
    system("cls");
  printf("================= Genius ================= \n");
  printf("=============== Rodada: %d ================ \n", pontos+1);
    estadoJogo= comparaFila(f);
    if (estadoJogo == 1){
      colocaDado(f, rand() % a);
      pontos ++;
    }
  } while(estadoJogo == 1);
  
  if (estadoJogo == 2){
    printf("\n \n \n");
    printf("Sua pontua%c%co foi: %d\n",135 ,198 ,pontos);
    printf("Deseja recome%car? (S/N)\n",135);
    setbuf(stdin, NULL);
    scanf("%c", &opt);
    if(opt == 'S' || opt == 's'){
      morreFila(f, pontos);
      system("cls");
      main();
    }
  system("cls");
  printf("Obrigado por Jogar\n");
  printf("================== Por: ================== \n");
  printf(" Fabio Zhao \n Matheus de Souza \n Murilo Capponi\n");
  system("pause");
  }
  
} 
