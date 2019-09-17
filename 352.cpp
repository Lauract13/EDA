// Laura Casas Torres
// E10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>

const int MAX = 15;

class carnet_puntos{
private:
	std::unordered_map<std::string, int> conductores;
	std::vector<std::unordered_map<std::string, int>> consulta;



public:
	carnet_puntos() : consulta(std::vector<std::unordered_map<std::string, int>>(MAX + 1)){};




	void nuevo(const std::string &dni){
		if (!conductores.count(dni)){
			conductores[dni] = 15;
			consulta[15][dni] = 15;
		}
		else{
			throw std::domain_error("Conductor duplicado");
		}
	}

	void quitar(const std::string &dni, const int &puntos){
		if (conductores.count(dni)){
			int p = conductores.at(dni);
			consulta[p].erase(dni);
			if (p - puntos < 0){
				p = 0;

			}
			else{
				p = p - puntos;
			}
			consulta[p][dni] = p;
			conductores[dni] = p;
		}
		else{
			throw std::domain_error("Conductor inexistente");
		}
	}
	int consultar(const std::string &dni){
		if (conductores.count(dni)){
			return conductores[dni];
		}
		else{
			throw std::domain_error("Conductor inexistente");
		}
	}

	int cuantos_con_puntos(const int &puntos){
		int cuantos = 0;
		if (puntos > 15 || puntos < 0){
			throw std::domain_error("Puntos no validos");
		}
		else{
			return consulta[puntos].size();
		}
	}
	void recuperar(const std::string &dni, const int &puntos){
		if (conductores.count(dni)){
			int p = conductores[dni];
			conductores.erase(dni);
			if (puntos + p > 15){
				conductores[dni] = 15;
				consulta[15][dni] = 15;
			}
			else{
				consulta[p].erase(dni);
				conductores[dni] = p + puntos;
				consulta[conductores[dni]][dni] = conductores[dni];
			}
		}
		else{
			throw std::domain_error("Conductor inexistente");
		}
	}

	std::unordered_map<std::string, int> lista_por_puntos(const int &puntos){
		if (puntos < 0 || puntos > 15){
			throw std::domain_error("Puntos no validos");
		}
		else{
			return consulta[puntos];
		}
	}


};
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string orden, dni;
	int puntos;

	std::cin >> orden;
	if (!std::cin)
		return false;

	carnet_puntos carnet_p;

	while (orden != "FIN"){
		try{
			if (orden == "nuevo"){
				std::cin >> dni;
				carnet_p.nuevo(dni);

			}
			else if (orden == "quitar"){

				std::cin >> dni >> puntos;
				carnet_p.quitar(dni, puntos);

			}
			else if (orden == "recuperar"){
				std::cin >> dni >> puntos;
				carnet_p.recuperar(dni, puntos);
			}
			else if (orden == "consultar"){
				std::cin >> dni;
				std::cout << "Puntos de " << dni << ": " << carnet_p.consultar(dni) << std::endl;
			}
			else if (orden == "cuantos_con_puntos"){
				std::cin >> puntos;
				std::cout << "Con " << puntos << " puntos hay " << carnet_p.cuantos_con_puntos(puntos) << std::endl;
			}
			else if (orden == "lista_por_puntos"){
				std::cin >> puntos; 
				std::unordered_map<std::string, int> aux = carnet_p.lista_por_puntos(puntos);

				std::cout << "Tienen " << puntos  << " puntos: ";
				for (auto a : aux){
					std::cout << a.first << " ";
				}
				std::cout << std::endl;
			}
		}
		catch (const std::domain_error& e) {

			std::cout << "ERROR: " << e.what() << std::endl;

		}
		std::cin >> orden;
	}

	std::cout << "---" << std::endl;

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