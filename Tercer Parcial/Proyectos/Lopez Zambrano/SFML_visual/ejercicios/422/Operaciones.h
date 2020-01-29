const int MaximoAnioValido = 5000;
const int MinimoAnioValido = 1700;

class Operaciones
{
public:
	bool fecha_valida(int d, int m, int y);
private:
	bool esBisiesto(int anio);
};

