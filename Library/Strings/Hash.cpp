#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

// Constantes
ll INF = 1e18;
ll M = 999999900409;     // Um número primo grande usado como módulo
ll K = 1000213;          // Base do hash, também primo

// Multiplicação modular segura usando __int128 para evitar overflow
ll mod_mul(ll a, ll b, ll mod) {
    __int128 t = a;
    t = t * b;
    t %= mod;
    return (ll)t;
}

void solve() {
    string s, p;
    cin >> s >> p;

    int n = s.size();
    int m = p.size();

    // Vetores para prefix hash e potências de K
    ll pref[n];
    ll powers[n + 1];

    // Inicializa o hash do primeiro caractere
    pref[0] = s[0] - 'a';
    powers[0] = 1;

    // Calcula os hashes prefixados da string s
    for (int i = 1; i < n; i++) {
        pref[i] = (pref[i - 1] * K + (s[i] - 'a')) % M;
    }

    // Pré-calcula as potências de K até o tamanho máximo
    for (int i = 1; i <= n; i++) {
        powers[i] = (powers[i - 1] * K) % M;
    }

    // Calcula o hash da string padrão p
    ll pHash = p[0] - 'a';
    for (int i = 1; i < m; i++) {
        pHash = (pHash * K + (p[i] - 'a')) % M;
    }

    // Conta quantas vezes o padrão aparece na string
    ll ans = 0;
    for (int i = 0; i + m - 1 < n; i++) {
        int l = i;
        int r = i + m - 1;

        ll subHash;
        if (i == 0) {
            subHash = pref[r];  // Hash direto se começa em 0
        } else {
            // Calcula o hash da substring s[l..r] usando diferença de prefixos
            subHash = pref[r] - mod_mul(pref[l - 1], powers[r - l + 1], M);
        }

        // Garante que o valor fique positivo no módulo
        subHash = (subHash % M + M) % M;

        if (subHash == pHash) {
            ans++;  // Hash bate → provavelmente a substring é igual
        }
    }

    cout << ans << endl;
}
