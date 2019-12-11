#include <stdio.h>

int main(){

    int N;
    int vetor[1000];
    int resposta;
    resposta = 1;

    FILE *procura;

        procura = fopen("entrada.txt", "r");

        if(procura == NULL){
            printf("Arquivo nao pode ser aberto\n");
            return 0;
        }
    
    fscanf(procura,"%d",&N);
        for(int i = 0; i < N; i++){
            fscanf(procura,"%d",&vetor[i]);
        
    }
        // ELE VAI COMECAR NO 3 ELEMENTO
    for(int i = 2;i < N; i++){
          // se a diferença dos ultimos dois numeros é diferente da diferença dos dois numeros antes desses dois numeros 
          //vai estar gerando uma nova escadinha
        if((vetor[i] - vetor[i - 1]) != (vetor [i - 1] - vetor[i - 2])){
            resposta++;
        }
    }


printf("%d\n",resposta);
    return 0;
}
