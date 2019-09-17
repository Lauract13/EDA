// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Predicado suma(p,q) = {sum i: p <= i < q: v[i]}

// Coste: Coste lineal O(n) siendo n el número de elementos del vector, ya que solo se pasa por cada elemento una vez


// P: {0 =< n =< long(v) && k <= long(v)}
int resolver(const std::vector<int> &v, int &n, int k, int tam) {

	int maximo = 0;
	int i = 0;
	n = 0; 
	int suma = 0;

	if (v.empty()) {
		return 0;
	}

	// I = { 0 <= i <= tam && maximo = (max p,q: 0 <= p <= q <= tam: suma(p,q))
	// FUNCION DE COTA: f(i) = tam - i, como tam es constante y i aumenta en cada iteración en algún momento se dará que tam - i <= 0 
	while (i < tam) {
		if (i < k) {
			maximo += v[i];
			suma += v[i];
			
		}
		else {
			suma -= v[i - k];
			suma += v[i];

			if (suma >= maximo) {
				maximo = suma; 
				n = i - k + 1;
			}
		}
		i++;
	}

	return maximo;
}
// Q: {maximo = (max p,q: 0 <= p <= q <= k: suma(p,q))}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int numCasos; 

	std::cin >> numCasos; 

	if (!std::cin)
		return false;
	int tam, k, pos = 0; 

	

	for (int i = 0; i < numCasos; i++) {
		std::cin >> tam >> k; 

		std::vector<int> vagones(tam);

		for (int j = 0; j < tam; j++) {
			std::cin >> vagones[j];
		}

		std::cout << pos << " " << resolver(vagones, pos, k, tam) << std::endl;
	}


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}