
#include <stdio.h>
#include "fila.h"

Fila filaNormal;
Fila filaPreferencial;
Fila filaUrgente;

int contadorN = 0;
int contadorP = 0;
int contadorU = 0;

void inicializarFilas() {
    filaNormal.inicio = 0;
    filaNormal.fim = 0;

    filaPreferencial.inicio = 0;
    filaPreferencial.fim = 0;

    filaUrgente.inicio = 0;
    filaUrgente.fim = 0;
}

void gerarSenha(Paciente *p) {
    if (p->categoria == NORMAL) {
        contadorN++;
        sprintf(p->senha, "N%03d", contadorN);
    } 
    else if (p->categoria == PREFERENCIAL) {
        contadorP++;
        sprintf(p->senha, "P%03d", contadorP);
    } 
    else {
        contadorU++;
        sprintf(p->senha, "U%03d", contadorU);
    }
}

int adicionarFila(Paciente p) {
    Fila *fila;

    if (p.categoria == NORMAL)
        fila = &filaNormal;
    else if (p.categoria == PREFERENCIAL)
        fila = &filaPreferencial;
    else
        fila = &filaUrgente;

    // Reaproveita as posições já liberadas
    if (fila->fim >= MAX) {
        int total = fila->fim - fila->inicio;

        for (int i = 0; i < total; i++) {
            fila->pacientes[i] =
                fila->pacientes[fila->inicio + i];
        }

        fila->inicio = 0;
        fila->fim = total;
    }

    if (fila->fim >= MAX) {
        printf("Fila cheia!\n");
        return 0;
    }

    fila->pacientes[fila->fim] = p;
    fila->fim++;

    return 1;
}

Paciente *proximaSenha() {
    if (filaUrgente.inicio < filaUrgente.fim)
        return &filaUrgente.pacientes[filaUrgente.inicio];

    if (filaPreferencial.inicio < filaPreferencial.fim)
        return &filaPreferencial.pacientes[filaPreferencial.inicio];

    if (filaNormal.inicio < filaNormal.fim)
        return &filaNormal.pacientes[filaNormal.inicio];

    return NULL;
}

int quantidade(Fila *fila) {
    return fila->fim - fila->inicio;
}
