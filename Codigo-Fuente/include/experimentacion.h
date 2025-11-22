//Include's
#include "dns.h"
#include <vector>
#include <iostream>
#include <string>

// Define's
#ifndef experimentacion_h
#define experimentacion_h

// Declaracion de funciones
//reservar memoria para cada vector
void reservarMemoria(std::vector<std::string> &dominios, std::vector<std::string> &ip, int n);

//creacion de ambos vectores y llenarlos
std::vector<std::string> llenarDominios(std::vector<std::string> dominio, int n);
std::vector<std::string> llenarIps(std::vector<std::string> ips, int n);



#endif