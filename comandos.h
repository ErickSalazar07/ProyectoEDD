#ifndef COMANDOS_H
#define COMANDOS_H
#include<string>

void interfaz();
void helpCmd(const std::string&);
void help();
void inicializar(const std::string&);
void iniciarInv(const std::string&);
void puntaje(const std::string&);
void iniciarArbol(const std::string&);
void iniciarArbolInv(const std::string&);
void palabrasPorPrefijo(const std::string&);
void palabrasPorSufijo(const std::string&);
void grafoPalabras();
void posiblesPalabras(const std::string&);
bool esPalabraValida(const std::string&);


#endif