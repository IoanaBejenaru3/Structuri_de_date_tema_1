//AM PRELUAT CODUL PT LISTELE INLANTUITE DE LA liste_simplu_inlantuite.cpp
#include <iostream>
//Sa se verifice daca un set de paranteze citit de la tastatura este corect inchise.
//corect: {[()()][()]}
//gresit: {(})[{}]
struct Nod{
    Nod* next;
    int info;
};

Nod* L;

void Adauga(int nr){
    if(L == NULL) //daca lista nu are niciun element
    {
        L  = new Nod;
        L -> info = nr;
        L -> next = NULL;
    }
    else //in cazul in care deja exista elemente
    {
        Nod* nod = new Nod;
        nod -> info = nr;
        nod -> next = L;
        L = nod;
    }
}

void Creare()
{
    L = NULL; //lista este definita trebuie sa o intializam cu NULL pentru a si ca este vida
    int n, val;
    std::cin >> n; //citim numarul de elemente pe care vrem sa le avem in lista initial
    for(int i = 0; i < n; i++) //citim elementele pe care le vrem in lista
        {
            std::cin >> val;
            Adauga(val);
        }
}

int CautareVal(int val){ //functie care cauta prima aparitie a valorii val si returneaza pozitia ei
    Nod* x = new Nod; //pointer de tip Nod cu care vom parcurge lista L pentru a nu pierde informatiile din aceasta
    x = L;
    int ct = 1; //variabila cu care contorizam pozitia la care ne aflam la un moment dat in lista
    while(x != 0) //cat tip mai avem elemente in lista
    {
        if(x -> info == val) //daca acumva gasim acea valoare returnam pozitia ei
            return ct;
        ct++;
        x = x -> next;
    }
    return -1; //daca nu am gasit valoarea returnam -1 care semnifica ca nu a fost gasita
}

void Inserare(int poz, int val){
    Nod* x = new Nod; //pointer de tip Nod cu care vom parcurge lista L pentru a nu pierde informatiile din aceasta
    x = L;
    int ct = 1;
    if(poz == 1) //daca cumva trebuie sa inseram la pozitia 1 in lista, pur si simplu mai adaugam un nod care va deveni capul listei
    {
        Adauga(val);
        return;
    }
    while(x != 0 && ct != poz-1) //cautam nodul de pe pozitia poz-1 pentru a putea ulterior sa inseram la pozitia poz ajutandu-ma de x -> next
    {
        x = x -> next;
        ct++;
    }
    if(x != 0) //daca pozitia primita ca parametru este viabila, adica daca exista in lista sau vrem sa mai inseram un nod la final
    {
        Nod* nod = new Nod; //atunci facem legaturile
        nod -> info = val;
        nod -> next = x -> next;
        x -> next = nod;
    }
    return;
}

void Stergere(int poz){ 
    Nod* x = new Nod; //pointer de tip Nod cu care vom parcurge lista L pentru a nu pierde informatiile din aceasta
    x = L;
    int ct = 1;
    if(poz == 1) //daca trebuie sa stergem capul listei
    {
        x = L ->next; //tinem minte restul listei in x
        delete L; //stergem capul listei
        L = x; //lista devine restul listei fara head (primul elemet)
        return;
    }
    while(ct != poz-1 && x != 0)
    {
        ct++;
        x = x -> next;
    }
    if(x != 0) //daca avem acea pozitie in lista
    {
        //inseamna ca in x->next avem nodul pe care vrem sa il stergem
        //asa ca facem legaturile
        Nod* nou = x -> next;
        x -> next = x -> next -> next; //merge si pt ultimul nod
        delete nou;
    }
}

void Afisare(){
    Nod* x = new Nod;
    x = L;
    while(x != 0)
    {
        std::cout << x -> info << ' ';
        x = x -> next;
    }
    std::cout << std::endl;
}


int main()
{
    L = NULL; //nu avem nicio paranteza momentan
    int n; //numarul de paranteze pe care vrem sa le citim
    char c;
    std::cin >> n;
    for(int i=0; i<n; i++)
    {
        std::cin>>c;
        if(c=='{')
            Adauga('{');
        else if(c=='[')
            Adauga('[');
        else if(c=='(')
            Adauga('(');
        else if(c==')')
        {
            if(L->info!='(') {std::cout << "Parantezele NU sunt corect inchise"; return 0;}
            Stergere(1);
        }
        else if(c==']')
        {
            if(L->info!='[') {std::cout << "Parantezele NU sunt corect inchise"; return 0;}
            Stergere(1);
        }
        else if(c=='}')
        {
            if(L->info!='{') {std::cout << "Parantezele NU sunt corect inchise"; return 0;}
            Stergere(1);
        }
    }
    std::cout << "Parantezele SUNT CORECT inchise!";
    return 0;
}
