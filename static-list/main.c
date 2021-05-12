#include <stdio.h>
#include "StaticList.c"

int main()
{
	List *list = create_list();

	Student st1 = {.name = "Afonso", .registry = 1, .n1 = 61, .n2 = 78, .n3 = 91, .n4 = 58};
	Student st2 = {.name = "Afons2", .registry = 2, .n1 = 61, .n2 = 78, .n3 = 91, .n4 = 58};
	Student st3 = {.name = "Afons3", .registry = 3, .n1 = 61, .n2 = 78, .n3 = 91, .n4 = 58};
	Student st4 = {.name = "Afons4", .registry = 4, .n1 = 61, .n2 = 78, .n3 = 91, .n4 = 58};

	add_last(list, st1);
	add_first(list, st2);
	add_first(list, st3);

	remove_first(list);

	Student st;

	find_by_index(list, 2, &st);

	printf("O primeiro aluno é: %d\n", st.registry);

	int l = length_list(list);

	printf("O tamanho da lista é: %d\n", l);
	printf("end\n");
	free_list(list);
	return 0;
}
