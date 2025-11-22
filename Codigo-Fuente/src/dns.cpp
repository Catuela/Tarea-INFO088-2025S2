#include "../include/dns.h"

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