//VECTOR SORTAT -> BTS (ARBORE BINAR DE CAUTARE BALANSAT - BALANCED SEARCH BINARY TREE)
#include <iostream>
#include <vector>

//ce este un BTS balansat si ce idee de implementare folosesc?
//un arbore binar de cautare balansat este un arbore care respecta anumite conditii: orice nod are maxim 2 fii, in stanga mai mic, in dreapta mai mare, si, in plus, pentru a fi balansat inseamna
//ca pozitionarea nodurilor in arbore trebuie sa fie optima pentru a pastra eficienta arborelui
//balanced bts are timp logartimic pentru majoritatea operatiilor aplicate asupra lui
//pentru implementare ne ajutam de faptul ca vectorul dat ca input este sortat ceea ce ne ajuta sa determinam mereu elementul "cel mai optim" pentru a fi radacina arborelui, radacina unui subarbore, s.a.

//structura care ne ajuta sa memoram nodurile unui BTS
struct Nod{
    int info;
    Nod* left_child, *right_child; 
};

Nod* BTS;

//functie care construieste noduri ale BTS-ului si le returneaza pentru a putea fi memorate de restul nodurilor din BTS
Nod* Build_BTS(std::vector <int> v, int left, int right)
{
    if(left <= right) //daca gasim cel putin un element in subvectorii vectorului principal este perfect
    {                 //il adaugam ca nod in BTS si ii cautam copiii
        int middle = (left + right) / 2;
        Nod* nod = new Nod; //alocam spatiu pentru un nod
        nod -> info =v[middle]; //memoram valoarea
        std::cout << v[middle] << " "; //afisam pentru a vedea cum este construit optim acest BTS
        nod -> left_child = Build_BTS(v, left, middle - 1); //cautam cel mai "optim" element care poate fi left_child
        nod -> right_child = Build_BTS(v, middle + 1, right); //cautam cel mai "optim" element care poate fi right_child
        return nod;
    }
    else return NULL; //daca nu mai avem niciun element inseamna ca nu avem nici copii pentru nodul din care venim si returnam NULL

}

int main()
{
    int n, val;
    std::vector <int> v;
    std::cin >> n; //citim numarul de elemente ale vectorrului sortat
    for(int i = 0; i < n; i++)
    {
        std::cin >> val;
        v.push_back(val); //adaugam elementele citite in vector
    }
    std::cout << "Construim BTS si afisam ordinea in care acestea sunt inserate in el:\n";
    Nod* BTS = Build_BTS(v, 0, n-1);
    return 0;
}