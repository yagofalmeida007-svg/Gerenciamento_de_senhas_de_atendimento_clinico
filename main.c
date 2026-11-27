
#include <stdio.h>

#include "paciente.h"
#include "fila.h"
#include "atendimento.h"
#include "painel.h"

int main() {

    int opcao;

    // Inicializa as filas
    inicializarFilas();

    do {

        printf("\n");
        printf("====================================\n");
        printf("     SISTEMA DE TRIAGEM CLINICA     \n");
        printf("====================================\n");

        printf("1 - Cadastrar paciente\n");
        printf("2 - Consultar proxima senha\n");
        printf("3 - Chamar paciente\n");
        printf("4 - Finalizar atendimento\n");
        printf("5 - Exibir painel\n");
        printf("0 - Sair\n");

        printf("====================================\n");

        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida! Digite um numero.\n");

            while (getchar() != '\n');

            opcao = -1;
            continue;
        }

        switch (opcao) {

            case 1: {
                Paciente p = cadastrarPaciente();

                gerarSenha(&p);

            if (adicionarFila(p)) {
                printf("\nCadastro realizado!\n");
                printf("Senha gerada: %s\n", p.senha);
            } else {
                printf("\nNao foi possivel cadastrar o paciente.\n");
            }

            break;
            }

            case 2: {

                Paciente *p = proximaSenha();

                if (p != NULL) {
                    printf("\nProxima senha: %s\n", p->senha);
                } else {
                    printf("\nNao existem pacientes aguardando.\n");
                }

                break;
            }

            case 3:

                chamarPaciente();
                break;

            case 4:

                finalizarAtendimento();
                break;

            case 5:

                exibirPainel();
                break;

            case 0:

                printf("\nSistema encerrado!\n");
                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}