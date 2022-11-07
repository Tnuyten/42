typedef struct s_silent
{
	struct s_silent *prev;
	struct s_silent *next;
}

t_silent *silent_tail(t_silent *node)
{
	while(node->prev != NULL)
	{
		node = node->prev;
	}
	return (node);
}


int int main(int argc, char const *argv[]) {
	return 0;
}
