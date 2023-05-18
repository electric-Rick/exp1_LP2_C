#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Estrutura de como será a variável dicionário
struct chave_valor {
    char chave[30];
    int valor;
    struct chave_valor* prox;

};

// Função que cria a variável dicionário
struct chave_valor* fornece(const char* chave, int valor){

    // Cria a variável dicionário
    struct chave_valor* dados = (struct chave_valor*)malloc(sizeof(struct chave_valor)); //É importante entender que esse malloc está alocando memória para a variável dicionário, e não para a chave e o valor. A chave e o valor estão dentro da variável dicionário, então eles são alocados junto com a variável dicionário.
    // Existem dois ponteiros aqui: Um para a chave e outro para o valor. Eles são ponteiros porque eles apontam para o endereço de memória da variável dicionário.
    // O ponteiro da chave aponta para o endereço de memória da chave e o ponteiro do valor aponta para o endereço de memória do valor.
    // O ponteiro da chave é um ponteiro constante porque ele não pode ser alterado, já o ponteiro do valor pode ser alterado.

    // Cria os dados da variável dicionário
    strcpy(dados->chave, chave);
    dados->valor =valor;
    dados->prox = NULL;
    return dados;   // Retorna os dados

};

// Função que adiciona os dados na variável dicionário
void adcDadosChaveValor(struct chave_valor** dicio, const char* chave, int valor){ // Cria uma função que recebe os dados da variável dicionário
    struct chave_valor* dados = fornece(chave, valor); // Cria uma variável dados que recebe os dados da função "fornece"
    if (*dicio == NULL){
        *dicio = dados;  // Se a variável dicionário for NULL, ela recebe os dados
    } else {    // Se não
        struct chave_valor* atual = *dicio; // Cria uma variável auxiliar
        while(atual->prox != NULL){ // Enquanto o próximo for diferente de NULL
            atual = atual->prox;    // Atual recebe o próximo
            
        }
        atual->prox = dados; // O próximo recebe os dados
    }
};

// Função que imprime os dados da variável dicionário
char imprimeChaveValor(struct chave_valor* dicio){
    printf("{");
    while(dicio != NULL){
        printf("%s: %d", dicio->chave, dicio->valor);
        cria_arquivo(dicio->chave, dicio->valor); 
        dicio = dicio->prox;
        if(dicio != NULL){
            printf(", ");
        }
    }
    printf("}\n");
}

// Função que limpa a variável dicionário
void limpa_chave_valor(struct chave_valor* dicio){
    while(dicio != NULL){
        struct chave_valor* aux = dicio;
        dicio = dicio->prox;
        free(aux);
    }
}

void cria_arquivo(struct chave_valor* dicio_c, struct chave_valor* dicio_v){
    FILE* arquivo = fopen("dicionario.json", "a");    
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
        system("pause");
    } else{
        
        fprintf(arquivo, "{ '%s': %d }, \n ", dicio_c, dicio_v);

    }
    
    fclose(arquivo);
}


// Função principal
int main(){
    // Funcoes:
    // adcDadosChaveValor
    // imprimeChaveValor
    // limpa_chave_Valor
    // crie_chave_valor
    
    struct chave_valor* dicio = NULL; // Cria a variável dicionário
    int interacoes = 0; // Variável para testar a função adcDadosChaveValor
    // Teste 1
    do {
        interacoes = interacoes + 1;
        adcDadosChaveValor(&dicio, "a", interacoes);        
        adcDadosChaveValor(&dicio, "b", interacoes);
        adcDadosChaveValor(&dicio, "c", interacoes);
        adcDadosChaveValor(&dicio, "d", interacoes);
        
        
    } while(interacoes < 100); // Valor limite do teste
    
    
    // Imprime a variável dicionário
    imprimeChaveValor(dicio);
    // Limpa a variável dicionário
    limpa_chave_valor(dicio);

    
    // Finalização
    system("pause");
    return 0;
}