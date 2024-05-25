//LISTE DUBLU INLANTUITE

//voi defini functiile Creare(), Aisare(), Inserare(poz, val), CautareVal(val), Stergere(poz)
//totodata aceste functii sunt definite sa functioneze pentru variabila globala L
#include <iostream>

struct Nod{
    Nod* next;
    Nod* prev;
    int info;
};

void Adauga(Nod* &L, int nr){
    if(L == NULL) //daca lista nu are niciun element
    {
        L  = new Nod;
        L -> info = nr;
        L -> next = NULL;
        L -> prev = NULL;
    }
    else //in cazul in care deja exista elemente
    {
        Nod* nod = new Nod; //facem un nou nod pe care il punem pe pozitia 1 in lista
        nod -> info = nr;
        nod -> next = L; //urmatorul elemten din lista devine headerul anterior
        nod -> prev = NULL; //nu exista nimic anterior primului element
        L = nod; //actualizam lista
    }
}

void Creare(Nod* &L)
{
    L = NULL; //lista este definita trebuie sa o intializam cu NULL pentru a si ca este vida
    int n, val;
    std::cin >> n; //citim numarul de elemente pe care vrem sa le avem in lista initial
    for(int i = 0; i < n; i++) //citim elementele pe care le vrem in lista
        {
            std::cin >> val;
            Adauga(L, val);
        }
}

int CautareVal(Nod* &L, int val){ //functie care cauta prima aparitie a valorii val si returneaza pozitia ei
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

void Inserare(Nod* &L, int poz, int val){
    Nod* x = new Nod; //pointer de tip Nod cu care vom parcurge lista L pentru a nu pierde informatiile din aceasta
    x = L;
    int ct = 1;
    if(poz == 1) //daca cumva trebuie sa inseram la pozitia 1 in lista, pur si simplu mai adaugam un nod care va deveni capul listei
    {
        Adauga(L, val);
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
        nod -> prev = x;
        x -> next = nod;
    }
    return;
}
void Stergere(Nod* &L, int poz){ 
    Nod* x = new Nod; //pointer de tip Nod cu care vom parcurge lista L pentru a nu pierde informatiile din aceasta
    x = L;
    int ct = 1;
    if(poz == 1) //daca trebuie sa stergem capul listei
    {
        x = L ->next; //tinem minte restul listei in x
        delete L; //stergem capul listei
        L = x; //lista devine restul listei fara head (primul elemet)
        L -> prev = NULL; //avem grija sa modificam faptul ca al 2 lea element nu mai are pe nimeni inaintea lui
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
        if(nou -> next != 0) x -> next -> prev = x -> next; 
        delete nou;
    }
}

void Afisare(Nod* L){
    Nod* x = new Nod;
    x = L;
    while(x != 0)
    {
        std::cout << x -> info << ' ';
        x = x -> next;
    }
    std::cout << std::endl;
}

void StergereLista(Nod* &L) //stergem elementele alocate dinamic pentru a evita memory leaks
{
    Nod* x; //va pointa catre aceeasi zona de memorie ca si L deci ne vom ajuta de x sa o stergem
    while(L != 0)
    {
        x = L -> next;
        delete L;
        L = x;
    }
    std::cout << "S-a sters lista!";
}


int main()
{
    Nod* L;
    Creare(L);
    Afisare(L);
    Inserare(L,1,0);
    Afisare(L);
    Inserare(L,6,5);
    Afisare(L);
    Inserare(L,3,8);
    Afisare(L);
    Stergere(L,1);
    Afisare(L);
    Stergere(L,6);
    Afisare(L);
    Stergere(L,2);
    Afisare(L);
    StergereLista(L);
    return 0;
}
