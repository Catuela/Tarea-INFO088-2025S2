#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include "../include/dns.h"
#include "../include/experimentacion.h"
using namespace std;

int main() {
    int n;
    cout << "ingresar numero de pruebas a realizar: ";
    cin >> n;
    //creacion de vectores vacios y se reserva memoria n a cada uno
    vector<string> dominios, ips;
    reservarMemoria(dominios, ips, n);


    DNS dns;

    // Construcción
    chrono::time_point<chrono::system_clock> start, end; //inicio medicion tiempo
    start = chrono::system_clock::now();

    dominios = llenarDominios(dominios, n);
    ips = llenarIps(ips, n);

    for (size_t i = 0; i < n; i++) {
        dns.insertar(dominios[i], ips[i]);
    }
    end = std::chrono::system_clock::now();

    auto tiempo = end - start;
    cout << "tiempo de construccion para " << n << " entradas: " << chrono::duration_cast<chrono::microseconds>(tiempo).count() << " microsegundos" << endl;
    // Prueba simple de búsqueda
    chrono::time_point<chrono::system_clock> inicio, fin; //armando medicion tiempo busqueda


    inicio = chrono::system_clock::now(); //inciando tiempo de busqueda

    string test = dominios[rand() % n];
    cout << "Buscando: " << test << "\n";
    cout << "IP encontrada: " << dns.buscar(test) << endl;

    fin = std::chrono::system_clock::now(); //terminando tiempo de busqueda
    auto tiempoBusqueda = fin - inicio;
    cout << "tiempo de busqueda para " << n << " entradas: " << chrono::duration_cast<chrono::microseconds>(tiempoBusqueda).count() << " microsegundos" << endl;
    cout << "IP encontrada (busqueda secuencial): " << dns.buscarSecuencial(test) << endl;
    cout << "IP encontrada (busqueda binaria): " << dns.busquedaBinaria(test, ips, dominios) << endl;

    return 0;
} 