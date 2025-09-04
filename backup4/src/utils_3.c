/* Em src/utils_3.c */

#include "../push_swap.h"

void	do_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

// Esta função faz a checagem de overflow comparando as strings.
// Assim, não precisamos de 'atol'.
static void	check_overflow(const char *str)
{
	int		is_neg;
	int		len;
	char	*max_int;

	is_neg = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = 1;
		str++;
	}
	len = ft_strlen(str);
	if (len > 10) // Mais de 10 dígitos sempre estoura o limite de um int
		do_error();
	if (len < 10) // Menos de 10 dígitos nunca estoura
		return ;
	// Se tiver exatamente 10 dígitos, comparamos com o limite
	if (is_neg)
		max_int = "2147483648";
	else
		max_int = "2147483647";
	if (ft_strncmp(str, max_int, 10) > 0)
		do_error();
}

// Esta é a nossa nova função principal de validação.
// Ela verifica tudo e só no final chama a ft_atoi da sua libft.
int	validate_and_convert(const char *str)
{
	int i;

	i = 0;
	// 1. Checa sintaxe básica (sinal e dígitos)
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0') // Apenas um sinal não é válido
		do_error();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			do_error();
		i++;
	}
	// 2. Checa overflow
	check_overflow(str);
	// 3. Se tudo passou, é seguro converter com a ft_atoi
	return (ft_atoi(str));
}

// A função de checar repetições continua aqui.
void	check_rep(t_push **a)
{
	t_push	*tmp1;
	t_push	*tmp2;

	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->number == tmp2->number)
				do_error();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}