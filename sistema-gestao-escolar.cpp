#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cadastro {
	char aluno[50], professor[50], disciplina[50];
};

cadastro recebeAluno();
cadastro recebeProfessor();
cadastro recebeDisciplina();
void alunoDisciplina(cadastro listaluno[], int maxa, cadastro listamateria[], int maxd, int ram[][25]);
void cancelalunoDisciplina(cadastro listaluno[], int maxa, cadastro listamateria[], int maxd, int ram[][25]);
void professorDisciplina(cadastro listamateria[], int maxd, cadastro listaprofessor[], int maxp, int rdp[][25]);
void imprimeAluno(cadastro listaluno[], int maxa);
void imprimeDisciplina(cadastro listamateria[], int maxd);
void imprimeProfessor(cadastro listaprofessor[], int maxp);
void lstmateriaAluno(int ram[][25], int maxd, int maxa, cadastro listamateria[]);
void lstalunoMateria(int ram[][25], int maxa, int maxd, cadastro listaluno[]);
void lstmateriaProfessor(int rdp[][25], int maxd, int maxp, cadastro listamateria[]);
void lstprofessorMateria(int rdp[][25], int maxp, int maxd, cadastro listaprofessor[]);

int main()
{
	cadastro listAluno[100], listaProfessor[25], listaDisciplina[25], aux;
	int opcao, ialuno = 0, iprofessor = 0, idisciplina = 0, relacaoalunomateria[100][25], one = 0, relacaoprofessormateria[25][25];
	do {
		printf("\t*****************************************************************\n");
		printf("\t*\t\t\t\t\t\t\t\t*\n");
		printf("\t*   1-Cadastrar aluno.\t\t\t\t\t\t*\n\t*   2-Cadastrar disciplina.\t\t\t\t\t*\n\t*   3-Cadastrar professor.\t\t\t\t\t*\n");
		printf("\t*   4-Cadastrar alunos em disciplinas.\t\t\t\t*\n\t*   5-Cancelar matricula de alunos em disciplinas.\t\t*\n");
		printf("\t*   6-Vincular professores em disciplinas.\t\t\t*\n\t*   7-Imprimir lista de todos alunos.\t\t\t\t*\n");
		printf("\t*   8-Imprimir lista de todas disciplinas.\t\t\t*\n\t*   9-Imprimir lista de todos professores.\t\t\t*\n");
		printf("\t*   10-Imprimir lista de disciplinas de um aluno.\t\t*\n\t*   11-Imprimir a lista de alunos em uma disciplina.\t\t*\n");
		printf("\t*   12-Imprimir lista de disciplinas dadas por um professor.\t*\n");
		printf("\t*   13-Imprimir lista de professores de uma disciplina.\t\t*\n\t*   14-Sair\t\t\t\t\t\t\t*\n");
		printf("\t*\t\t\t\t\t\t\t\t*\n");
		printf("\t*****************************************************************\n");
		printf("\tOpcao: ");
		scanf("%i", &opcao);
		printf("\n");

		switch (opcao)
		{
		case 1:
			listAluno[ialuno] = recebeAluno();
			ialuno++;
			break;
		case 2:
			listaDisciplina[idisciplina] = recebeDisciplina();
			idisciplina++;
			break;
		case 3:
			listaProfessor[iprofessor] = recebeProfessor();
			iprofessor++;
			break;
		case 4:
			alunoDisciplina(listAluno, ialuno, listaDisciplina, idisciplina, relacaoalunomateria);
			break;
		case 5:
			cancelalunoDisciplina(listAluno, ialuno, listaDisciplina, idisciplina, relacaoalunomateria);
			break;
		case 6:
			professorDisciplina(listaDisciplina, idisciplina, listaProfessor, iprofessor, relacaoprofessormateria);
			break;
		case 7:
			imprimeAluno(listAluno, ialuno);
			break;
		case 8:
			imprimeDisciplina(listaDisciplina, idisciplina);
			break;
		case 9:
			imprimeProfessor(listaProfessor, iprofessor);
			break;
		case 10:
			imprimeAluno(listAluno, ialuno);
			lstmateriaAluno(relacaoalunomateria, idisciplina, ialuno, listaDisciplina);
			break;
		case 11:
			imprimeDisciplina(listaDisciplina, idisciplina);
			lstalunoMateria(relacaoalunomateria, ialuno, idisciplina, listAluno);
			break;
		case 12:
			imprimeProfessor(listaProfessor, iprofessor);
			lstmateriaProfessor(relacaoprofessormateria, idisciplina, iprofessor, listaDisciplina);
			break;
		case 13:
			imprimeDisciplina(listaDisciplina, idisciplina);
			lstprofessorMateria(relacaoprofessormateria, iprofessor, idisciplina, listaProfessor);
			break;
		default:
			printf("\nOpcao invalida.\n");
			break;
		}
		if (one == 0)
		{
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j < 25; j++)
				{
					relacaoalunomateria[i][j] = 0;
				}
			}
			for (int i = 0; i < 25; i++)
			{
				for (int j = 0; j < 25; j++)
				{
					relacaoprofessormateria[i][j] = 0;
				}
			}
			one++;
		}
	} while (opcao != 14);

	return 0;
}

