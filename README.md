Push_SwapO push_swap é um projeto da 42 que desafia a ordenar uma pilha de números inteiros usando um conjunto limitado de operações, com o objetivo de usar o menor número de movimentos possível. Este documento detalha a lógica, a estrutura e o funcionamento deste projeto.Visão Geral do AlgoritmoA estratégia principal varia conforme o número de elementos a serem ordenados:Listas Pequenas (2 a 5 elementos): São usados algoritmos específicos e otimizados para resolver a ordenação com um número mínimo de passos.Listas Grandes (mais de 5 elementos): É implementado um algoritmo baseado em "chunks" (pedaços), que divide o problema em partes menores. Os números são indexados, movidos em blocos para uma pilha auxiliar (b) e, em seguida, retornados para a pilha principal (a) na ordem correta.Como Compilar e ExecutarCompilaçãoO projeto inclui um Makefile que simplifica todo o processo. Para compilar, basta executar:make
Isso irá compilar a libft e, em seguida, o executável push_swap.ExecuçãoO programa aceita os números a serem ordenados como argumentos. Eles podem ser passados de duas formas:Como múltiplos argumentos:./push_swap 4 67 3 -1 100
Como uma única string entre aspas:./push_swap "4 67 3 -1 100"
O programa irá imprimir na saída padrão a sequência de operações necessárias para ordenar os números.As Operações PermitidasApenas 11 operações são permitidas para manipular as pilhas:OperaçãoDescriçãosaSwap A: Troca os 2 primeiros elementos no topo da pilha a.sbSwap B: Troca os 2 primeiros elementos no topo da pilha b.ssExecuta sa e sb ao mesmo tempo.paPush A: Pega o primeiro elemento de b e o coloca no topo de a.pbPush B: Pega o primeiro elemento de a e o coloca no topo de b.raRotate A: Move o elemento do topo de a para o final da pilha.rbRotate B: Move o elemento do topo de b para o final da pilha.rrExecuta ra e rb ao mesmo tempo.rraReverse Rotate A: Move o último elemento de a para o topo.rrbReverse Rotate B: Move o último elemento de b para o topo.rrrExecuta rra e rrb ao mesmo tempo.Estrutura de Arquivos e FunçõesO projeto é organizado de forma modular para separar responsabilidades, como validação, operações de pilha e algoritmos de ordenação.push_swap.c (O Ponto de Entrada)Este arquivo controla o fluxo principal do programa.main: Orquestra todo o processo:Verifica se há argumentos suficientes.Inicializa as pilhas a e b.Chama parse_input para preencher a pilha a.Chama check_rep para validar se há números duplicados.Verifica se a pilha já está ordenada com is_sorted.Se não, chama sort para iniciar a ordenação.Libera a memória alocada com free_stack.parse_input: Processa os argumentos da linha de comando. Ele usa ft_split para lidar com argumentos passados como uma única string.fill_stack_from_args: Recebe os números (já como strings) e os converte para inteiros usando parse_number, criando um novo nó na pilha a para cada um.free_stack / free_split: Funções utilitárias para garantir que toda a memória alocada seja liberada ao final da execução.src/validation.c (Validação de Entrada)Responsável por garantir que a entrada do usuário seja válida.exit_error: Imprime "Error" na saída de erro padrão e encerra o programa. É chamada sempre que uma entrada inválida é detectada.parse_number: Verifica se uma string representa um número inteiro válido (contendo apenas dígitos e um sinal opcional no início) e se está dentro dos limites de um int.check_rep: Percorre a pilha a para garantir que não existem números repetidos.src/stack_utils.c (Funções Utilitárias da Pilha)Contém funções que fornecem informações sobre o estado das pilhas.is_sorted: Verifica se a pilha a já está ordenada em ordem crescente.minnum: Retorna o menor valor numérico presente na pilha.maxnum: Retorna o maior valor numérico presente na pilha.maxindex: Retorna o maior índice presente na pilha (usado no sort_big).src/sort.c (Os Algoritmos de Ordenação)Aqui reside a lógica principal de ordenação.sort: Atua como um roteador. Com base no tamanho da pilha, ele decide qual algoritmo específico chamar (sort_2, sort_3, sort_5 ou sort_big).sort_2: Ordena 2 elementos com uma única operação sa, se necessário.sort_3: Ordena 3 elementos com uma lógica que usa no máximo 2 operações.sort_5: Ordena 4 ou 5 elementos. A estratégia é mover os menores elementos para a pilha b, ordenar os 3 restantes em a, e depois retornar os elementos de b.sort_big: O algoritmo para mais de 5 elementos. Veja a análise detalhada abaixo.src/sort_utils.c (Auxiliares de Ordenação)Funções de suporte para os algoritmos de ordenação, principalmente o sort_big.set_index: Atribui um índice a cada nó da pilha, representando sua posição final ordenada. Essencial para o sort_big.min_pos / max_pos: Determinam se um elemento está na metade superior ou inferior de uma pilha. Isso é usado para decidir se é mais eficiente usar rotate (ra/rb) ou reverse rotate (rra/rrb) para movê-lo para o topo.sort_pa: Parte final do sort_big. Move todos os elementos de b de volta para a de forma ordenada, sempre encontrando o próximo maior elemento e posicionando-o no topo antes do pa.src/push.c, src/swap.c, src/rotate.c, src/rotate_rev.cCada um desses arquivos implementa um grupo de operações permitidas (pa/pb, sa/sb/ss, etc.). A lógica é encapsulada em funções estáticas (push, swap, rotate) e as funções exportadas (pa, ra, etc.) chamam a lógica base e imprimem o nome da operação na saída padrão.O Algoritmo sort_big: Uma Análise DetalhadaPara ordenar pilhas com um grande número de elementos (mais de 5), o push_swap adota uma estratégia sofisticada e eficiente conhecida como "radix sort" simplificado, ou mais comumente, o método de "chunks" (pedaços). A abordagem sort_big move os números de forma inteligente da pilha a para a b e de volta, garantindo uma ordenação com um número otimizado de movimentos.Esta análise detalha as três etapas fundamentais do algoritmo.Etapa 1: A Indexação - Criando o Roteiro para a OrdenaçãoA primeira e mais crucial etapa é a indexação. Em vez de trabalhar com os valores brutos dos números (que podem ser quaisquer inteiros, como -500, 42, 1337), o algoritmo atribui a cada número um índice que representa sua posição final na pilha ordenada.O menor número da pilha recebe o índice 0.O segundo menor número recebe o índice 1....e assim por diante, até o maior número, que recebe o índice N-1, onde N é o número total de elementos.Exemplo Prático:Pilha a inicial: [10, -5, 100, 0]Após a indexação (set_index):O número -5 (o menor) recebe o index = 0.O número 0 recebe o index = 1.O número 10 recebe o index = 2.O número 100 (o maior) recebe o index = 3.Essa abstração é poderosa porque transforma um problema de ordenação de valores arbitrários em um problema muito mais simples: colocar os índices de 0 a N-1 em ordem.Etapa 2: A Conquista - Movendo Elementos de a para b por ChunksCom os índices definidos, o algoritmo começa a mover os números de a para b. Ele não faz isso de forma aleatória; ele o faz em "chunks". Um chunk_size (tamanho do pedaço, ex: 15 para 100 números, 30 para 500) define uma faixa de índices que o algoritmo deve procurar e mover.void	sort_big(t_list **a, t_list **b, int chunk_size)
{
	int	i; // 'i' marca o início do primeiro chunk a ser procurado

	i = 0;
	while ((*a) != NULL) // 1. Continua até a pilha 'a' estar vazia
	{
		// Se o topo de 'a' pertence a um chunk anterior (otimização)
		if (i > 0 && (*a)->index < i)
		{
			pb(a, b);
			i++;
            // Otimização: se o próximo em 'a' precisa ser rotacionado,
            // e o que acabamos de mover para 'b' também precisa,
            // fazemos os dois de uma vez com 'rr'.
			if ((*a) && (*a)->index >= i + chunk_size)
				rr(a, b);
			else
				rb(b); // Senão, só rotacionamos 'b'
		}
		// Se o topo de 'a' pertence ao chunk ATUAL
		else if ((*a)->index < i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		// Se o topo de 'a' pertence a um chunk futuro
		else if ((*a)->index >= i + chunk_size)
			ra(a); // Deixa ele para depois, rotacionando 'a'
	}
	sort_pa(a, b); // Inicia a fase de reconstrução
}
Como funciona na prática:Definição do Alvo: O algoritmo começa procurando por números cujos índices estejam na faixa [i, i + chunk_size - 1]. No início, com i = 0 e chunk_size = 15, ele busca os índices de 0 a 14.Busca e Movimentação:Se o número no topo da pilha a tem um índice dentro dessa faixa, ele é movido para b com pb. A variável i é incrementada, pois "encontramos" mais um número da sequência.Se o número no topo tem um índice maior que a faixa-alvo, significa que ele pertence a um chunk futuro. O algoritmo o "ignora" temporariamente, executando ra para movê-lo para o final da pilha a e analisar o próximo.Avanço dos Chunks: Conforme os números são movidos para b, a variável i aumenta, e com ela, a faixa de busca [i, i + chunk_size - 1] também se desloca, fazendo o algoritmo procurar pelo próximo "pedaço" da sequência ordenada.Otimização: A condição (*a)->index < i lida com casos onde um número de um chunk anterior ficou para trás. Ele é movido para b e, em seguida, rb é usado para "organizá-lo" dentro de b, colocando-o abaixo dos números maiores que já estão lá. A verificação para usar rr é uma otimização chave que economiza uma instrução ao realizar duas rotações necessárias simultaneamente.Ao final desta fase, a está vazia e b contém todos os números, com os de maior índice geralmente mais próximos do topo.Etapa 3: A Reconstrução - Ordenando de b para aAgora, com a pilha b cheia, a função sort_pa tem a tarefa final: mover cada número de volta para a, mas na ordem perfeitamente correta (do maior para o menor).void	sort_pa(t_list **a, t_list **b)
{
	while (*b != NULL) // Continua até a pilha 'b' esvaziar
	{
		// 1. Encontra qual é o maior índice atualmente em 'b'
		int max_idx = maxindex(b);

		// 2. Se o número com o maior índice não está no topo...
		if ((*b)->index != max_idx)
		{
			// 3. Usa a rotação mais curta (rb ou rrb) para trazê-lo ao topo.
			// A função max_pos calcula se é mais rápido girar para frente ou para trás.
			if (!max_pos(b, max_idx, ft_lst_size(b)))
				rb(b);
			else
				rrb(b);
		}
		// 4. Quando o maior está no topo...
		else
			pa(a, b); // ...o move para 'a'.
	}
}
Como funciona na prática:Encontrar o Próximo Maior: O loop começa identificando o número com o maior índice que ainda resta em b.Posicionar para o Push: Ele então calcula a maneira mais eficiente de levar esse número para o topo de b. Se o número estiver na metade superior da pilha, rb é usado. Se estiver na metade inferior, rrb é mais rápido.Empurrar para a: Com o número de maior índice no topo, pa o move para a pilha a.Repetir: O processo se repete. A cada iteração, o próximo maior número de b é encontrado, posicionado e movido para a.Como estamos sempre colocando o próximo maior elemento no topo de a, ao final do processo, a pilha a estará perfeitamente ordenada, do menor (no topo) ao maior (na base).
