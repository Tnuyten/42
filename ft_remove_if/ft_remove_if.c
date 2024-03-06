#include "t_list.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEM 6

int compare_num(void* a, void* b) {
	if (a == NULL || b == NULL)
		return 0;
	int aa = *(int*)a;
	int bb = *(int*)b;

	if (aa == bb)
		return 0;
	return aa - bb;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()) {
	if (begin_list == NULL || data_ref == NULL)
		return ;
	if (*begin_list == NULL)
		return ;

	t_list *head = *begin_list;
	while (cmp(head->data, data_ref) == 0) {
		printf("%s: %d\n", "Head Node to remove found", *(int *)(head->data));

		t_list *next = head->next;
		head->next = NULL;
		head->data = NULL;
		free(head);
		*begin_list = next;
		head = next;
	}

	t_list *iter = *begin_list;

	while (iter && iter->next) {
		if (iter && cmp(iter->next->data, data_ref) == 0) {
			printf("%s: %d\n", "Node to remove found", *(int *)iter->next->data);
			t_list *temp = iter->next;
			iter->next = iter->next->next;
			free(temp);

		}
		iter = iter->next;
	}
	
	return ;
}

t_list* list_new(void *data) {
	t_list *node = calloc(sizeof(t_list), 1);
	if (node == NULL) {
		printf("%s\n", "Malloc was NULL");
		return node;
	}
	node->next = NULL;
	node->data = data;
	printf("%s\n", "Made new node");

	return node;
}

void list_add_back(t_list **list, t_list *node) {
	if (list == NULL || node == NULL) {
		printf("%s\n", "List or node is NULL");
		return ;
	}
	if (*list == NULL) {
		printf("%s\n", "Assigning new head node");
		*list = node;
		return ;
	}
	
	t_list *iter = *list;
	while(iter && iter->next != NULL) {
		iter = iter->next;
	}
	iter->next = node;
	printf("%s\n", "Added node to back");
}

void ft_list_print(t_list** list) {
	if (list == NULL) {
		printf("%s\n", "Printf list is NULL");
		return;
	}
	t_list *iter = *list;

	while(iter) {
		if (iter->next != NULL) {
			printf("%d, ", *(int *)(iter->data));
		} else {
			printf("%d\n", *(int *)(iter->data));
		}
		iter = iter->next;
	}
}

t_list* ft_list_next(t_list** head, int n) {
	if (head == NULL)
		return NULL;
	t_list *iter = *head;

	while (iter && n) {
		n--;
		iter = iter->next;
	}

	return iter;
}

int main() {
	t_list **head = calloc(sizeof(t_list*), 1);

	int nums[NUM_ELEM] = {1, 1, 3, 4, 5, 6};

	for (int i = 0; i < NUM_ELEM; i++) {
		printf("%s %d\n", "Making new node", i);
		t_list* node = list_new(&nums[i]);
		printf("%s\n", "Adding node to back");
		list_add_back(head, node);
		printf("\n");
	}

	ft_list_print(head);
	printf("\n");

	ft_list_remove_if(head, &nums[3], compare_num);
	ft_list_print(head);
	printf("\n");

	ft_list_remove_if(head, &nums[0], compare_num);
	ft_list_print(head);
	printf("\n");

	ft_list_remove_if(head, &nums[5], compare_num);
	ft_list_print(head);
	printf("\n");

	ft_list_remove_if(head, &nums[2], compare_num);
	ft_list_print(head);
	printf("\n");

	// CLEANUP
	t_list* iter = *head;
	while (iter) {
		t_list *next = iter->next;
		free(iter);
		iter = next;
	}
	free(head);
}