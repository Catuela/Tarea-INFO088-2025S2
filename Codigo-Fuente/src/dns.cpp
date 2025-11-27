#include "../include/dns.h"
#include <chrono>
#include <ctime>

void DNS::insertar(const std::string& dominio, const std::string& ip){
    tabla[dominio] = ip;
}

std::string DNS::buscar(const std::string &dominio){
    auto it = tabla.find(dominio);
    if(it != tabla.end()){
        return it->second;
    }
    return "no se encontro";
}

std::string DNS::buscarSecuencial(const std::string &dominio){
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    for(const auto &entry : tabla){
        if(entry.first == dominio){
            end = std::chrono::system_clock::now();
            std::cout << "Tiempo de busqueda secuencial: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsegundos" << std::endl;
            return entry.second;
        }
    }

    end = std::chrono::system_clock::now();
    return "no se encontro";
}

std::string DNS::busquedaBinaria(const std::string &encuentra, const std::vector<std::string> &ips, const std::vector<std::string> &dominios){
    size_t l = 0;
    size_t r = dominios.size() - 1;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    while (l <= r) {
        size_t m = l + (r - l) / 2;
        if (tabla.find(encuentra)->first == dominios[m])  {
            end = std::chrono::system_clock::now();
            std::cout << "Tiempo de busqueda binaria: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsegundos" << std::endl;
            return ips[m];
        }
        else if (encuentra < dominios[m] )
            r = m - 1;
        else
            l = m + 1;
    }
      return "No se encontró la IP correspondiente al dominio solicitado";
}