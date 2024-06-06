//ALGORITMUL LUI KRUSKAL -> determinarea unui arbore partial de costt minim
#include <iostream>
#include <vector>
#include <algorithm>

struct muchie{
    int x, y, c;
};

void Citire(std::vector <muchie>& v, int& n, int& m)
{
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
        {
            muchie aux;
            std::cin >> aux.x >> aux.y >> aux.c;
            v.push_back(aux);
        }
}

//sortam toate muchiile de la cel mai mic cost la cel mai mare
void Sortare(std::vector <muchie>& v)
{
    sort(v.begin(), v.end(),[](muchie a, muchie b){return a.c < b.c;});
}

void Kruskal(std::vector <muchie> v, std::vector <int>& sol1, std::vector <int>& sol2, std::vector <int>& C, int n)
{
    int cn1, cn2, s = 0;
    int k = 0;
    //primul pas
    for(int i = 0; i < n; i++)
        C.push_back(i);
    Sortare(v);
    //trebuie sa avem n-1 muchii in arborele pe care vrem sa il gasim
    for(int i = 0; i < n-1; i++)
    {
        while(C[v[k].x] == C[v[k].y]) k++;
        s += v[k].c;
        sol1.push_back(v[k].x);
        sol2.push_back(v[k].y);

        cn1 = C[v[k].x]; cn2 = C[v[k].y];
        for(int j = 0; j < n; j++)
            if(C[j] == cn1) C[j] = cn2;
    }
    std::cout << s << std::endl;
}

void Afisare(std::vector <int> sol1, std::vector <int> sol2, int n)
{
    for(int i = 0; i < n-1; i++)
        std::cout << sol1[i] << " " << sol2[i] << std::endl;
}

int main()
{
    std::vector <muchie> v;
    std::vector <int> sol1, sol2, C;
    int n, m;
    //n = nr de noduri, m = nr de muchii
    Citire(v,n,m);
    Kruskal(v, sol1, sol2, C, n);
    Afisare(sol1, sol2, n);
    return 0;
}