#include <iostream>
/* METODE DE SORTARE */

//BUBBLE SORT
void BubbleSort(int v[], int lungime)
{
    bool ok = 0;
    while(!ok)
    {
        ok = 1;
        for(int i = 0; i < lungime - 1; i++)
            if(v[i] > v[i+1])
            {
                ok = 0;
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
    }
}

//SORTAREA PRIN SELECTIE
//se bazeaza ca la pasul i sa aducem cel mai mic element existent de la i+1 la n, unde n este lungimea vectorului, la pozitia i
void SelectionSort(int v[], int lungime)
{
    for(int i = 0; i < 8; i++)
        for( int j = i+1; j < 9; j++)
            if(v[j] < v[i])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

//SORTAREA PRIN INSERTIE
//se bazeaza pe faptul ca primul element este de fapt un vector sortat
//astfel, pentru elementele urmatoare noi trebuie
void InsertionSort(int v[], int lungime)
{
    for(int i = 1; i < 9; i++)
    {
        int aux = v[i], j = i-1;
        while(j>=0 && aux < v[j])
        {
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = aux;
    }
           
}

//SORTARE PRIN INTERCLASARE
//se bazeaza pe divide et impera
//impartim problema mare in probleme mai mici de aceeasi natura

void MergeOperation(int v[], int length, int left, int middle, int right)
{
    //luam un vector auxiliar in care vom face interclasarea celor doua parti din vector si anume let->middle middle+1->right
    int aux[length+5];
    int count = 0; //variabila care retine la ce pozitie am ajuns in aux
    int i = left, j = middle + 1;
    while(i <= middle && j <= right)
        if(v[i] < v[j]) 
            aux[count++] = v[i++]; 
        else aux[count++] = v[j++];
    std::cout << "pozitii " << i << " " << j << std::endl; 
    while(i <= middle)
        aux[count++] = v[i++]; 
    while(j <= right)
        aux[count++] = v[j++]; 
    //urmeaza sa punem elementele ordonate crescator din aux in vectorul v
    j = 0;
    for(i = left; i <= right; i++)
        {v[i] = aux[j++]; std::cout << v[i] << "  ";}
    std::cout << std::endl;

}

void MergeSort(int v[], int length, int left, int right)
{
    if(left < right)
    {
        int middle = (left + right) / 2;
        //DIVIDE
        MergeSort(v, length, left, middle);
        MergeSort(v, length, middle + 1, right);
        //IMPERA
        MergeOperation(v , length, left, middle, right);
    }
}


//HEAPSORT


void Heapify(int v[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    //daca exista copilul stang al elementului curent (largest)
    if(left < n && v[left] > v[largest]) largest = left; 
    //la fel si pentru copilul din dreapta
    if(right < n && v[right] > v[largest]) largest = right;

    if(largest != i)
    {
        int aux = v[largest]; 
        v[largest] = v[i];
        v[i] = aux;
        Heapify(v, n, largest);
    }
}

void HeapSort(int v[], int n)
{
    //noi deja avem vectorul deci trebuie sa ne asiguram ca aducem vectorul sub forma de vector pentru "heap" adica elem i are la 2*i+1 si 2*i+2 copii aferenti
    for(int i = n / 2 - 1; i >= 0; i--)
        Heapify(v, n, i);

    //acum ca vectorul este in pozitia corecta putem incepe sa scoatem din el valori obtinand astfel sir de numere sortate cres / descres
    for(int i = n - 1; i >= 0; i--)
    {
        //luam pe rand elementele de la final si le dam swap cu primul elem din vect
        int aux = v[i];
        v[i] = v[0];
        v[0] = aux;
        //acum pentru a ne asigura ca o sa avem ca prim element cel maxim din vector-ul ramas, trebuie sa aplicam din nou heapify pe vectorul redus
        //incepem heapify-ul de la primul element deoarece acela este nodul caruia trebuie sa ii gasim pozitia in heap
        //astfel elem coboara in heap pana la pozitia corecta
        Heapify(v, i, 0);
        //vectorul la final va fi sortat deoarece elemntul maxim mereu ajunge pe ultima pozitie valabila datorita swapului
        //deci sortarea si heapifyul se intampla in acelasi vector doar ca la intervale diferite ale vectorului
    }
}

int main()
{
    int v[] = {5,7,6,3,2,8,4};

    // BubbleSort(v,9);
    // SelectionSort(v,9);
    // InsertionSort(v,9);
    // MergeSort(v,7,0,6);
    HeapSort(v,7);
    for(int i = 0; i < 7; i++)
        std::cout << v[i] << " ";
    std::cout << "DAA";
    return 0;
}