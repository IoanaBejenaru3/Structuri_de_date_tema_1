#include <iostream>
#include <string>
//implementarea unui hash table care retine liste de cuvinte ordonate lexicografic dupa litere

struct Nod{
    Nod* next;
    std::string cuv;
    std::string up_cuv;
};

Nod* HashTable[25]; //hash table pentru cele 26 de litere ale alfabetului englezesc


std::string MakeUpper(std::string cuv)
{
    for(char c : cuv)
        c = toupper(c);
    return cuv;
}

int HashCode(std::string cuvant)
{
    return toupper(cuvant[0]) - 'A';
}

void Adauga(std::string cuv, Nod* &L)
{
    if(L == NULL)
    {
        Nod* nod = new Nod;
        nod -> next = NULL;
        nod -> cuv = cuv;
        nod -> up_cuv = MakeUpper(cuv);
        L = nod;
        return;
    }
    else
    {
        Nod* nod = new Nod, *x = L;
        nod -> cuv = cuv;
        nod -> up_cuv = MakeUpper(cuv);
        while(x -> next != 0 && x -> next -> up_cuv < nod-> up_cuv) //cat timp mai avem elemente de parcurs si cat timp acestea sunt mai mici dpdv leicografic
            x = x -> next;
        nod -> next = x -> next;
        x -> next = nod;
    }
}

void AfisareLista(Nod* L, int val)
{
    Nod* x = L;
    if(x == NULL)
    {
        char c = val + 'A';
        char c2 = val + 'A' + 32;
        std::cout << "Nu avem cuvinte cu litera " << c <<"/" << c2 << std::endl;
        return;
    }
    while(x != 0)
    {
        std::cout << x -> cuv << " ";
        x = x -> next;
    }
    std::cout << std::endl;
}

void AfisareHashTable(Nod* HashTable[])
{
    for(int i = 0; i < 25; i++)
        AfisareLista(HashTable[i], i);
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
}


void StergereHashTable(Nod* HashTable[])
{
    for(int i = 0; i < 25; i++)
        StergereLista(HashTable[i]);
    std::cout << "S-a sters HashTable-ul!";
}

int main()
{
    int n; //numarulde cuvinte citite
    std::string cuv;
    std::cin >> n;

    for(int i = 0; i < 25; i++)
        HashTable[0] = NULL; //ne asiguram ca listele sunt intial vide deoarece nu am adaugat niciun cuv
    //citim cuvintele si completam hash tableul
    for(int i = 0; i < n; i++)
    {
        std::cin >> cuv;
        Adauga(cuv, HashTable[HashCode(cuv)]);
    }   
    AfisareHashTable(HashTable);
    StergereHashTable(HashTable);
    return 0;
}