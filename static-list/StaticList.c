#include <malloc.h>
#include "StaticList.h"

struct list
{
	int len;
	Student data[MAX];
};

List *create_list()
{
	List *list = (List *)malloc(sizeof(List));

	if (list != NULL)
	{
		list->len = 0;
		return list;
	}
}

void free_list(List *l)
{
	free(l);
}

int length_list(List *l)
{
	if (l != NULL)
		return l->len;

	return -1;
}

int is_full(List *l)
{
	if (l != NULL)
		return l->len == MAX;

	return -1;
}

int is_empty(List *l)
{
	if (l != NULL)
		return l->len == 0;

	return -1;
}

int add_last(List *li, Student st)
{
	// Verifica se a referência passada é nula
	if (li == NULL)
		return 0;

	// Verifica se a lista está cheia
	if (is_full(li))
		return 0;

	// Adiciona o aluno na próxima posição vazia
	li->data[li->len] = st;
	li->len++;
	return 1;
}
int add_first(List *li, Student st)
{
	// Verifica se a referência passada é nula
	if (li == NULL)
		return 0;

	// Verifica se a lista está cheia
	if (is_full(li))
		return 0;

	int i;
	for (i = li->len - 1; i > 0; i--)
		li->data[i + 1] = li->data[i];

	li->data[0] = st;
	li->len++;
	return 1;
}

int add_sorted(List *li, Student st)
{
	// Verifica se a referência passada é nula
	if (li == NULL)
		return 0;

	// Verifica se a lista está cheia
	if (is_full(li))
		return 0;

	int i, k = 0;

	// Procura uma posição onde a matricula passada por argumento é menor que as matirculas da lista
	// e incrementa o valor de 'i' a cada interação para salvar a posição
	while (i < li->len && li->data[i].registry < st.registry)
		i++;

	// Realiza a iteração da última posição preenchida até a posição onde matricula passada por argumento
	// é menor que as matirculas da lista passando os alunos uma posição para frente
	for (k = li->len - 1; k >= i; k--)
		li->data[k + 1] = li->data[k];

	// salva o aluno em questão na posição que ficou livre após movermos os alunos com a matricula
	//maior uma posição para frente
	li->data[i] = st;
	li->len++;
	return 1;
}

int remove_last(List *l)
{
	// verifica se a lista está vazia ou é nula
	if (l == NULL)
		return 0;
	if (l->len == 0)
		return 0;
	// caso não seja, diminui o tamanho do array em uma posição deixando a última posição inacessível
	l->len--;
	return 1;
}
int remove_first(List *li)
{
	// verifica se a lista está vazia ou é nula
	if (li == NULL)
		return 0;
	if (li->len == 0)
		return 0;

	int i;
	// percorre a lista pegando o elemento e passando para uma posição anterior
	// [0] [1] [2] [3]
	// [1] [2] [3] [3] -> ultima posição inacessível
	for (i = li->len - 1; i > 1; i--)
		li->data[i - 1] = li->data[i];

	li->len--;
	return 1;
}

int remove_by_register(List *li, Student st)
{
	// verifica se a lista está vazia ou é nula
	if (li == NULL)
		return 0;
	if (li->len == 0)
		return 0;

	int i, k = 0;
	// Procura uma posição onde a matricula passada por argumento é igual a uma da lista
	// e incrementa 'i' a cada interação falsa até achar a posição em questão
	while (i < li->len && li->data[i].registry != st.registry)
		i++;
	// percorre a lista pegando o elemento e passando para uma posição anterior
	// até a posição da matricula a ser excluida
	for (k = li->len - 1; k > i; k--)
		li->data[k - 1] = li->data[k];

	li->len--;
	return 1;
}

int find_by_index(List *l, int pos, Student *st)
{
	if (l == NULL || pos < 0 || pos >= l->len)
		return 0;

	*st = l->data[pos];
	return 1;
}

int find_by_register(List *l, Student find, Student *st)
{
}
