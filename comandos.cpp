#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<string>
#include"comandos.h"

int banderas = 0;


void interfaz(){ system("cls");
    
    std::string comando;

    do{
        std::cout<<"$ ";
        getline(std::cin,comando);

        
        
        if(comando == "salir"){ 
            return;
        }else if(comando.at(0) == 'h' && comando.find("help") != std::string::npos){

            if(comando.length() == 4) help();

            else{ comando.erase(0,5); helpCmd(comando);} //llama a la funcion que muestra, informacion mas detallada segun el comando que le es pasado

        }else if(comando.at(0) == 'i' && comando.find("inicializar") != std::string::npos){

            comando.erase(0,12);
            inicializar(comando);

        }else if(comando.at(0) == 'i' && comando.find("iniciar inverso") != std::string::npos){
            
            comando.erase(0,16);
            iniciarInv(comando);

        }else if(comando.at(0) == 'p' && comando.find("puntaje") != std::string::npos){

            comando.erase(0,8); 
            puntaje(comando);

        }else if(comando.at(0) == 'i' && comando.find("iniciar arbol inverso") != std::string::npos){

            comando.erase(0,22);
            iniciarArbolInv(comando);

        }else if(comando.at(0) == 'i' && comando.find("iniciar arbol") != std::string::npos){ 

            comando.erase(0,14);
            iniciarArbol(comando);

        }else if(comando.at(0) == 'p' && comando.find("palabras por prefijo") != std::string::npos){

            comando.erase(0,21);
            palabrasPorPrefijo(comando);

        }else if(comando.at(0) == 'p' && comando.find("palabras por sufijo") != std::string::npos){

            comando.erase(0,20);
            palabrasPorSufijo(comando);

        }else if(comando == "grafo de palabras"){
            grafoPalabras();
        }else if(comando.at(0) == 'p' && comando.find("posibles palabras") != std::string::npos){

            comando.erase(0,18);
            posiblesPalabras(comando);

        }else{
            std::cout<<"\n\n\aEl comando: "<<comando<<" no fue reconocido\n\n";
        }
        
        system("pause"); system("cls");

    }while(comando != "salir");
}

