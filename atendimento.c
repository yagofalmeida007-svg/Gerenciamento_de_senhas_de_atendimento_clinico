
#include <stdio.h>
#include "atendimento.h"

// Armazena o paciente em atendimento
Paciente pacienteAtual;

// Indica se existe atendimento ativo
int atendimentoAtivo = 0;


// Verifica se existe atendimento
int existeAtendimento() {

    return atendimentoAtivo;
}


// Retorna os dados do paciente atual
Paciente obterPacienteAtual() {

    return pacienteAtual;
}


// Realiza a chamada do proximo paciente
void chamarPaciente() {

    if (atendimentoAtivo == 1) {

        printf("\nFinalize o atendimento atual primeiro!\n");
        return;
    }

    Paciente *p = proximaSenha();

    if (p == NULL) {

        printf("\nNao existem pacientes aguardando.\n");
        return;
    }

    // Copia os dados do paciente
    pacienteAtual = *p;

    // Avanca o inicio da fila correspondente
    if (p->categoria == URGENTE) {

        filaUrgente.inicio++;

    } else if (p->categoria == PREFERENCIAL) {

        filaPreferencial.inicio++;

    } else {

        filaNormal.inicio++;
    }

    atendimentoAtivo = 1;

    printf("\n===== PACIENTE CHAMADO =====\n");
    printf("Senha: %s\n", pacienteAtual.senha);

    if (pacienteAtual.categoria == URGENTE) {

        printf("Categoria: URGENTE\n");

    } else if (pacienteAtual.categoria == PREFERENCIAL) {

        printf("Categoria: PREFERENCIAL\n");

    } else {

        printf("Categoria: NORMAL\n");
    }
}


// Finaliza o atendimento atual
void finalizarAtendimento() {

    if (atendimentoAtivo == 0) {

        printf("\nNao existe atendimento em andamento.\n");
        return;
    }

    printf("\nAtendimento da senha %s finalizado!\n",
           pacienteAtual.senha);

    atendimentoAtivo = 0;
}
