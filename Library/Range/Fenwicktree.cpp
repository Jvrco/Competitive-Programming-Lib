#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão do C++
using namespace std;

#define endl '\n'               // Para melhorar a performance ao imprimir linhas
#define MOD 1000000007          // Constante de módulo (não usada aqui)
typedef long long ll;          // Atalho para long long

const int MAXV = 200000;       // Tamanho máximo dos vetores
const ll INF = LLONG_MAX;      // Valor infinito para long long (não usado neste código)

// Árvore de Fenwick para realizar consultas e atualizações de somas prefixadas de forma eficiente
ll tree[MAXV + 1];

// Vetor para armazenar os valores originais
int arr[MAXV + 1];

// Variáveis globais
int n, q;

// Função para atualizar o valor de um índice no Fenwick Tree
void update(int idx, ll val) {
    // A ideia é propagar a diferença `val` para todos os índices responsáveis por `idx`
    while (idx <= n) {
        tree[idx] += val;           // Soma o valor atual ao índice
        idx += idx & -idx;          // Avança para o próximo índice responsável (bit menos significativo)
    }
}

// Função para calcular a soma prefixada até o índice `idx`
ll prefixs(int idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += tree[idx];           // Soma os valores acumulados até o índice
        idx -= idx & -idx;          // Move para o índice anterior na árvore (removendo o bit menos significativo)
    }
    return sum;
}

// Soma dos elementos no intervalo [a, b]
ll rangesum(int a, int b) {
    return prefixs(b) - prefixs(a - 1); // Usa soma prefixada: soma(b) - soma(a-1)
}

int main() {
    ios::sync_with_stdio(false);    // Otimiza as operações de entrada/saída
    cin.tie(NULL);                  // Desvincula cin de cout para agilizar

    cin >> n >> q;                  // Lê o número de elementos e número de queries

    // Lê os elementos do array original e atualiza o Fenwick Tree
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];              // Lê o valor original
        update(i, arr[i]);          // Atualiza a árvore com esse valor
    }

    // Processa as queries
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) {
            // Tipo 1: atualizar valor da posição `a` para `b`
            update(a, b - arr[a]);  // Calcula a diferença e propaga para o BIT
            arr[a] = b;             // Atualiza o valor no array original
        } else if (t == 2) {
            // Tipo 2: calcular soma do intervalo [a, b]
            cout << rangesum(a, b) << endl;
        }
    }

    return 0;
}