void helpCmd(const std::string& comando){

    if(comando == "salir") 
        std::cout<<"Comando \"salir\":\n"
        <<"\n\nDescripcion: Termina la ejecucion de la aplicacion.";
    else if(comando == "inicializar") 

        std::cout<<"Comando \"inicializar\":\n"
        <<"\n\nDescripcion: Inicializa el sistema a partir del archivo diccionario.txt,\n"
        <<"que contiene un diccionario de palabras aceptadas en el idioma ingles (idioma original del juego).\n"
        <<"El comando debe almacenar las palabras del archivo de forma que sea facil recuperarlas posteriormente.\n"
        <<"Las palabras deben ser verificadas para no almacenar aquellas que incluyen simbolos invalidos (como guiones, numeros y signos de puntuacion).";

    else if(comando == "iniciar inverso") 

        std::cout<<"Comando \"inciar inverso\":\n"
        <<"\n\nDescripcion: Inicializa el sistema a partir del archivo diccionario.txt,\n"
        <<"que contiene un diccionario de palabras aceptadas en el idioma ingles (idioma original del juego).\n"
        <<"A diferencia del comando inicializar, este comando almacena las palabras en sentido inverso (leidas de derecha a izquierda),\n"
        <<"teniendo en cuenta que sea facil recuperarlas posteriormente.\n"
        <<"Las palabras tambien deben ser verificadas para no almacenar aquellas que incluyen simbolos invalidos (como guiones, numeros y signos de puntuacion).";

    else if(comando == "puntaje") 

        std::cout<<"Comando \"puntaje\":\n"
        <<"\n\nDescripcion: El comando permite conocer la puntuacion que puede obtenerse con una palabra dada,\n"
        <<"de acuerdo a la tabla de puntuacion de cada letra presentada anteriormente.\n"
        <<"Sin embargo, el comando debe verificar que la palabra sea valida, es decir,\n"
        <<"que exista en el diccionario (tanto original como en sentido inverso), y que este escrita con simbolos validos.";

    else if(comando == "iniciar arbol") 

        std::cout<<"Comando \"inciar arbol\":\n"
        <<"\n\nDescripcion: Inicializa el sistema a partir del archivo diccionario.txt,\n"
        <<"que contiene un diccionario de palabras aceptadas en el idioma ingles (idioma original del juego).\n"
        <<"A diferencia del comando inicializar, este comando almacena las palabras en uno o mas arboles de letras (como se considere conveniente).\n"
        <<"Las palabras deben ser verificadas para no almacenar aquellas que incluyen simbolos invalidos (como guiones, numeros y signos de puntuacion).";

    else if(comando == "iniciar arbol inverso")

        std::cout<<"Comando \"iniciar arbol inverso\":\n"
        <<"\n\nDescripcion: Inicializa el sistema a partir del archivo diccionario.txt,\n"
        <<"que contiene un diccionario de palabras aceptadas en el idioma ingles (idioma original del juego).\n"
        <<"A diferencia de los comandos iniciar_inverso e iniciar_arbol,\n"
        <<"este comando almacena las palabras en uno o mas arboles de letras, pero en sentido inverso (leidas de derecha a izquierda).\n" 
        <<"Las palabras tambien deben ser verificadas para no almacenar aquellas que incluyen simbolos invalidos (como guiones, numeros y signos de puntuacion).";

    else if(comando == "palabras por prefijo")

        std::cout<<"Comando \"palabras por prefijo\":\n"
        <<"\n\nDescripcion: Dado un prefijo de pocas letras, el comando recorre\n"
        <<"el(los) arbol(es) de letras (construido(s) con el comando iniciar_arbol)\n"
        <<"para ubicar todas las palabras posibles a construir a partir de ese prefijo.\n"
        <<"A partir del recorrido, se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada una y la puntuacion que cada una puede obtener.";

    else if(comando == "palabras por sufijo")

        std::cout<<"Comando \"palabras por sufijo\":\n"
        <<"\n\nDescripcion: Dado un sufijo de pocas letras, el comando recorre el(los) arbol(es) de letras\n"
        <<"(construido(s) con el comando iniciar_arbol_inverso) para ubicar todas las palabras posibles a construir que terminan con ese sufijo.\n"
        <<"A partir del recorrido, se presenta al usuario en pantalla todas las posibles palabras, la longitud de cada una y la puntuacion que cada una puede obtener.";

    else if(comando == "grafo de palabras")

        std::cout<<"Comando \"grafo de palabras\":\n"
        <<"\n\nDescripcion: Con las palabras ya almacenadas en el diccionario (luego de ejecutar el comando inicializar),\n"
        <<"el comando construye un grafo de palabras, "
        <<"en donde cada palabra se conecta a las demas si y solo si difieren en un unica letra (con las demas letras iguales y en las mismas posiciones).";

    else if(comando == "posibles palabras")

        std::cout<<"Comando \"posibles palabras\":\n"
        <<"\n\nDescripcion: Dadas ciertas letras en una cadena de caracteres (sin importar su orden),\n"
        <<"el comando debe presentar en pantalla todas las posibles palabras validas a construir,\n"
        <<"indicando la longitud de cada una y la puntuacion que se puede obtener con cada una.\n"
        <<"En las letras de la cadena de caracteres, puede admitirse un unico simbolo comodin (?),\n"
        <<"el cual representara una letra desconocida y permitira generar mayores posibilidades de palabras a construir.\n"
        <<"Para este proposito, el comando debe hacer uso del grafo de palabras construido con el comando grafo_de_palabras.";

    else
        std::cout<<"\n\aEl comando al que trata de obtener informacion, no existe\n\n";
    
    
    std::cout<<"\n\n\n";
}

void help(){

    std::cout
    <<"\n\t- salir\n\n"
    <<"\t- inicializar\n\n"
    <<"\t- iniciar inverso\n\n"
    <<"\t- puntaje\n\n" 
    <<"\t- iniciar arbol\n\n"
    <<"\t- iniciar arbol inverso\n\n"
    <<"\t- palabras por prefijo\n\n"
    <<"\t- palabras por sufijo\n\n"
    <<"\t- grafo de palabras\n\n"
    <<"\t- posibles palabras\n\n"
    <<"\t- help\n\n"
    <<"\t- help COMANDO    ->    (COMANDO, en minusculas)\n\n\n\n";
}

