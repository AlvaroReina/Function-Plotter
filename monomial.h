typedef struct T_Mono* T_Polynomial;

struct T_Mono {
	double multiplier;
	double degree;
	T_Polynomial next;
};

/* Crea la estructura utilizada para gestionar la memoria disponible. Inicialmente, sólo un nodo desde 0 a MAX */
/* Create a empty linked list. */
	void create(T_Polynomial* poly);
