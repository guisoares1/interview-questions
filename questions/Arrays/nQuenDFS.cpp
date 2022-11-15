#include <iostream>

using namespace std;

#include <iostream>
#include <vector>
using namespace std;



vector<string> result;

void preencheTabuleiro(vector<string> &tabuleiro, int n){
    string linha = "";
    for(int i=0; i<n; i++) linha += '.';
    for(int i=0; i<n; i++) tabuleiro.push_back(linha);
}

bool rainhaNaoPodeSerAtacadaNessaPosicao(int row, int col, int n, vector<string>& tabuleiro){
    //Check up
    for(int i=0; i<row; i++){
        if(tabuleiro[i][col] == 'Q') return false;
    }
    
    //Check left diag
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
        if(tabuleiro[i][j] == 'Q') return false;
    }
    
    //Check right diag
    for(int i=row-1, j=col+1; i>=0 && j<n; i--,j++){
        if(tabuleiro[i][j] == 'Q') return false;
    }
    return true;
}

void dfsQueens(int row, int n, vector<string>& tabuleiro){
    if(row == n){
        result = tabuleiro ;
        return;
    }
    
    for(int cont=0; cont<n; cont++){
        if(rainhaNaoPodeSerAtacadaNessaPosicao(row, cont, n, tabuleiro)){
            
            //Place Queen at this position
            tabuleiro[row][cont] = 'Q';
            dfsQueens(row+1, n, tabuleiro);
            
        }
    }
    return;
}


void nQueenBuscaProfundidadeIterativa(int n) {

    vector<string> tabuleiro;
    preencheTabuleiro(tabuleiro, n);

    dfsQueens(0, n, tabuleiro);
}



int main(){
    int n =0;
    cin>>n;
    nQueenBuscaProfundidadeIterativa(n);
    for(int cont = 0; cont<n;cont++){
        cout<<result[cont];
        cout<<"\n";
    }
}