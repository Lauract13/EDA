// Laura Casas Torres
// E10


#include <iostream>

#include <fstream>
#include "stack_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string frase; 
	bool correcto = true;
	std::getline(std::cin, frase);

	if (!std::cin)
		return false;

	stack<char> pila;
	int i = 0;
	if (frase.size() == 1 && (frase[i] == '(' || frase[i] == '[' || frase[i] == '{')){
		correcto = false;
	}

	while (i < frase.size() && correcto){
		if (frase[i] == '(' || frase[i] == '[' || frase[i] == '{'){
			pila.push(frase[i]);
		}
		else if (frase[i] == ')' || frase[i] == ']' || frase[i] == '}'){
			if (!pila.empty()){
				if (frase[i] == ']' && pila.top() == '['){
					pila.pop();
				}
				else if (frase[i] == ')' && pila.top() == '('){
					pila.pop();
				}
				else if (frase[i] == '}' && pila.top() == '{'){
					pila.pop();
				}
				else{
					correcto = false;
				}
			}
			else{
				correcto = false;
			}
		}
		i++;
	}


	// escribir sol
	if (correcto && pila.size() <= 0){
		std::cout << "SI" << std::endl;
	}
	else{
		std::cout << "NO" << std::endl;
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