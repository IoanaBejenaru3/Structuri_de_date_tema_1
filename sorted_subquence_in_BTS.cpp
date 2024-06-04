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

//pentru a verifica daca secventa se regaseste in BTS va trebui sa facem o parcurgere SRD pentru a prelua elementele in ordine crescatoare
//daca gasim elementul de pe poz secventa[poz], incrementam poz si il cautam pe urmatorul
//daca la finalul parcurgerii poz != nr + 1 inseamna ca secventa nu se regaseste in BTS
void Verificare(Nod* BTS, std::vector <int> secventa, int& poz)
{
    if(BTS == NULL) return;
    Verificare(BTS->left_child, secventa, poz);
    if(BTS->info == secventa[poz]) poz++;
    Verificare(BTS->right_child, secventa, poz);
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

    int nr;
    std::vector <int> secventa;
    std::cout << "Numarul de elementele ale secventei: "; std::cin >> nr;
    std::cout << "Elementele secventei sortate strict crescator:\n";
    for(int i = 0; i < nr; i++)
    {
        int elem;
        std::cin >> elem;
        secventa.push_back(elem);
    }
    int poz = 0;
    Verificare(BTS, secventa, poz);
    if(poz == nr) std::cout << "Secventa se regaseste!";
    else std::cout << "Secventa NU se regaseste!";
    return 0;
}