cadastro recebeAluno()
{
	cadastro nomealuno;
	printf("Nome do aluno:\n");
	fflush(stdin);
	scanf("%s", nomealuno.aluno);
	printf("\n");
	return nomealuno;
}

cadastro recebeDisciplina()
{
	cadastro nomedisciplina;
	printf("Nome da disciplina:\n");
	fflush(stdin);
	scanf("%s", nomedisciplina.disciplina);
	printf("\n");
	return nomedisciplina;
}

cadastro recebeProfessor()
{
	cadastro nomeprofessor;
	printf("Nome do professor:\n");
	fflush(stdin);
	scanf("%s", nomeprofessor.professor);
	printf("\n");
	return nomeprofessor;
}

void alunoDisciplina(cadastro listaluno[], int maxa, cadastro listamateria[], int maxd, int ram[][25])
{
	int i, j, op, num, conjaluno[100], conjmateria[25], confere = 0, iconja = 0, atribui = 0, iconjd = 0;
	printf("\nFazendo conjunto de alunos ...\n");
	do {
		for (i = 0; i < maxa; i++)
		{
			printf("%i - %s\n", i + 1, listaluno[i].aluno);
		}
		do {
			printf("\nInforme o numero do aluno: ");
			scanf("%i", &num);
		} while (num<1 || num>maxa);
		for (i = 0; i < atribui; i++)
		{
			if (num == conjaluno[i])
			{
				confere++;
			}
		}
		atribui++;
		if (confere == 0)
		{
			conjaluno[iconja] = num - 1;
			iconja++;
		}
		else
		{
			printf("\nAluno ja presente no conjunto.\n");
		}
		confere = 0;
		printf("\nConjunto de alunos (numero dos alunos): \n");
		for (i = 0; i < iconja; i++)
		{
			printf("%i - ", conjaluno[i] + 1);
		}
		printf("\n");
		do {
			printf("\n1-Adicionar outro aluno ao conjunto.\n2-Atribuir alunos em conjunto de disciplinas.\n");
			scanf("%i", &op);
			printf("\n");
		} while (op<1 || op>2);
	} while (op != 2);
	atribui = 0;
	confere = 0;
	printf("\nDisciplinas que serao atribuidas aos alunos ...\n");
	do {
		for (i = 0; i < maxd; i++)
		{
			printf("%i - %s\n", i + 1, listamateria[i].disciplina);
		}
		do {
			printf("\nInforme o numero da disciplina: ");
			scanf("%i", &num);
		} while (num<1 || num>maxd);
		for (i = 0; i < atribui; i++)
		{
			if (num == conjmateria[i])
			{
				confere++;
			}
		}
		atribui++;
		if (confere == 0)
		{
			conjmateria[iconjd] = num - 1;
			iconjd++;
		}
		else
		{
			printf("\nDisciplina ja presente no conjunto.\n");
		}
		confere = 0;
		printf("\nConjunto de disciplinas (numero das disciplinas): \n");
		for (i = 0; i < iconjd; i++)
		{
			printf("%i - ", conjmateria[i] + 1);
		}
		printf("\n");
		do {
			printf("\n1-Adicionar outra disciplina ao conjunto.\n2-Finalizar atribuicao.\n");
			scanf("%i", &op);
		} while (op<1 || op>2);
	} while (op != 2);
	for (int i = 0; i < iconja; i++)
	{
		for (int j = 0; j < iconjd; j++)
		{
			ram[conjaluno[i]][conjmateria[j]] = 1;
		}
	}
}

