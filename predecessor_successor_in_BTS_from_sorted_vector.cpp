//ma ajut de o problema anterioara pentru a putea sa o implementez pe aceasta


//VECTOR SORTAT STRICT CRESCATOR-> BTS (ARBORE BINAR DE CAUTARE BALANSAT - BALANCED SEARCH BINARY TREE)
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

//functie care construieste noduri ale BTS-ului si le returneaza pentru a putea fi memorate de restul nodurilor din BTS
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

void FindPredSucc(Nod* BTS, int& pred, int& succ, int element)
{
    if(BTS == NULL) return;
    if(BTS->info == element) //daca se gaseste chiar in radacina e cazul simplu preluam copii nodului
    {
        if(BTS->left_child != NULL)
            pred = BTS->left_child->info;
        else pred = -1; //-1 inseamna ca nu gasim predecesor diferit de valoarea primita
        
        if(BTS->right_child != NULL)
            succ = BTS->right_child->info;
        else succ = -1;

        return; 
    }

    if(BTS->info > element)
    {
        succ = BTS->info;
        FindPredSucc(BTS->left_child, pred, succ, element);
    }
    else
    {
        pred = BTS->info;
        FindPredSucc(BTS->right_child, pred, succ, element);
    }

}

int main()
{
    int n, val;
    std::vector <int> v;
    std::cout << "Numar elemente: ";
    std::cin >> n; //citim numarul de elemente ale vectorului sortat
    std::cout << "ELementele vectorului in ordine stric crescatoare:\n";
    for(int i = 0; i < n; i++)
    {
        std::cin >> val;
        v.push_back(val); //adaugam elementele citite in vector
    }
    Nod* BTS = Build_Balanced_BTS(v, 0, n-1);

    int elem;
    std::cout << "Element pentru care trebuie sa gasim succesorul si predecesorul: ";
    std::cin >> elem;
    int pred = -1, succ = -1;
    FindPredSucc(BTS, pred, succ, elem);
    std::cout << "Preceseroul este: " << pred << std::endl;
    std::cout << "Succesorul este: " << succ << std::endl;
    return 0;
}