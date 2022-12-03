#include <iostream>

using namespace std;

//prototype __________________________
void Affiche (int m[9][9]);
void Recherche(int tab[9],int v);
void Solve(int m[9][9]);
bool zer(int m[9][9]);
void Creation(int m[9][9]);
int Compteur(int tab[9]);
void Mlczero(int m[9][9],int l,int c);

//This program is a SUDOKU Solver is made by Amir FARES __________________________________________________________

int main()
{
    int m[9][9]={0};
    cout << "Donner la grille de SUDOKU : (Apres chaque nombre click Entree)" << endl ;
    Creation(m);
    Affiche(m);
    while(zer(m))
    {
        Solve(m);
    }
    cout << "After Solve : " << endl ;
    Affiche(m);

    return 0;
}


//function _____________________________

void Affiche (int m[9][9])
{
    int l,c;
    for(l=0;l<9;l++)
    {
        for(c=0;c<9;c++)
        {
            cout << m[l][c] << " ";
        }
        cout << endl;
    }
}

void Recherche(int tab[9],int v)
{
    if(v!=0)
    {
        int i=0;
        while(i<9)
        {
            if(tab[i]==v)
            {
                tab[i]=0;
            }
            i++;
        }
    }

}

void Solve(int m[9][9])
{
    int l,c;
    for(l=0;l<9;l++)
    {
        for(c=0;c<9;c++)
        {
            if(m[l][c]==0)
            {
                Mlczero(m,l,c);
            }
        }
    }
}

bool zer(int m[9][9])
{
    bool z=false;
    int l,c;
    for(l=0;l<9;l++)
    {
        for(c=0;c<9;c++)
        {
            if(m[l][c]==0)
            {
                z=true;
                break;
            }
        }
        if(m[l][c]==0)
        {
            break;
        }
    }
    return z;
}

void Creation(int m[9][9])
{
    int l,c;
    for(l=0;l<9;l++)
    {
        cout << "Ligne " << l+1 << ":" << endl ;
        for(c=0;c<9;c++)
        {
            cin >> m[l][c];
        }
    }
}

int Compteur(int tab[9])
{
    int cmp=0;
    for(int u=0;u<9;u++)
    {
        if(tab[u]!=0)
        {
            cmp++;
        }
    }
    return cmp;
}

void Mlczero(int m[9][9],int l,int c)
{
                int tab[9]={1,2,3,4,5,6,7,8,9};
                for(int k=0;k<9;k++)
                {
                    int val=m[l][k];
                    Recherche(tab,val);
                }
                for(int k=0;k<9;k++)
                {
                    int val=m[k][c];
                    Recherche(tab,val);
                }
                if(l<3)
                {
                    for(int i=0;i<3;i++)
                    {
                        if(c<3)
                        {
                            for(int j=0;j<3;j++)
                            {
                                int val=m[i][j];
                                Recherche(tab,val);
                            }
                        }
                        if((c>2)&&(c<6))
                        {
                            for(int j=3;j<6;j++)
                            {
                                int val=m[i][j];
                                Recherche(tab,val);
                            }
                        }
                        if((c>5)&&(c<9))
                        {
                            for(int j=6;j<9;j++)
                            {
                                int val=m[i][j];
                                Recherche(tab,val);
                            }
                        }
                    }
                }
                if((l>2)&&(l<6))
                {
                    for(int i=3;i<6;i++)
                    {
                        if(c<3)
                        {
                            for(int j=0;j<3;j++)
                            {
                                int val=m[i][j];
                                Recherche(tab,val);
                            }
                        }
                        if((c>2)&&(c<6))
                        {
                            for(int j=3;j<6;j++)
                            {
                                int val=m[i][j];
                                Recherche(tab,val);
                            }
                        }
                        if((c>5)&&(c<9))
                        {
                            for(int j=6;j<9;j++)
                            {
                                int val=m[i][j];
                                Recherche(tab,val);
                            }
                        }
                    }
                }
                if((l>5)&&(l<9))
                {
                    for(int i=6;i<9;i++)
                    {
                        if(c<3)
                        {
                            for(int j=0;j<3;j++)
                            {
                                int val=m[i][j];
                                Recherche(tab,val);
                            }
                        }
                        if((c>2)&&(c<6))
                        {
                            for(int j=3;j<6;j++)
                            {
                                int val=m[i][j];
                                Recherche(tab,val);
                            }
                        }
                        if((c>5)&&(c<9))
                        {
                            for(int j=6;j<9;j++)
                            {
                                int val=m[i][j];
                                Recherche(tab,val);
                            }
                        }
                    }
                }
                if(Compteur(tab)==1)
                {
                    int w=0;
                    while((w<9)&&(tab[w]==0))
                    {
                        w++;
                    }
                    m[l][c]=tab[w];
                }
}