void cancelalunoDisciplina(cadastro listaluno[], int maxa, cadastro listamateria[], int maxd, int ram[][25])
{
	int i, j, op, num, conjaluno[100], conjmateria[25], confere = 0, iconja = 0, atribui = 0, iconjd = 0;
	printf("\nFazendo conjunto de alunos ...\n");
	do {
		for (i = 0; i < maxa; i++)
		{
			printf("%i - %s\n", i + 1, listaluno[i].aluno);
		}
		do {
			printf("\nInforme o numero do aluno: ");
			scanf("%i", &num);
		} while (num<1 || num>maxa);
		for (i = 0; i < atribui; i++)
		{
			if (num == conjaluno[i])
			{
				confere++;
			}
		}
		atribui++;
		if (confere == 0)
		{
			conjaluno[iconja] = num - 1;
			iconja++;
		}
		else
		{
			printf("\nAluno ja presente no conjunto.\n");
		}
		confere = 0;
		printf("\nConjunto de alunos (numero dos alunos): \n");
		for (i = 0; i < iconja; i++)
		{
			printf("%i - ", conjaluno[i] + 1);
		}
		printf("\n");
		do {
			printf("\n1-Adicionar outro aluno ao conjunto.\n2-Cancelar alunos em disciplinas.\n");
			scanf("%i", &op);
			printf("\n");
		} while (op<1 || op>2);
	} while (op != 2);
	atribui = 0;
	confere = 0;
	printf("\nDisciplinas que serao canceladas dos alunos ...\n");
	do {
		for (i = 0; i < maxd; i++)
		{
			printf("%i - %s\n", i + 1, listamateria[i].disciplina);
		}
		do {
			printf("\nInforme o numero da disciplina: ");
			scanf("%i", &num);
		} while (num<1 || num>maxd);
		for (i = 0; i < atribui; i++)
		{
			if (num == conjmateria[i])
			{
				confere++;
			}
		}
		atribui++;
		if (confere == 0)
		{
			conjmateria[iconjd] = num - 1;
			iconjd++;
		}
		else
		{
			printf("\nDisciplina ja presente no conjunto.\n");
		}
		confere = 0;
		printf("\nConjunto de disciplinas (numero das disciplinas): \n");
		for (i = 0; i < iconjd; i++)
		{
			printf("%i - ", conjmateria[i] + 1);
		}
		printf("\n");
		do {
			printf("\n1-Adicionar outra disciplina ao conjunto.\n2-Finalizar o cancelamento.\n");
			scanf("%i", &op);
		} while (op<1 || op>2);
	} while (op != 2);
	for (int i = 0; i < iconja; i++)
	{
		for (int j = 0; j < iconjd; j++)
		{
			ram[conjaluno[i]][conjmateria[j]] = 0;
		}
	}
}

void professorDisciplina(cadastro listamateria[], int maxd, cadastro listaprofessor[], int maxp, int rdp[][25])
{
	int i, j, op, num, conjprofessor[125], conjmateria[25], confere = 0, iconjp = 0, atribui = 0, iconjd = 0;
	printf("\nFazendo conjunto de professores ...\n");
	do {
		for (i = 0; i < maxp; i++)
		{
			printf("%i - %s\n", i + 1, listaprofessor[i].professor);
		}
		do {
			printf("\nInforme o numero do professor: ");
			scanf("%i", &num);
		} while (num<1 || num>maxp);
		for (i = 0; i < atribui; i++)
		{
			if (num == conjprofessor[i])
			{
				confere++;
			}
		}
		atribui++;
		if (confere == 0)
		{
			conjprofessor[iconjp] = num - 1;
			iconjp++;
		}
		else
		{
			printf("\nProfessor ja presente no conjunto.\n");
		}
		confere = 0;
		printf("\nConjunto de professores (numero dos professores): \n");
		for (i = 0; i < iconjp; i++)
		{
			printf("%i - ", conjprofessor[i] + 1);
		}
		printf("\n");
		do {
			printf("\n1-Adicionar outro professor ao conjunto.\n2-Atribuir professores em conjunto de disciplinas.\n");
			scanf("%i", &op);
			printf("\n");
		} while (op<1 || op>2);
	} while (op != 2);
	atribui = 0;
	confere = 0;
	printf("\nDisciplinas que serao atribuidas os professores ...\n");
	do {
		for (i = 0; i < maxd; i++)
		{
			printf("%i - %s\n", i + 1, listamateria[i].disciplina);
		}
		do {
			printf("\nInforme o numero da disciplina: ");
			scanf("%i", &num);
		} while (num<1 || num>maxd);
		for (i = 0; i < atribui; i++)
		{
			if (num == conjmateria[i])
			{
				confere++;
			}
		}
		atribui++;
		if (confere == 0)
		{
			conjmateria[iconjd] = num - 1;
			iconjd++;
		}
		else
		{
			printf("\nDisciplina ja presente no conjunto.\n");
		}
		confere = 0;
		printf("\nConjunto de disciplinas (numero das disciplinas): \n");
		for (i = 0; i < iconjd; i++)
		{
			printf("%i - ", conjmateria[i] + 1);
		}
		printf("\n");
		do {
			printf("\n1-Adicionar outra disciplina ao conjunto.\n2-Finalizar atribuicao.\n");
			scanf("%i", &op);
		} while (op<1 || op>2);
	} while (op != 2);
	for (int i = 0; i < iconjp; i++)
	{
		for (int j = 0; j < iconjd; j++)
		{
			rdp[conjprofessor[i]][conjmateria[j]] = 1;
		}
	}
}

