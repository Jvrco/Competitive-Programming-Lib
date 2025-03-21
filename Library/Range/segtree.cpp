#include <bits/stdc++.h>
using namespace std;

#define endl '\n'             // Otimiza a quebra de linha para mais velocidade
#define MOD 1000000007        // Constante para módulo (não usada aqui)
typedef long long ll;

const int MAXV = 200000;
const ll INF = LLONG_MAX;

// Vetores globais usados em outros contextos (não usados aqui)
bool visited[MAXV];   
vector<pair<int, ll>> adj[MAXV];

// Variáveis globais
int n, q;
vector<int> arr, seg;  // `arr` é o array original, `seg` é a segment tree

// Função para construir a segment tree
void build(int node, int start, int end) {
    if (start == end) {
        // Caso base: folha da árvore representa o valor do array original
        seg[node] = arr[start]; 
    } else {
        // Caso recursivo: divide o intervalo ao meio
        int mid = (start + end) / 2;
        // Constrói recursivamente as subárvores esquerda e direita
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        // O nó atual guarda o valor mínimo entre os filhos
        seg[node] = min(seg[2 * node], seg[2 * node + 1]);
    }
}

// Função para atualizar um valor no array e na segment tree
void update(int node, int start, int end, int idx, int v) {
    if (start == end) {
        // Atualiza o valor diretamente na folha
        arr[idx] = v;
        seg[node] = v;
    } else {
        int mid = (start + end) / 2;
        // Recorre à subárvore esquerda ou direita, dependendo da posição `idx`
        if (idx <= mid)
            update(2 * node, start, mid, idx, v);
        else
            update(2 * node + 1, mid + 1, end, idx, v);
        // Após a atualização, recalcula o valor mínimo do nó atual
        seg[node] = min(seg[2 * node], seg[2 * node + 1]);
    }
}

// Função para consultar o valor mínimo no intervalo [l, r]
int rangem(int node, int start, int end, int l, int r) {
    // Se o intervalo atual [start, end] está completamente fora de [l, r]
    if (r < start || l > end) return INT_MAX;

    // Se o intervalo atual está completamente dentro de [l, r]
    if (l <= start && end <= r) return seg[node];

    // Se há sobreposição parcial, divide em dois
    int mid = (start + end) / 2;
    int lm = rangem(2 * node, start, mid, l, r);       // Mínimo na esquerda
    int rm = rangem(2 * node + 1, mid + 1, end, l, r); // Mínimo na direita
    
    return min(lm, rm); // Retorna o menor dos dois
}

int main() {
    ios::sync_with_stdio(false); // Otimiza I/O
    cin.tie(NULL);               // Evita flush automático do cout

    cin >> n >> q;              // Lê o tamanho do array e o número de queries
    arr.resize(n + 1);          // Aloca o array original (indexado de 1 a n)
    seg.resize(4 * n);          // Aloca a segment tree com tamanho suficiente (4*n)

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];          // Lê os elementos do array original
    }

    build(1, 1, n);             // Constrói a segment tree a partir do array

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) {
            // Tipo 1: Atualiza o valor da posição `a` para `b`
            update(1, 1, n, a, b);
        } else if (t == 2) {
            // Tipo 2: Consulta o valor mínimo no intervalo [a, b]
            cout << rangem(1, 1, n, a, b) << endl;
        }
    }

    return 0;
}
