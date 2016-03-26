typedef struct T_Mono* T_Polynomial;

typedef double (*functiontype)(double);

struct T_Mono {
	double multiplier;
	double degree;
	//double *funct;
	functiontype funct;
	T_Polynomial next;
};

/* Creates an empty expression with a initial node that have a 0x multiplier */
	void create(T_Polynomial* poly);

/* Destroys an expression */
    void destroy(T_Polynomial* poly);

/* Add a monomial to the expression */
    void add(T_Polynomial* poly, T_Polynomial* mono);

/* Creates a monomial */
    T_Polynomial createMono();

/* Create a monomial and add it to the expression */
    void addc(T_Polynomial* poly);

/* Shows an expression (ignores monomials with a 0x multiplier) */
    void show(T_Polynomial poly);

/* Calculates every point between minRange and maxRange */
    void plot(int minRange, int maxRange, T_Polynomial* poly);

/* Calculate a single point in a function */
    double calcPoint(double x, functiontype funct);

/* Allow to select a function when creating a monomial */
    functiontype selectFunction();

/* Helps with better representation of a expression */
    void printfunction(functiontype funct);
