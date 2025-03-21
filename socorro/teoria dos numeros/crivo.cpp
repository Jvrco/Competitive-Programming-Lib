#include <iostream>
#include <vector>

// Função que retorna um vetor de booleanos indicando quem é primo
// (true para primo, false para não primo).
std::vector<bool> crivoEratostenes(int n) {
    std::vector<bool> ehPrimo(n + 1, true); // Inicialmente, marca tudo como true
    ehPrimo[0] = false; // 0 não é primo
    ehPrimo[1] = false; // 1 não é primo

    for (int i = 2; i * i <= n; i++) {
        if (ehPrimo[i]) {
            // Marca múltiplos de i (começando de i*i) como não primos
            for (int j = i * i; j <= n; j += i) {
                ehPrimo[j] = false;
            }
        }
    }

    return ehPrimo;
}

int main() {
    int n;
    std::cout << "Digite o valor de n: ";
    std::cin >> n;

    std::vector<bool> resultado = crivoEratostenes(n);

    std::cout << "Numeros primos entre 1 e " << n << ":\n";
    for (int i = 2; i <= n; i++) {
        if (resultado[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
