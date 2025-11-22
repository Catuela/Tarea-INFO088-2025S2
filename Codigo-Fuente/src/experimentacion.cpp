#include "experimentacion.h"
using namespace std;

void reservarMemoria(vector<string> &dominios, vector<string> &ips, int  n){
        dominios.reserve(n);
        ips.reserve(n);
}

vector<string> llenarDominios(vector<string> dominios, int n){
    for(int i = 0; i < n; i++){
        dominios.push_back("www.sitio" + to_string(i) + ".com"); //crea el dominio unico 
    }
    return dominios;
}

vector<string> llenarIps(vector<string> ips, int n){
    for(int i = 0; i < n; i++){ 
        ips.push_back(to_string(rand()%255) + "." +  //generan direcciones IP aleatorias
                      to_string(rand()%255) + "." + 
                      to_string(rand()%255) + "." +
                      to_string(rand()%255));
    }
    return ips;
}