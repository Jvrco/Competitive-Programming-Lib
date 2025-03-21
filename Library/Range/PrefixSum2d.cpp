#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

// Vetores bidimensionais para armazenar os valores e a matriz de prefixos
// 'val' guarda os valores originais da matriz (0 ou 1, dependendo se a célula contém '*' ou não)
// 'pref' armazenará a soma cumulativa (prefix sum) para permitir consultas eficientes
vector<vector<int>> val;
vector<vector<int>> pref;

// Função query que retorna a soma dos valores na submatriz definida pelos cantos (x1, y1) e (x2, y2)
// Utiliza a técnica de matriz de prefixos para calcular a soma de forma rápida
int query(int x1, int y1, int x2, int y2) {
    // total: soma de todos os valores da submatriz de (1,1) até (x2,y2)
    int total = pref[x2][y2];
    // removeline: soma da área acima da linha x1, ou seja, de (1,1) até (x2, y1-1)
    int removeline = pref[x2][y1 - 1];
    // removecolumn: soma da área à esquerda da coluna y1, ou seja, de (1,1) até (x1-1, y2)
    int removecolumn = pref[x1 - 1][y2];
    // addexcedent: essa área foi removida duas vezes, por isso é adicionada de volta: de (1,1) até (x1-1, y1-1)
    int addexcedent = pref[x1 - 1][y1 - 1];
    // A soma final é obtida subtraindo as áreas que não fazem parte da consulta e adicionando a interseção
    return total - removeline - removecolumn + addexcedent;
}

// Função principal de solução que processa a entrada, constrói a matriz de prefixos e responde as queries
void solve(){
    int n, q;
    cin >> n >> q;

    // Redimensiona as matrizes 'val' e 'pref'
    // Usamos n+1 para que a indexação comece do 1 e facilite o cálculo dos prefixos
    val.resize(n + 1, vector<int>(n + 1, 0));
    pref.resize(n + 1, vector<int>(n + 1, 0));

    // Leitura da matriz de entrada
    // Para cada célula, se o caractere for '*' atribui 1 a 'val' (indicando presença do sinal)
    // Caso contrário, permanece 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == '*')
                val[i][j] = 1;
        }
    }

    // Construção da matriz de prefixos 'pref'
    // Cada posição [i][j] contém a soma de todos os elementos da submatriz que vai de (1,1) até (i,j)
    // A fórmula: pref[i][j] = val[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]
    // Essa fórmula evita contagem dupla, subtraindo a área que foi somada duas vezes
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = val[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    // Processamento das q queries
    // Cada query solicita a soma dos valores (quantidade de '*') na submatriz delimitada pelos pontos (x1, y1) e (x2, y2)
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // Chama a função query para obter a soma na submatriz e imprime o resultado
        cout << query(x1, y1, x2, y2) << endl;
    }    
}
