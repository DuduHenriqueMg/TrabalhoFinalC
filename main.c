#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {   
    int codigo;
    char descricao[100];
    int quantidade;
    float valor;
    struct produto *prox;
} Produto;

Produto *inicializaLista() {
     return NULL;
}

Produto *adicionarProduto(Produto *lista) {
    Produto *novo = (Produto *)malloc(sizeof(Produto));
    printf("Digite o codigo do produto: ");
    scanf("%d", &novo->codigo);
    printf("Digite a descricao do produto: ");
    scanf(" %[^\n]", novo->descricao);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novo->quantidade);
    printf("Digite o valor do produto: ");
    scanf("%f", &novo->valor);
    novo->prox = lista;
    return novo;
}

void imprimirRelatorio(Produto *lista) {
    Produto *p;

    for (p = lista; p != NULL; p = p->prox) {
        printf("\nCodigo: %d\n", p->codigo);
        printf("Descricao: %s\n", p->descricao);
        printf("Quantidade: %d\n", p->quantidade);
        printf("Valor: %.2f\n", p->valor);
        printf("\n");
    }
       
}

Produto *buscarProduto(Produto *lista, int codigo) {
    Produto *p;
    for (p = lista; p != NULL; p = p->prox) {
        if (p->codigo == codigo)
            return p;
    }
    return NULL;
}

Produto *removeProduto(Produto *lista, int codigo) {
    Produto *ant = NULL;
    Produto *p = lista;

    while (p != NULL && p->codigo != codigo) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) {
        return lista;
    }

    if (ant == NULL) {
        lista = p->prox;
    }
    else{
        ant->prox = p->prox;
    }

    free(p);

    return lista;
}

int main() {
    Produto *estoque = inicializaLista();

    int opcao, codigo;

    do{
        printf("1- Cadastrar produto\n");
        printf("2- Consultar produto\n");
        printf("3- Gerar relatorio de produtos\n");
        printf("4- Remover produto do estoque\n");
        printf("5- Sair\n\n");

        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            estoque = adicionarProduto(estoque);
            break;
        case 2:
            printf("Digite o codigo do produto a ser consultado: ");
            scanf("%d", &codigo);
            Produto *produto = buscarProduto(estoque, codigo);
            if (produto != NULL){
                printf("\nCodigo: %d\n", produto->codigo);
                printf("Descricao: %s\n", produto->descricao);
                printf("Quantidade: %d\n", produto->quantidade);
                printf("Valor: %.2f\n", produto->valor);
            } else{
                printf("Produto nao encontrado.\n");
            }
            break;
        case 3:
            if (estoque != NULL){
                imprimirRelatorio(estoque);
            }else{
                printf("O estoque está vazio.\n");
            }

            break;
        case 4:
            printf("Digite o codigo do produto a ser removido: ");
            scanf("%d", &codigo);
            estoque = removeProduto(estoque, codigo);
            break;
        case 5:
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }

        printf("\n");

    } while (opcao != 5);
}
