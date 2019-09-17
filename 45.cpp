// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


typedef struct{
	int suma;
	int inicio; 
	int dias;

} t_info;


t_info  resolver(const std::vector<int> &v, int num_dias){

	t_info ret = { 0, 0, -1 };

	int suma = 0; 
	int act = 0; 
	int comienzo = -1;
	int dias = 0; 

	while (act < num_dias){

		if (suma + v[act] > 0){ // Si la suma es positiva consideramos este dia
			suma += v[act];
			
			if (comienzo == -1){
				comienzo = act;
				dias = 1; 
			}
			else{
				dias++;
			}

		}
		else{
			suma = 0;
			dias = 0;
			comienzo = -1;
		}
		
		if (suma > ret.suma){
			ret.suma = suma;
			ret.dias = dias; 
			ret.inicio = comienzo;
		}
		else if (suma == ret.suma){
			if (dias < ret.dias){
				ret.suma = suma; 
				ret.dias = dias; 
				ret.inicio = comienzo;
			}
		}
			
	
		
		act++;
	}

	return ret;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int tam; 

	std::cin >> tam; 

	if (!std::cin)
		return false;
	
	std::vector<int> vector(tam); 
	
	for (int i = 0; i < tam; i++){
		std::cin >> vector[i];
	}

	
	t_info sol = resolver(vector, tam);

	std::cout << sol.suma << " " << sol.inicio << " " << sol.dias << std::endl;

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