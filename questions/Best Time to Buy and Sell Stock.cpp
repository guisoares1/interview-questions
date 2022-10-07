class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int anterior = -1;
       int atual = 0;
       int conta = 0;
       
        for(int data: prices){
           
            atual = data;
            if(anterior!=-1 && (atual - anterior)>conta)
                conta = atual - anterior;
            
            if(anterior==-1)
                anterior = data;
            else if(anterior>data)
                anterior = data;  
            
       }
        return conta;
        
        
    }
};