void inicializar(const std::string& archivo){
    if(banderas & 1){ std::cout<<"\nYa se ha realizado la funcion \"inicializar\"\n\n"; return;}

    bool ban = 1;
    char c = 'E';
    std::string linea;
    std::ifstream diccionario(archivo);
    std::vector<std::vector<std::string>> palabras(26,std::vector<std::string>(0)); //matriz de palabras

    if(!diccionario){ std::cerr<<"\aNo se encontro el archivo: "<<archivo<<std::endl; ban = 0; return;}
    
    while(getline(diccionario,linea))
    
        switch(toupper(linea[0])){
            case 'A': palabras[0].push_back(linea);
                      break;
            case 'B': palabras[1].push_back(linea);
                      break;
            case 'C': palabras[2].push_back(linea);
                      break;
            case 'D': palabras[3].push_back(linea);
                      break;
            case 'E': palabras[4].push_back(linea);
                      break;
            case 'F': palabras[5].push_back(linea);
                      break;
            case 'G': palabras[6].push_back(linea);
                      break;
            case 'H': palabras[7].push_back(linea);
                      break;
            case 'I': palabras[8].push_back(linea);
                      break;
            case 'J': palabras[9].push_back(linea);
                      break;
            case 'K': palabras[10].push_back(linea);
                      break;
            case 'L': palabras[11].push_back(linea);
                      break;
            case 'M': palabras[12].push_back(linea);
                      break;
            case 'N': palabras[13].push_back(linea);
                      break;
            case 'O': palabras[14].push_back(linea);
                      break;
            case 'P': palabras[15].push_back(linea);
                      break;
            case 'Q': palabras[16].push_back(linea);
                      break;
            case 'R': palabras[17].push_back(linea);
                      break;
            case 'S': palabras[18].push_back(linea);
                      break;
            case 'T': palabras[19].push_back(linea);
                      break;
            case 'U': palabras[20].push_back(linea);
                      break;
            case 'V': palabras[21].push_back(linea);
                      break;
            case 'W': palabras[22].push_back(linea);
                      break;
            case 'X': palabras[23].push_back(linea);
                      break;
            case 'Y': palabras[24].push_back(linea);
                      break;
            case 'Z': palabras[25].push_back(linea);
                      break;
        }
    
    
    for(std::vector<std::string> i:palabras)
        for(std::string pal:i)
             std::cout<<pal<<std::endl;
        
    if(ban) banderas |= 1;

    diccionario.close();

    std::cout<<"\nResultado "<<(ban?"Exitoso":"Fallido")<<"\n\n";
}

void iniciarInv(const std::string& archivo){

    if(banderas & 2){ std::cout<<"\nYa se ha realizado la funcion \"iniciar inverso\"\n\n"; return;}

    char c = 'F';
    bool ban = 1;
    std::string linea;
    std::ifstream diccionario(archivo);
    std::vector<std::vector<std::string>> palabrasInv(26,std::vector<std::string>(0)); //matriz de palabras inversas

    if(diccionario.fail()){ std::cerr<<"\aNo se encontro el archivo: "<<archivo<<std::endl; ban = 0; return; }

    while(getline(diccionario,linea)){

        std::reverse(linea.begin(),linea.end());
        linea[linea.size()-1] = tolower(linea[linea.size()-1]); // cambia el ultimo caracter a minuscula

        switch(toupper(linea[0])){

            case 'A': palabrasInv[0].push_back(linea);
                      break;
            case 'B': palabrasInv[1].push_back(linea);
                      break;
            case 'C': palabrasInv[2].push_back(linea);
                      break;
            case 'D': palabrasInv[3].push_back(linea);
                      break;
            case 'E': palabrasInv[4].push_back(linea);
                      break;
            case 'F': palabrasInv[5].push_back(linea);
                      break;
            case 'G': palabrasInv[6].push_back(linea);
                      break;
            case 'H': palabrasInv[7].push_back(linea);
                      break;
            case 'I': palabrasInv[8].push_back(linea);
                      break;
            case 'J': palabrasInv[9].push_back(linea);
                      break;
            case 'K': palabrasInv[10].push_back(linea);
                      break;
            case 'L': palabrasInv[11].push_back(linea);
                      break;
            case 'M': palabrasInv[12].push_back(linea);
                      break;
            case 'N': palabrasInv[13].push_back(linea);
                      break;
            case 'O': palabrasInv[14].push_back(linea);
                      break;
            case 'P': palabrasInv[15].push_back(linea);
                      break;
            case 'Q': palabrasInv[16].push_back(linea);
                      break;
            case 'R': palabrasInv[17].push_back(linea);
                      break;
            case 'S': palabrasInv[18].push_back(linea);
                      break;
            case 'T': palabrasInv[19].push_back(linea);
                      break;
            case 'U': palabrasInv[20].push_back(linea);
                      break;
            case 'V': palabrasInv[21].push_back(linea);
                      break;
            case 'W': palabrasInv[22].push_back(linea);
                      break;
            case 'X': palabrasInv[23].push_back(linea);
                      break;
            case 'Y': palabrasInv[24].push_back(linea);
                      break;
            case 'Z': palabrasInv[25].push_back(linea);
                      break;
        }
    }
    std::cout<<"palabras que comienzan por "<<c<<"\n";
    for(std::string i:palabrasInv[c-'A'])
        std::cout<<i<<std::endl;

    
    
    if(ban) banderas |= 2;
    
    diccionario.close();

    std::cout<<"\nResultado "<<(ban?"Exitoso":"Fallido")<<"\n\n";
}

