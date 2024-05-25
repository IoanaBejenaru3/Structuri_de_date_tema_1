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

void HeapSort()
{
    
}

int main()
{
    int v[] = {5,7,6,3,2,8,4};

    // BubbleSort(v,9);
    // SelectionSort(v,9);
    // InsertionSort(v,9);
    // MergeSort(v,7,0,6);
    HeapSort();
    for(int i = 0; i < 7; i++)
        std::cout << v[i] << " ";
    std::cout << "DAA";
    return 0;
}