# Sistema de Triagem e Gerenciamento de Filas — Clínica

## 1. Sobre o projeto

Este projeto foi desenvolvido em linguagem C como atividade acadêmica. Seu objetivo é criar um sistema de triagem e gerenciamento de filas para uma clínica, permitindo cadastrar pacientes, classificá-los por prioridade e organizar a ordem de atendimento.

O sistema utiliza estruturas de dados, funções, arquivos separados e filas independentes para cada categoria de atendimento.

## 2. Funcionalidades

- Cadastro de pacientes.
- Identificação de gênero e idade.
- Registro de gestação, lactação, necessidade especial e condição de obesidade.
- Classificação automática dos pacientes.
- Geração de senhas sequenciais.
- Organização de três filas independentes.
- Chamada de pacientes conforme a prioridade.
- Finalização de atendimentos.
- Consulta da próxima senha.
- Painel de acompanhamento das filas.
- Validação de entradas do usuário.

## 3. Regras de classificação

O sistema utiliza três categorias:

### Urgente
- Pacientes com idade superior a 80 anos.

### Preferencial
- Gestantes.
- Lactantes.
- Pessoas com necessidades especiais.
- Pessoas com condição de obesidade.
- Mulheres com 60 anos ou mais.
- Homens com 65 anos ou mais.

### Normal
- Pacientes que não se enquadram nas categorias anteriores.

**Observação:** em caso de enquadramento em mais de uma categoria, prevalece a classificação de maior prioridade definida pelo sistema.

As regras representam os critérios definidos para este trabalho acadêmico e não substituem uma avaliação clínica ou a legislação aplicável.

## 4. Sistema de senhas

Cada categoria possui uma sequência independente:

- Normal: N001, N002, N003...
- Preferencial: P001, P002, P003...
- Urgente: U001, U002, U003...

A ordem de atendimento segue a seguinte prioridade:

1. Urgente.
2. Preferencial.
3. Normal.

Dentro de cada categoria, os pacientes são atendidos na ordem em que foram cadastrados (FIFO).

## 5. Estrutura dos arquivos

| Arquivo | Responsabilidade |
|---|---|
| `main.c` | Menu principal e controle do programa. |
| `paciente.h` | Estrutura e constantes dos pacientes. |
| `paciente.c` | Cadastro e classificação dos pacientes. |
| `fila.h` | Definição da estrutura das filas. |
| `fila.c` | Geração de senhas e gerenciamento das filas. |
| `atendimento.h` | Declaração das funções de atendimento. |
| `atendimento.c` | Chamada e finalização dos atendimentos. |
| `painel.h` | Declaração da função do painel. |
| `painel.c` | Exibição das informações das filas. |

## 6. Opções do sistema

Ao executar o programa, o usuário encontra as seguintes opções:

1. Cadastrar paciente.
2. Consultar próxima senha.
3. Chamar paciente.
4. Finalizar atendimento.
5. Exibir painel.
0. Sair do sistema.

## 7. Tecnologias utilizadas

- Linguagem C.
- Compilador GCC.
- Ambiente de desenvolvimento e testes: GDB Online.

## 8. Como executar

Para compilar o projeto utilizando GCC, execute:

```bash
gcc main.c paciente.c fila.c atendimento.c painel.c -o clinica
```

Para executar:

```bash
./clinica
```

No Windows, o executável poderá ser iniciado com:

```powershell
.\clinica.exe
```

## 9. Conceitos aplicados

Durante o desenvolvimento foram utilizados:

- Estruturas (`struct`).
- Funções.
- Vetores.
- Ponteiros.
- Condicionais.
- Estruturas de repetição.
- Arquivos de cabeçalho (`.h`).
- Modularização.
- Filas e lógica FIFO.
- Validação de dados.

## 10. Considerações finais

O projeto demonstra a aplicação dos conceitos fundamentais da linguagem C na construção de um sistema de gerenciamento de atendimentos.

A divisão do código em módulos facilita a organização, manutenção e compreensão do programa.

## desenvolvido por
Yago Fernandes de Almeida
