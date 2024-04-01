// Parcial 2 Estructuras de Datos y Algoritmos 2:
// Problema de Online Judge 11054 - Wine trading in Gergovia.
// Todos los habitantes son vendedores de vino y le compran vino a otros y cada dia deciden cuanto vino quiere comprar o vender.
// La demanda y oferta son siempre iguales por lo que cada habitante obtiene lo que desea.
// Hay un problema: el transporte de una casa a otra resulta en trabajo.
// A los habitantes no les importa a quien le compran o venden, solo les importa la cantidad de vino que se compra o vende.
// Son lo suficientemente inteligentes como para idear una forma de intercambiar para que el trabajo necesario del transporte sea minimo.
// Se pide:
// Reconstruir el intercambio de un dia; asumiendo que las casas estan construidas en una sola linea recta con la misma distancia entre casas vecinas.
// Adicionalmente, el transporte de una botella de vino de una casa a otra adyacente cuesta 1 de trabajo.
// La entrada esta compuesta por varios casos de prueba.
// Cada caso se compone de:
// Una primera linea que contiene el numero de habitantes n (2 <= n <= 100000).
// Una segunda linea que contiene n enteros a_i (-1000 <= a_i <= 1000) que representan la cantidad de vino que cada habitante desea comprar o vender. Si a_i es positivo, el habitante i desea comprar a_i botellas de vino. Si a_i es negativo, el habitante i desea vender -a_i botellas de vino.
// Se puede asumir que la suma de todos los a_i es 0.
// La entrada termina cuando n = 0.
// La salida esta copuesta por:
// Una linea para cada caso de prueba que contiene el minimo trabajo necesario para que todos los habitantes obtengan lo que desean.


// Ejemplo:
// Entrada:
// 5
// 5 -4 1 -3 2
// 0
// Salida:
// 9


// Ejemplo:
// 10
// 100 200 300 400 500 600 700 800 900 -4500
// 16500
// Tenemos al vendedor y digamos que le vende 4500 al que quiere comprar 900, entonces el trabajo aca fue de 4500 y nos quedan disponibles 4500 - 900 = 3600 vinos.
// Ahora el vendedor le vende 3600 al que quiere comprar 800, entonces el trabajo aca fue de 3600 y nos quedan disponibles 3600 - 800 = 2800 vinos.
// Ahora el vendedor le vende 2800 al que quiere comprar 700, entonces el trabajo aca fue de 2800 y nos quedan disponibles 2800 - 700 = 2100 vinos.
// Ahora el vendedor le vende 2100 al que quiere comprar 600, entonces el trabajo aca fue de 2100 y nos quedan disponibles 2100 - 600 = 1500 vinos.
// Ahora el vendedor le vende 1500 al que quiere comprar 500, entonces el trabajo aca fue de 1500 y nos quedan disponibles 1500 - 500 = 1000 vinos.
// Ahora el vendedor le vende 1000 al que quiere comprar 400, entonces el trabajo aca fue de 1000 y nos quedan disponibles 1000 - 400 = 600 vinos.
// Ahora el vendedor le vende 600 al que quiere comprar 300, entonces el trabajo aca fue de 600 y nos quedan disponibles 600 - 300 = 300 vinos.
// Ahora el vendedor le vende 300 al que quiere comprar 200, entonces el trabajo aca fue de 300 y nos quedan disponibles 300 - 200 = 100 vinos.
// Ahora el vendedor le vende 100 al que quiere comprar 100, entonces el trabajo aca fue de 100 y nos quedan disponibles 100 - 100 = 0 vinos.
// El trabajo total seria 4500 + 3600 + 2800 + 2100 + 1500 + 1000 + 600 + 300 + 100 = 16500.


// Algoritmo:
// 1. Leer el numero de habitantes.
// 2. Leer la lista de habitantes.
// 3. Inicializar el trabajo total en 0.
// 4. Inicializar el total de vinos en 0.
// 5. Iterar sobre la lista de habitantes.
// 6. Calcular el total de vinos.
// 7. Calcular el trabajo total.
// 8. Imprimir el trabajo total.



#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int leer_habitantes (){
    int num_habitantes;
    cin >> num_habitantes;
    return num_habitantes;
}

vector<int> crear_lista_habitantes (int num_habitantes) {
    vector<int> habitantes;
    habitantes.resize(num_habitantes);
    for (int i = 0; i < num_habitantes; i++) {
        cin >> habitantes[i];
    }
    return habitantes;
}

long long calcular_trabajo_total (vector<int> habitantes) {
    long long trabajo_total = 0;
    long long total_vinos = 0;
    for (int i = 0; i < habitantes.size(); i++) {
        total_vinos += habitantes[i];
        trabajo_total += abs(total_vinos);
    }
    return trabajo_total;
}

int main() {
    int num_habitantes = leer_habitantes();
    while (num_habitantes != 0) {
        vector<int> habitantes = crear_lista_habitantes(num_habitantes);
        long long trabajo_total = calcular_trabajo_total(habitantes);
        cout << trabajo_total << endl;
        num_habitantes = leer_habitantes();
    }


return 0;
}



