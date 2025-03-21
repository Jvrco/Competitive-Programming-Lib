#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

// Estrutura de um nó da Trie
struct Node {
    map<int, int> next; // Mapeia cada caractere (c - 'a') para o próximo nó
    int sub_cnt = 0;     // Quantidade de strings que passam por esse nó (útil para contagem de prefixos)
};

// Estrutura da Trie
struct Trie {
    vector<Node> tr; // Vetor que representa todos os nós da Trie

    // Construtor: inicia a Trie com um nó raiz
    Trie() : tr(1) {}

    // Adiciona uma string `s` à Trie
    void add(string s) {
        int cur = 0; // Começa na raiz (índice 0)
        for (char c : s) {
            // Se não há transição com o caractere atual, cria novo nó
            if (tr[cur].next[c - 'a'] == 0) {
                int sz = tr.size();           // Índice do novo nó
                tr[cur].next[c - 'a'] = sz;   // Conecta o nó atual ao novo
                tr.emplace_back();            // Adiciona novo nó ao vetor
            }
            tr[cur].sub_cnt += 1;             // Incrementa contador de prefixos passando por esse nó
            cur = tr[cur].next[c - 'a'];      // Move para o próximo nó
        }
        tr[cur].sub_cnt += 1; // Também conta o final da palavra
    }

    // Consulta quantas strings começam com o prefixo `s`
    int query(string s) {
        int cur = 0; // Começa na raiz
        for (char c : s) {
            if (tr[cur].next[c - 'a'] == 0) return 0; // Se o caminho não existe, não há prefixos
            cur = tr[cur].next[c - 'a'];              // Vai para o próximo caractere
        }
        return tr[cur].sub_cnt; // Retorna o contador de prefixos naquele ponto
    }
};

// Função principal
void solve() {
    Trie trie; // Cria uma instância da Trie
    int n, q;
    cin >> n >> q;

    // Lê `n` strings e adiciona na Trie
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        trie.add(s);
    }

    // Lê `q` consultas de prefixos e imprime quantas vezes ocorrem
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        cout << trie.query(s) << endl;
    }
}

// Ponto de entrada do programa
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
