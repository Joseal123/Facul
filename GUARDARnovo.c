#include <stdio.h>
#include <string.h>
#define N 10
struct REGISTRO{
    int codigo;
    char nome[51];
    float saldo;
    int ativo;
};

struct REGISTRO cliente[N];
int removeCliente(int pos); //
int alteraCliente(int pos);
int buscaPosicaoVazio(); // vai buscar uma posiçao que esta vazio // JA FIZ
int buscaPosicaoNome(char nome[]); // busca um nome de cliente // JA FIZ
int buscaPorCodigo(int cod); // vai busca o cliente pelo codigo // JA FIZ
void cadastroCliente(int pos); // cadastra o cliente // JA FIZ
void listaCliente(int pos); //lista 1 cliente // JA FIZ
void listaTodos(); //lista todos cadatrados // JA FIZ
int menu();
void inicializaVetor(); 

int buscaPosicaoNome(char nome[]){
    int x = -1;
    for(int i = 0; i < N; i++)
        if (strcmp(cliente[i].nome,nome)== 0 && cliente[i].ativo == 1){
            x = i;
            break;

        }
    return x;
}


int buscaPorCodigo(int cod){
    int x = -1;
    for(int i = 0; i < N; i++)     
        if (cliente[i].codigo == cod && cliente[i].ativo == 1){
            x = i;
            break;
        } 
    return x;
}

int buscaPosicaoVazio(){
    int x = -1;
    for(int i = 0; i < N; i++)
        if (cliente[i].ativo == 0){
            x = i;
            break;

        }
        return x;
}


 void cadastroCliente(int pos){
    printf("Digite seu o codigo:");
    scanf(" %d",&cliente[pos].codigo);
    printf("Nome:");
    scanf(" %[^\n]",cliente[pos].nome);// le qualquer coisa em uma struct//
    printf("Saldo:");
    scanf(" %f",&cliente[pos].saldo);
    cliente[pos].ativo = 1;
    printf("Cliente cadastrado com sucesso!!\n");
    
 }
 void inicializaVetor(){
     for(int i = 0; i < N; i++){
         cliente[i].saldo = 0; // 
         cliente[i].ativo = 0; // 1 seria ativo
     }
 }
 void listaCliente(int pos){
    printf("Registro:\n");
    printf("Cliente: %s\n", cliente[pos].nome);
    printf("Codigo:%d\n", cliente[pos].codigo);
    printf("Saldo: R$%.2f\n", cliente[pos].saldo);
      
 }

void listaTodos(){
    for (int i = 0; i < N; i++)
        if (cliente[i].ativo == 1){
            printf("Registro:\n");
            printf("Cliente: %s\n", cliente[i].nome);
            printf("Codigo:%d\n", cliente[i].codigo);
            printf("Saldo: R$%.2f\n", cliente[i].saldo);
        }
}
 int menu(){
     printf("Bem-vindo ao Banco Gringostes\n");
     printf("1 - Cadastro Cliente\n");
     printf("2 - Lista de Cliente\n");
     printf("3 - Busca por Nome\n");
     printf("0 - Sair\n");
     printf("Opção:\n");
     int op;
     scanf("%d",&op);  

     return op;

 }


 int main(){
     int  x, pesquisa , atual = 0;
     inicializaVetor();
      
     do{
         x = menu();
         switch (x){
             case 1:
                atual = buscaPosicaoVazio();
                if (atual != -1)
                    cadastroCliente(atual);
                else 
                    printf("Vetor de cliente esta cheio\n");
                break;
            case 2:
                printf("Posição a ser listada: ");
                scanf(" %d",&pesquisa);
                if(pesquisa < atual)
                        listaCliente(pesquisa);
                else 
                    printf("Vetor de Clientes esta Vazio:");
                break;
            case 3:

                printf("Digite o nome do cliente:");
                char nome[51];
                scanf(" %[^\n]",nome);
                int pos;
                pos = buscaPosicaoNome(nome);
                    if (pos > 0){
                        listaCliente(pos);
                    }
                    else
                        printf("Não existe nenhum cliente com esse nome!!\n");
                
                
        
                break;
             case 0:
                printf("Adeus!\n");
                break;
             default: printf("Opção invalida!\n");
        }



    }while (x != 0);









     return 0;
 }