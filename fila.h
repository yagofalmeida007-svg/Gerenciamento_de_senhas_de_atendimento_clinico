
#ifndef FILA_H
#define FILA_H

#include "paciente.h"

#define MAX 500

// Estrutura da fila
typedef struct {
    Paciente pacientes[MAX];
    int inicio;
    int fim;
} Fila;

// Declaracao das tres filas
extern Fila filaNormal;
extern Fila filaPreferencial;
extern Fila filaUrgente;

// Inicializacao das filas
void inicializarFilas();

// Geracao de senhas
void gerarSenha(Paciente *p);

// Adicionar paciente na fila
int adicionarFila(Paciente p);

// Consultar proxima senha
Paciente *proximaSenha();

// Quantidade de pacientes aguardando
int quantidade(Fila *fila);

#endif