void puntaje(const std::string& palabra){
    unsigned int puntaje = 0;

    if(!esPalabraValida(palabra)){ std::cout<<"\nLa palabra contiene caracteres no validos\n\nResultado Fallido\n"; return;}

    for(int i=0; i<palabra.length(); i++)
        switch(toupper(palabra[i])){
            case 'E':
            case 'A':
            case 'I':
            case 'O':
            case 'N':
            case 'R':
            case 'T':
            case 'L':
            case 'S':
            case 'U': puntaje++; break;
            case 'D':
            case 'G': puntaje += 2; break;
            case 'B':
            case 'C':
            case 'M':
            case 'P': puntaje += 3; break;
            case 'F':
            case 'H':
            case 'V':
            case 'W': 
            case 'Y': puntaje += 4; break;
            case 'K': puntaje += 5; break;
            case 'J': 
            case 'X': puntaje += 8; break;
            case 'Q':
            case 'Z': puntaje += 10;
        }

    std::cout<<"\n\nLa palabra "<<palabra<<" tiene un puntaje de: "<<puntaje<<"\n\n";

    std::cout<<"\nResultado exitoso\n";
}

void iniciarArbol(const std::string& archivo){
    if(banderas & 4){ std::cout<<"\nYa se ha realizado la funcion \"iniciar arbol\"\n\n"; return;}

    bool ban = 1;
    std::string linea;
    std::ifstream diccionario(archivo);


    
    if(diccionario.fail()){ std::cerr<<"\aNo se encontro el archivo: "<<archivo<<std::endl; ban = 0; return; }

    if(ban){
    std::cout<<"\n\n\tEl arbol del diccionario se ha inicializado correctamente.\n\n";
        getline(diccionario,linea);
        std::cout<<linea<<std::endl;
        banderas |= 4;
    }
    diccionario.close();

    std::cout<<"\nResultado "<<(ban?"Exitoso":"Fallido")<<"\n\n";
}

void iniciarArbolInv(const std::string& archivo){
    if(banderas & 8){ std::cout<<"\nYa se ha realizado la funcion \"iniciar arbol inverso\"\n\n"; return;}

    bool ban = 1;
    std::string linea;
    std::ifstream diccionario(archivo);


    
    if(diccionario.fail()){ std::cerr<<"\aNo se encontro el archivo: "<<archivo<<std::endl; ban = 0; return; }

    if(ban){
    std::cout<<"\n\n\tEl arbol del diccionario inverso se ha inicializado correctamente.\n\n";
        getline(diccionario,linea);
        std::cout<<linea<<std::endl;
        banderas |= 8;
    }
    diccionario.close();

    std::cout<<"\nResultado "<<(ban?"Exitoso":"Fallido")<<"\n\n";
}

void palabrasPorPrefijo(const std::string& palabras){
    std::cout<<"\n\n\tpalabras por prefijo\n\n";

    std::cout<<"Argumento pasado: "<<palabras<<std::endl;

    std::cout<<"\nLas palabras que inician con este prefijo son:\n";
}

void palabrasPorSufijo(const std::string& palabras){
    std::cout<<"\n\n\tpalabras por sufijo\n\n";

    std::cout<<"Argumento pasado: "<<palabras<<std::endl;

    std::cout<<"\nLas palabras que terminan con este sufijo son:\n";
}

void grafoPalabras(){
    std::cout<<"\n\n\tGrafo construido correctamente.\n\n";

    std::cout<<"\nResultado exitoso\n";
}

void posiblesPalabras(const std::string& letras){

    if(!esPalabraValida(letras)){ std::cout<<"\nLa palabra contiene caracteres no validos\n\nResultado Fallido\n"; return;}

    std::cout<<"\n\n\tLas posibles palabras a construir con las letras letras son:\n\n";

    std::cout<<"Argumento pasado: "<<letras<<std::endl;

    std::cout<<"\nResultado exitoso\n";
}

bool esPalabraValida(const std::string& palabra){

    for(int i=0; i<palabra.size(); i++)
        if(!(palabra[i] >= 'A' && palabra[i] <= 'Z' || palabra[i] >= 'a' && palabra[i] <= 'z' || palabra[i] == ' ')) return false;  
    return true;
}