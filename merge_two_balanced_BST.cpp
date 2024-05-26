//INTERCLASAREA A DOI ARBORI BINARI DE CAUTARE ECHILIBRATI

//pentru a rezolva aceasta problema ma voi ajuta de doi vectori cititi de la tastatura care vor fi sortati strict crescator
//cu acestia voi face doi arbori binari de cautare echilibrati si ulterior ii voi interclasa rezultand unul singur

#include <iostream>
#include <vector>

struct Nod{
    int info;
    int frecv = 0;
    Nod* left_child, *right_child; 
};


Nod* Build_Balanced_BTS(std::vector <int> v, int left, int right)
{
    if(left <= right) //daca gasim cel putin un element in subvectorii vectorului principal este perfect
    {                 //il adaugam ca nod in BTS si ii cautam copiii
        int middle = (left + right) / 2;
        Nod* nod = new Nod; //alocam spatiu pentru un nod
        nod -> info =v[middle]; //memoram valoarea
        nod -> left_child = Build_Balanced_BTS(v, left, middle - 1); //cautam cel mai "optim" element care poate fi left_child
        nod -> right_child = Build_Balanced_BTS(v, middle + 1, right); //cautam cel mai "optim" element care poate fi right_child
        return nod;
    }
    else return NULL; //daca nu mai avem niciun element inseamna ca nu avem nici copii pentru nodul din care venim si returnam NULL

}

//implementare interclasare a doi balanced BTS

void MergeBalancedBTS(int val, Nod* &BTS)
{
    Nod* x = BTS;
    bool cond = false, left = false;
    //cautam nodul din BTS de care trebuie sa legam noul nod cu valoarea pe care o inseram
    while(!cond)
    {
        if(val > x -> info)
        {
            if(x -> right_child == NULL)
                cond = true;
            else x = x -> right_child;
        }
        else if(val < x -> info)
        {
            if(x -> left_child == NULL)
                {cond = true; left = true;}
            else x = x -> left_child;
        }
        else 
        {
            x -> frecv++;
            return;
        }
    }
    //in x se afla nodul cu care vom face legatura
    Nod* nou = new Nod;
    nou -> info = val;
    nou -> right_child = NULL;
    nou -> left_child = NULL;
    if(left == true)
        x -> left_child = nou;
    else x -> right_child = nou;
}

void Inordine(Nod* nod, Nod* &BTS1)
{
    if(nod != NULL)
    {
        Inordine(nod -> left_child, BTS1);
        MergeBalancedBTS(nod -> info, BTS1);
        Inordine(nod -> right_child, BTS1);
    }
}

void AfisareInordine(Nod* nod)
{
    if(nod != NULL)
    {
        AfisareInordine(nod -> left_child);
        std::cout << nod ->info << " ";
        AfisareInordine(nod -> right_child);
    }
}

int main()
{
    int n1, n2 , val;
    std::vector <int> v;
    std::cin >> n1; //citim numarul de elemente ale vectorrului sortat

    for(int i = 0; i < n1; i++)
    {
        std::cin >> val;
        v.push_back(val); //adaugam elementele citite in vector
    }
    Nod* BTS1 = Build_Balanced_BTS(v, 0, n1-1);

    v.clear();

    std::cin >> n2;
    for(int i = 0; i < n2; i++)
    {
        std::cin >> val;
        v.push_back(val); //adaugam elementele citite in vector
    }
    Nod* BTS2 = Build_Balanced_BTS(v, 0, n2-1);

    //interclasarea celor doi balanced BTS
    //voi folossi algoritmul in care inseram pe rand cate un nod din primul arbore in al doilea
    ///parcurgem BTS2 fie prin RSD, ori SRD, ori SDR (parcurgerea aleasa nu influenteaza alg deoarece am nevoie doar sa ajung in fiecare nod cumva, toate cele 3 facand acest lucru)
    Inordine(BTS2, BTS1);
    //afisam BTS1 folosind inordinea pentru a vedea daca elementele sunt afisate in ordine crescatoare
    //daca da, arborele este corect dpdp al balanced BTS
    //in caz contrar, nu respecta regulile unui astfel de arbore
    AfisareInordine(BTS1);
    return 0;
}