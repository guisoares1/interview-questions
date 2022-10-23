string isBalanced(string s) {
    stack<char> pilha;
    for(char caractere: s){
        if(caractere == '{' || caractere == '[' || caractere == '(')
            pilha.push(caractere);
        else 
        {
            if(caractere == '}' && pilha.top()=='{')
                pilha.pop();
            else if(caractere == ')' && pilha.top()=='(')
               pilha.pop();
            else if(caractere == ']' && pilha.top()=='[')
               pilha.pop();
            else 
                break;
        }
    }
    if (pilha.empty())
        return "YES";
    else        
        return "NO";
}