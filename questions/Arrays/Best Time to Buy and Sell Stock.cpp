class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int anterior = -1;
       int atual = 0;
       int conta = 0;
       
        // array que percorre vetor de preços
        for(int data: prices){
           
            atual = data;
            // 1 - Verifico se estou na primeira verificação, caso contrário verifico também se o valor atual - anterior é maior que o valor que tenho guardado até o momento
            if(anterior!=-1 && (atual - anterior)>conta)
                conta = atual - anterior;
            // caso seja a primeira verificação, o anterior passa a ser o valor atual, caso contrário verifico se ele é maior que o valor atual do vetor
            if(anterior==-1)
                anterior = data;
            else if(anterior>data)
                anterior = data;  
            
       }
        return conta;
        
        
    }
};