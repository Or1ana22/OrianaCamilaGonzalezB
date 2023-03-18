#include <iostream>
#include <cmath>

using namespace std;

//Una función que permita imprimir los números del arreglo con un ciclo for
void imprimir_con_for(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "- ";
    }
    cout << endl << endl;
}
//Una función que permita imprimir los números del arreglo con un while
void imprimir_con_while(int arreglo[], int n) {
    int i = 0;
    while (i < n) {
        cout << arreglo[i] << " ";
        i++;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "- ";
    }
    cout << endl;
}

//Una función que cargue el Número contenido en la posición media (mitad del del arreglo)
int cargar_posicion_media(int arreglo[], int n) {
    int pos_media = n/2;
    return arreglo[pos_media];
}
//Una función que imprima los números pares contenidos en el arreglo
void imprimir_pares(int arreglo[], int n) {
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (arreglo[i] % 2 == 0) {
            encontrado = true;
            cout << arreglo[i] << " ";
        }
    }
    if (!encontrado) {
        cout << endl << "No hay numeros pares en el arreglo.";
    }
    cout << endl;
}

bool es_primo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
//Una función que imprima los números primos contenidos en el arreglo
void imprimir_primos(int arreglo[], int n) {
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (es_primo(arreglo[i])) {
            encontrado = true;
            cout << arreglo[i] << " ";
        }
    }
    if (!encontrado) {
        cout << endl << "No hay numeros primos en el arreglo.";
    }
    cout << endl;
}
//Una función que devuelva el número mayor contenido en el arreglo.
int encontrar_mayor(int arreglo[], int n) {
    int maximo = arreglo[0];
    for (int i = 1; i < n; i++) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }
    return maximo;
}
//Una función que ordene el arreglo de menor a mayor
void ordenar_arreglo(int arreglo[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arreglo[i] > arreglo[j]) {
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
}
int main() {
    int n, opcion;
    cout << "Ingrese el tamaño de su arreglo: ";
    cin >> n;

    int arreglo[n];

    cout << endl << "Seleccione una opcion para llenar su arreglo: \n" << endl;
    cout << "1. Automático (números entre 100 y 200)" << endl;
    cout << "2. Manual (números entre 0 y 99)" << endl;
    cin >> opcion;

    if (opcion == 1) {
        for (int i = 0; i < n; i++) {
            arreglo[i] = rand() % 101 + 100;
        }
    } else if (opcion == 2) {
        for (int i = 0; i < n; i++) {
            cout << "Ingrese el número en la posición: " << i << ": ";
            cin >> arreglo[i];
        }
    } else {
        cout << "Opcion invalida." << endl;
        return 0;
    }
    cout << endl << "Arreglo generado por el for: \n";
    imprimir_con_for(arreglo, n);

    cout << "Arreglo generado por el while: \n";
    imprimir_con_while(arreglo, n);

    cout << endl << "El número de la mitad del arreglo es: \n" << cargar_posicion_media(arreglo, n) << endl;

    bool hay_pares = false;
    for (int i = 0; i < n; i++) {
        if (arreglo[i] % 2 == 0) {
            hay_pares = true;
            break;
        }
    }
    if (hay_pares) {
        cout << endl << "Los numeros pares en el arreglo son: \n";
        imprimir_pares(arreglo, n);
    } else {
        cout << endl << "No hay numeros pares en el arreglo." << endl;
    }

    bool hay_primos = false;
    for (int i = 0; i < n; i++) {
        if (es_primo(arreglo[i])) {
            hay_primos = true;
            break;
        }
    }
    if (hay_primos) {
        cout << endl << "Los numeros primos en el arreglo son: ";
        imprimir_primos(arreglo, n);
    } else {
        cout << endl << "No hay numeros primos en el arreglo." << endl;
    }

    cout << endl << "El número mayor en el arreglo es: \n" << encontrar_mayor(arreglo, n) << endl;

    ordenar_arreglo(arreglo, n);
    cout << endl << "Arreglo ordenado de menor a mayor: \n";
    imprimir_con_for(arreglo, n);

    return 0;
}
