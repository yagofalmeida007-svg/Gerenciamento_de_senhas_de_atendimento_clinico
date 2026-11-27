
#include <stdio.h>
#include "painel.h"

// Exibe o painel de atendimento
void exibirPainel() {

    printf("\n");
    printf("====================================\n");
    printf("       PAINEL DE ATENDIMENTO        \n");
    printf("====================================\n");

    // Verifica se existe paciente em atendimento
    if (existeAtendimento()) {

        Paciente atual = obterPacienteAtual();

        printf("Senha atual: %s\n", atual.senha);

        if (atual.categoria == URGENTE) {
            printf("Categoria: URGENTE\n");

        } else if (atual.categoria == PREFERENCIAL) {
            printf("Categoria: PREFERENCIAL\n");

        } else {
            printf("Categoria: NORMAL\n");
        }

    } else {

        printf("Senha atual: Nenhuma\n");
    }

    printf("------------------------------------\n");
    printf("       PACIENTES AGUARDANDO         \n");
    printf("------------------------------------\n");

    // Quantidade por categoria
    printf("Urgentes: %d\n",
           quantidade(&filaUrgente));

    printf("Preferenciais: %d\n",
           quantidade(&filaPreferencial));

    printf("Normais: %d\n",
           quantidade(&filaNormal));

    printf("------------------------------------\n");
    printf("         PROXIMAS SENHAS            \n");
    printf("------------------------------------\n");

    int encontrou = 0;

    // Lista os pacientes urgentes
    for (int i = filaUrgente.inicio;
         i < filaUrgente.fim; i++) {

        printf("%s - URGENTE\n",
               filaUrgente.pacientes[i].senha);

        encontrou = 1;
    }

    // Lista os pacientes preferenciais
    for (int i = filaPreferencial.inicio;
         i < filaPreferencial.fim; i++) {

        printf("%s - PREFERENCIAL\n",
               filaPreferencial.pacientes[i].senha);

        encontrou = 1;
    }

    // Lista os pacientes normais
    for (int i = filaNormal.inicio;
         i < filaNormal.fim; i++) {

        printf("%s - NORMAL\n",
               filaNormal.pacientes[i].senha);

        encontrou = 1;
    }

    if (encontrou == 0) {
        printf("Nenhum paciente aguardando.\n");
    }

    printf("====================================\n");
}
