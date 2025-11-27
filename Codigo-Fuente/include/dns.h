//Include's
#include <map>
#include <iostream>
#include <vector>
#include <string>

// Define's
#ifndef dns_h
#define dns_h

// Declaracion de funciones
class DNS{
private:
    std::map<std::string, std::string> tabla;

public:
    void insertar(const std::string &dominio, const std::string &ip);
    std::string buscar(const std::string &dominio);
    std::string buscarSecuencial(const std::string &dominio);
    std::string busquedaBinaria(const std::string &dominio, const std::vector<std::string> &ips, const std::vector<std::string> &dominios); //por implementar

};


#endif // dns_h