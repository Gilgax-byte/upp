#include <iostream>
#include <vector>

using namespace std;

void imprimirMatriz(const vector<vector<double> >& matriz);
vector<vector<double> > sumarMatrices(const vector<vector<double> >& matriz1, const vector<vector<double> >& matriz2);
vector<vector<double> > restarMatrices(const vector<vector<double> >& matriz1, const vector<vector<double> >& matriz2);
vector<vector<double> > multiplicarMatrices(const vector<vector<double> >& matriz1, const vector<vector<double> >& matriz2);
vector<vector<double> > inversaMatriz(vector<vector<double> >& matriz);

int main() {
    int filas, columnas;
    
    cout << "Ingrese el número de filas de las matrices: ";
    cin >> filas;
    cout << "Ingrese el número de columnas de las matrices: ";
    cin >> columnas;
    
    vector<vector<double> > matriz1(filas, vector<double>(columnas));
    vector<vector<double> > matriz2(filas, vector<double>(columnas));
    
    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> matriz1[i][j];
        }
    }
    
    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> matriz2[i][j];
        }
    }
    
    cout << "Suma de matrices:" << endl;
    imprimirMatriz(sumarMatrices(matriz1, matriz2));
    
    cout << "Resta de matrices:" << endl;
    imprimirMatriz(restarMatrices(matriz1, matriz2));
    
    cout << "Multiplicación de matrices:" << endl;
    if (columnas == filas) {
        imprimirMatriz(multiplicarMatrices(matriz1, matriz2));
    } else {
        cout << "No se pueden multiplicar las matrices: las dimensiones no son compatibles." << endl;
    }
    
    if (filas == columnas) {
        cout << "Inversa de la primera matriz:" << endl;
        imprimirMatriz(inversaMatriz(matriz1));
        
        cout << "Inversa de la segunda matriz:" << endl;
        imprimirMatriz(inversaMatriz(matriz2));
    } else {
        cout << "No se puede calcular la inversa: las matrices no son cuadradas." << endl;
    }
    
    return 0;
}

void imprimirMatriz(const vector<vector<double> >& matriz) {
    for (size_t i = 0; i < matriz.size(); ++i) {
        for (size_t j = 0; j < matriz[i].size(); ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<double> > sumarMatrices(const vector<vector<double> >& matriz1, const vector<vector<double> >& matriz2) {
    int filas = matriz1.size();
    int columnas = matriz1[0].size();
    vector<vector<double> > resultado(filas, vector<double>(columnas));
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    
    return resultado;
}

vector<vector<double> > restarMatrices(const vector<vector<double> >& matriz1, const vector<vector<double> >& matriz2) {
    int filas = matriz1.size();
    int columnas = matriz1[0].size();
    vector<vector<double> > resultado(filas, vector<double>(columnas));
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
    
    return resultado;
}

vector<vector<double> > multiplicarMatrices(const vector<vector<double> >& matriz1, const vector<vector<double> >& matriz2) {
    int filas = matriz1.size();
    int columnas = matriz2[0].size();
    int n = matriz1[0].size();
    vector<vector<double> > resultado(filas, vector<double>(columnas));
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    
    return resultado;
}

vector<vector<double> > inversaMatriz(vector<vector<double> >& matriz) {
    int n = matriz.size();
    vector<vector<double> > identidad(n, vector<double>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        identidad[i][i] = 1;
    }
    
    for (int i = 0; i < n; ++i) {
        double pivote = matriz[i][i];
        for (int j = 0; j < n; ++j) {
            matriz[i][j] /= pivote;
            identidad[i][j] /= pivote;
        }
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = matriz[k][i];
                for (int j = 0; j < n; ++j) {
                    matriz[k][j] -= factor * matriz[i][j];
                    identidad[k][j] -= factor * identidad[i][j];
                }
            }
        }
    }
    
    return identidad;
}


