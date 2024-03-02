#ifndef COMANDOS_H
#define COMANDOS_H
#include<vector>
#include<string>

void interfaz();
void helpCmd(const std::string&);
void help();
void inicializar(const std::string&,std::vector<std::vector<std::string>>&);
void iniciarInv(const std::string&,std::vector<std::vector<std::string>>&);
void puntaje(const std::string&,const std::vector<std::vector<std::string>>&,const std::vector<std::vector<std::string>>&);
void iniciarArbol(const std::string&);
void iniciarArbolInv(const std::string&);
void palabrasPorPrefijo(const std::string&);
void palabrasPorSufijo(const std::string&);
void grafoPalabras();
void posiblesPalabras(const std::string&);
bool esPalabraValida(const std::string&);
bool encuentraDiccionario(const std::string&,const std::vector<std::string>&);
bool encuentraDiccionarioInv(const std::string&,const std::vector<std::string>&);

#endif