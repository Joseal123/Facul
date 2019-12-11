#include <stdio.h>
#include <string.h>

int life,pos;
char palavras[60];
char aldeiaoculta[99];
char letra;


void comecodetudo();
void recebe();
void letravirapala();
void palavratraco();
void segredoescrito();
void forcas();
void letramaiuscula();


void letramaiuscula(){
    for(int i = 0; i < strlen(palavras);i++);
}


void forcas(){

    switch (life){

             case 5:

                printf("  |===|      Letra escolhidas:");
                printf("  |   O      Palavra: "); 
                printf("  |          Tentativas() \n");
                printf(" _|_\n");
                printf("/   \\ ");
            break;  

        case 4:
                printf("  |===|      Letra escolhidas: ");
                printf("  |   O      Palavra: "); 
                printf("  |   |      Tentativas() \n");
                printf(" _|_\n");
                printf("/   \\ ");
            break;


        case 3:
                printf("  |===|      Letra escolhidas: ");
                printf("  |   O      Palavra: "); 
                printf("  |  /|      Tentativas()  \n");
                printf(" _|_\n");
                printf("/   \\ ");
            break;

        case 2:
                printf("  |===|      Letra escolhidas: ");
                printf("  |   O      Palavra: "); 
                printf("  |  /|\\     Tentativas() \n");
                printf(" _|_\n");
                printf("/  \\ ");
            break;

        case 1:
                printf("  |===|      Letra escolhidas: ");
                printf("  |   O      Palavra: "); 
                printf("  |  /|\\     Tentativas() \n");
                printf(" _|_ /\n");
                printf("/   \\ ");
                
                break;

        case 0:
                printf("  |===|      Letra escolhidas: ");
                printf("  |   O      Palavra: "); 
                printf("  |  /|\\     Tentativas() ");
                printf(" _|_ / \\     Pretty much dead! Try again, loser!!\n");
                printf("/   \\ ");
                
            break;
    
    default:
        break;
    }

}

void segredoescrito(){
    for(int i = 0; i < strlen(palavras); i++){
        printf(" %c\n", aldeiaoculta[i]);

    }
}

void palavratraco(){
    char alfa[] = {"abcdefghijklmnopqrstuvxwyz"};
    int lele;
    for(int i = 0; i < strlen(palavras); i++){
        for( int k = 0; k < strlen(palavras); k ++){
            if(alfa[k] == palavras[i]){
                aldeiaoculta[i] = '_';
            }
            if (lele == 0){
                aldeiaoculta[i] = palavras[i];
            }
        }
    }
};


void letravirapala(){

    int lele;

    for(int i = 0, lele = -1; i < strlen(palavras); i++){
        if(letra == palavras[i]){
            aldeiaoculta[i] = letra;
            lele = 0;
        }
    }
    
};


void comecodetudo(){
    printf("---------------------");
    printf("\nBem Vindo ao Jogo da Forca!\n");
    printf("  |===|      Letra escolhidas:\n");
    printf("  |          Palavra: "); 
    printf("  |  ");        
    printf(" _|_\n");
    printf("/   \\\n");
}

int main(){

    int correto;
    int i;
    char temp;
    FILE *procura;
    procura = fopen("segredo.txt", "r");
    if(procura == NULL){
        printf("ERRO na abertura do arquivo\n");
    }
    else {
        while((temp = fgetc(procura)) != EOF){
            i = 0;
            palavras[i++] = temp;
            
            

        }
        fclose(procura);
        life = 6;

        do{ 
            correto = strcmp(palavras, aldeiaoculta);
        }
        while(life != -1 && correto != 0);
        printf("\n");

        if(correto != 0){
            printf("A palavra certa era: %s\n", palavras);
        }
        if(correto == 0){
            printf("Congratulations! You won!!\n");


        }
            
    }
        void comecodetudo();
        void recebe();
        void letravirapala();
        void palavratraco();
        void segredoescrito();
        void forcas();
        void letramaiuscula();



    return 0;
}
