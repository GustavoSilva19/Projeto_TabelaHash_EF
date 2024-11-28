#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

// Cria uma nova tabela hash
TabelaHash* criar_tabela() {
    TabelaHash* tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
    if (!tabela) {
        printf("Erro ao alocar memoria para a tabela hash.\n");
        exit(1);
    }
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela->lista[i] = NULL;
    }
    return tabela;
}

// Funcao de hash simples: chave % TAMANHO_TABELA
int funcao_hash(int chave) {
    return chave % TAMANHO_TABELA;
}

// Insere um novo Pokemon na tabela hash
void inserir_pokemon(TabelaHash* tabela, int numero, char* nome, char* natureza) {
    int indice = funcao_hash(numero);
    Pokemon* novo = (Pokemon*)malloc(sizeof(Pokemon));
    if (!novo) {
        printf("Erro ao alocar memoria para o Pokemon.\n");
        exit(1);
    }
    novo->numero_pokedex = numero;
    strcpy(novo->nome, nome);
    strcpy(novo->natureza, natureza);
    novo->proximo = tabela->lista[indice];
    tabela->lista[indice] = novo;
    printf("Pokemon adicionado com sucesso a pokedex!\n");
}

// Busca um Pokemon na tabela hash pelo numero da Pokedex
Pokemon* buscar_pokemon(TabelaHash* tabela, int numero) {
    int indice = funcao_hash(numero);
    Pokemon* atual = tabela->lista[indice];
    while (atual != NULL) {
        if (atual->numero_pokedex == numero) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Remove um Pokemon da tabela hash pelo numero da Pokedex
void remover_pokemon(TabelaHash* tabela, int numero) {
    int indice = funcao_hash(numero);
    Pokemon* atual = tabela->lista[indice];
    Pokemon* anterior = NULL;

    while (atual != NULL && atual->numero_pokedex != numero) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Pokemon nao registrado na pokedex.\n");
        return;
    }

    if (anterior == NULL) { // Primeiro elemento da lista
        tabela->lista[indice] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
    printf("Pokemon removido com sucesso!\n");
}

// Imprime todo o conteudo da tabela hash
void imprimir_tabela(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        if (tabela->lista[i] != NULL) {
            printf("Indice %d:\n", i);
            Pokemon* atual = tabela->lista[i];
            while (atual != NULL) {
                printf("  Numero: %d, Nome: %s, Natureza: %s\n", atual->numero_pokedex, atual->nome, atual->natureza);
                atual = atual->proximo;
            }
        }
    }
}

// Libera toda a memoria da tabela hash
void liberar_tabela(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Pokemon* atual = tabela->lista[i];
        while (atual != NULL) {
            Pokemon* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(tabela);
}
