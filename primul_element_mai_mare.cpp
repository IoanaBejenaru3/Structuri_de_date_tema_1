#include <iostream>

//IMPLEMEMTAREA LISTELOR ALOCATE DINAMIC

struct Nod{
    Nod* next;
    int element;
    int pozitie;
};

Nod* L;

void Adauga(int nr, int poz){
    if(L == NULL) //daca lista nu are niciun element
    {
        L  = new Nod;
        L -> element = nr;
        L -> pozitie = poz;
        L -> next = NULL;
    }
    else //in cazul in care deja exista elemente
    {
        Nod* nod = new Nod;
        nod -> element = nr;
        nod -> pozitie = poz;
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
            Adauga(val, i);
        }
}


void Inserare(int poz, int val, int pozitie){
    Nod* x = new Nod; //pointer de tip Nod cu care vom parcurge lista L pentru a nu pierde informatiile din aceasta
    x = L;
    int ct = 1;
    if(poz == 1) //daca cumva trebuie sa inseram la pozitia 1 in lista, pur si simplu mai adaugam un nod care va deveni capul listei
    {
        Adauga(val, pozitie);
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
        nod -> element = val;
        nod -> pozitie = pozitie;
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

//COADA - IMPLEMENTATA DINAMIC

struct Nod_coada{
    Nod_coada* next;
    int poz_element;
    int poz_mai_mare;
};

Nod_coada* C;

void AdaugaCoada(int poz1, int poz2)
{
    Nod_coada* nod = new Nod_coada;
    nod -> poz_element = poz1;
    nod -> poz_mai_mare = poz2;
    nod -> next = NULL;
    if(C == NULL)
    {
        
        C = nod;
        return;
    }
    Nod_coada* x = C; //parcurgem coada pentru a afla de cine legam urmatorul element
    while(x -> next != 0)
        x = x -> next;
    //acum ne aflam pe ultimul element din coada
    x -> next = nod;
}

void AfisareCoada()
{
    Nod_coada* x = C;
    while(x != 0)
    {
        std::cout << "(" << x -> poz_element << "," << x -> poz_mai_mare << ")" << std::endl;
        x = x->next;
    }
}



int main()
{
    int n, val;
    std::cin >> n >> val;
    L = NULL; //o lista vida inca nu avem nimic in ea
    C = NULL;
    Adauga(val, 0);
    for(int i = 1; i < n; i++)
        {
            std::cin >> val;
            Nod* x = L;
            while(val > x -> element)
            {
                AdaugaCoada(x -> pozitie, i);
                Stergere(1);
                x = x -> next;
            }
            Inserare(1, val, i);
        }
    Nod* x = L;
    while(x != 0)
    {
        AdaugaCoada(x -> pozitie, -1); //nu am gasit niciun element in vector care sa fie mai mare decat elementul de pe respectiva pozitie
        x = x-> next;
    }
    AfisareCoada();
    return 0;
}