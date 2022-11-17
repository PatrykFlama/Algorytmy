struct FU
{
    int parent; // ojciec
    int sz; // rozmiar
    int aux; // można dodawać tu też inne swoje zmienne
};
FU tab[1000007];
void init()
{
    for(int i=1; i<=n; i++)
    {
        tab[i].parent = i; // uznajemy, że korzeń jest swoim własnym ojcem
        tab[i].sz = 1; // rozmiar każdej składowej to 1
    }
}
int Find(int nr)
{
    if(tab[nr].parent == nr)
        return nr;
    tab[nr].parent = Find(tab[nr].parent);
    return tab[nr].parent;
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b)
        return;
    if(tab[a].sz < tab[b].sz)
        swap(a, b);
    tab[b].parent = a;
    tab[a].sz += tab[b].sz;
}