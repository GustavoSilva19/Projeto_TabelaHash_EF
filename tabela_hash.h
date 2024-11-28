#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define TAMANHO_TABELA 1013 // Tamanho fixo, escolhido como um numero primo para melhorar a distribuicao

// Estrutura para armazenar os dados do Pokemon
typedef struct Pokemon {
    int numero_pokedex;       // Numero do Pokemon na Pokedex (chave)
    char nome[50];            
    char natureza[50];        
    struct Pokemon* proximo;  // Ponteiro para o proximo no (lista encadeada)
} Pokemon;

// Estrutura da Tabela Hash
typedef struct TabelaHash {
    Pokemon* lista[TAMANHO_TABELA]; // Array de ponteiros para listas encadeadas
} TabelaHash;

// Funcoes da Tabela Hash
TabelaHash* criar_tabela();
int funcao_hash(int chave);
void inserir_pokemon(TabelaHash* tabela, int numero, char* nome, char* natureza);
Pokemon* buscar_pokemon(TabelaHash* tabela, int numero);
void remover_pokemon(TabelaHash* tabela, int numero);
void imprimir_tabela(TabelaHash* tabela);
void liberar_tabela(TabelaHash* tabela);

#endif
