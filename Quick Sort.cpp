#include <iostream>
#include <locale.h>

using namespace std;

void intercambiar(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int particionar(int a[], int bajo, int alto) {
    int pivote = a[alto];
    int i = (bajo - 1);

    for (int j = bajo; j < alto; j++) {
        if (a[j] <= pivote) {
            i++;
            intercambiar(a[i], a[j]);
        }
    }
    intercambiar(a[i + 1], a[alto]);
    return (i + 1);
}

void ordenamientoRapido(int a[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particionar(a, bajo, alto);
        ordenamientoRapido(a, bajo, pi - 1);
        ordenamientoRapido(a, pi + 1, alto);
    }
}

int main() {
    setlocale(LC_ALL,"");
    int n;

    cout << "¿Cuántos datos deseas ingresar? ";
    cin >> n;

    int a[n];

    cout << "Ingresa " << n << " números:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Número " << (i + 1) << ": ";
        cin >> a[i];
    }

    ordenamientoRapido(a, 0, n - 1);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