void imprimeAluno(cadastro listaluno[], int maxa)
{
	printf("Lista de todos alunos:\n");
	for (int i = 0; i < maxa; i++)
	{
		printf("%i - %s\n", i + 1, listaluno[i].aluno);
	}
	printf("\n");
}

void imprimeDisciplina(cadastro listamateria[], int maxd)
{
	printf("Lista de todas as disciplinas:\n");
	for (int i = 0; i < maxd; i++)
	{
		printf("%i - %s\n", i + 1, listamateria[i].disciplina);
	}
	printf("\n");
}

void imprimeProfessor(cadastro listaprofessor[], int maxp)
{
	printf("Lista de todos professores:\n");
	for (int i = 0; i < maxp; i++)
	{
		printf("%i - %s\n", i + 1, listaprofessor[i].professor);
	}
	printf("\n");
}

void lstmateriaAluno(int ram[][25], int maxd, int maxa, cadastro listamateria[])
{
	int num;
	do {
		printf("\nDigite o numero do aluno, do qual deseja ver as disciplinas: ");
		scanf("%i", &num);
	} while (num<1 || num>maxa);
	printf("\nDisciplinas deste aluno: \n");
	for (int i = 0; i < maxd; i++)
	{
		if (ram[num-1][i] == 1)
		{
			printf("%i - %s\n", i + 1, listamateria[i].disciplina);
		}
	}
	printf("\n");
}

void lstalunoMateria(int ram[][25], int maxa, int maxd, cadastro listaluno[])
{
	int num;
	do {
		printf("\nDigite o numero da disciplina, do qual deseja ver os alunos: ");
		scanf("%i", &num);
	} while (num<1 || num>maxd);
	printf("\nAlunos desta disciplina: \n");
	for (int i = 0; i < maxa; i++)
	{
		if (ram[i][num-1] == 1)
		{
			printf("%i - %s\n", i + 1, listaluno[i].aluno);
		}
	}
	printf("\n");
}

void lstmateriaProfessor(int rdp[][25], int maxd, int maxp, cadastro listamateria[])
{
	int num;
	do {
		printf("\nDigite o numero do professor, do qual deseja ver as disciplinas: ");
		scanf("%i", &num);
	} while (num<1 || num>maxp);
	printf("\nO professor escolhido ministra a disciplina:\n");
	for (int i = 0; i < maxd; i++)
	{
		if (rdp[num-1][i] == 1)
		{
			printf("%i - %s\n", i + 1, listamateria[i].disciplina);
		}
	}
	printf("\n");
}

void lstprofessorMateria(int rdp[][25], int maxp, int maxd, cadastro listaprofessor[])
{
	int num;
	do {
		printf("\nDigite o numero da disciplina, do qual deseja ver os professores: ");
		scanf("%i", &num);
	} while (num<1 || num>maxd);
	printf("\nA disciplina escolhida tem como professor:\n");
	for (int i = 0; i < maxp; i++)
	{
		if (rdp[i][num-1] == 1)
		{
			printf("%i - %s\n", i + 1, listaprofessor[i].professor);
		}
	}
	printf("\n");
}