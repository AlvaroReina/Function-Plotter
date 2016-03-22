typedef struct T_Mono* T_Polynomial;

struct T_Mono {
	double multiplier;
	double degree;
	void *funct;
	T_Polynomial next;
};

/* Create a empty expression */
	void create(T_Polynomial* poly);

/* Destroy a expression */
    void destroy(T_Polynomial* poly);

/* Add a monomial to the expression */
    void add(T_Polynomial* poly, T_Polynomial* mono);

/* Create a monomial */
    T_Polynomial createMono();

/* Create a monomial + Add to the expression */
    void addc(T_Polynomial* poly);

/* Shows a expression */
    void show(T_Polynomial poly);
