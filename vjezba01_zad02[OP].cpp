#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct matrix
{
    int m;
    int n;
    int **mat_i_j;
};
void int_generation(matrix* mat, int a, int b)
{
        cout << "unesite broj m: " << endl;
        cin >> mat->m;
        cout << "unesite broj n: " << endl;
        cin >> mat->n;
        int rand_num;
        mat->mat_i_j=new int*[mat->m];
        for(int i=0;i<(mat->m);i++)
        {
            mat->mat_i_j[i]= new int[mat->n];
        }
        srand(time(NULL));
        for(int i=0;i<mat->m;i++)
        {
            for(int j=0;j<mat->n;j++)
            {
                rand_num=rand()%(b-a)+a;
                mat->mat_i_j[i][j]=rand_num;
            }
        }
}

void addition(matrix mat1, matrix mat2,matrix* mat3)
{
        if((mat1.m==mat2.m)&&(mat1.n==mat2.n))
        {
            cout << "zbroj matrica 1 i 2 je matrica: " << endl << endl << endl;
            mat3->mat_i_j=new int*[mat1.m];
            for(int i=0;i<(mat1.m);i++)
            {
                mat3->mat_i_j[i]= new int[mat1.n];
            }
            for(int i = 0; i < mat1.m; ++i)
            {
                for(int j = 0; j < mat2.n; ++j)
                {
                     mat3->mat_i_j[i][j] = mat1.mat_i_j[i][j] + mat2.mat_i_j[i][j];

                }
            }
        }
        else
            cout << "matrice se ne mogu zbrojiti i oduzeti !!" << endl;
}
void sub(matrix mat1, matrix mat2,matrix* mat3)
{
        if((mat1.m==mat2.m)&&(mat1.n==mat2.n))
        {
            cout << "razlika matrica 1 i 2 je matrica: " << endl << endl << endl;
            mat3->mat_i_j=new int*[mat1.m];
            for(int i=0;i<(mat1.m);i++)
            {
                mat3->mat_i_j[i]= new int[mat1.n];
            }
            for(int i = 0; i < mat1.m; ++i)
            {
                for(int j = 0; j < mat2.n; ++j)
                {
                     mat3->mat_i_j[i][j] = mat1.mat_i_j[i][j] - mat2.mat_i_j[i][j];

                }
            }
        }
}
void multiplication(matrix mat1,matrix mat2, matrix* mat_multiplication)
{
    if(1)
    {
        cout << "umnozak matrice 1 i 2 je matrica: " << endl << endl << endl;
            mat_multiplication->mat_i_j=new int*[mat1.m];
            for(int i=0;i<(mat1.n);i++)
            {
                mat_multiplication->mat_i_j[i]= new int[mat2.n];
            }
        for(int i = 0; i < mat1.m; ++i)
            for(int j = 0; j < mat2.n; ++j)
            {
                mat_multiplication->mat_i_j[i][j]=0;
            }
        for(int i = 0; i < mat1.m; ++i)
            for(int j = 0; j < mat2.n; ++j)
            {
                for(int k = 0; k < mat1.n; ++k)
                {
                    mat_multiplication->mat_i_j[i][j] += mat1.mat_i_j[i][k] * mat2.mat_i_j[k][j];
                }
            }
    }
    else
        cout<<"The matrixes are not compatable for multiplication"<<endl<<endl;
}
void output(matrix mat)
{
    for(int i=0;i<mat.m;i++)
    {
        for(int j=0;j<mat.n;j++)
        {
            cout << mat.mat_i_j[i][j] << "  ";
        }
        cout<< endl;
    }
}

void output_1(matrix mat,int a,int b)
{
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            cout<<mat.mat_i_j[i][j]<< "  ";
        }
        cout<<endl;
    }
}
void transponed(matrix unos1, matrix* trans) //Funkcija za transponiranje
{
	// Declare memory block of size m
    trans->mat_i_j=new int*[unos1.n];

    for(int i=0;i<(unos1.n);i++)
    {
        trans->mat_i_j[i]= new int[unos1.m];
    }
    for (int i = 0; i < unos1.n; ++i)
        for (int j = 0; j < unos1.m; ++j)
        {
            trans->mat_i_j[j][i] = unos1.mat_i_j[i][j];
        }

}
int main(void)
{
    matrix mat_unos1,mat_unos2,mat_addition,mat_sub, mat_mul,mat_trans,mat_trans1;
    int a,b;
    cout << "unesite parametre a i b koji ce biti raspon za generiranje brojeva : " << endl;
    cin >> a;
    cin >> b;
    cout << "unesite velicinu pomocu parametara m i n za prvu matricu! " << endl;
    int_generation(&mat_unos1,a,b);
    output(mat_unos1);
    cout << "unesite velicinu pomocu parametara m i n za drugu matricu" << endl;
    int_generation(&mat_unos2,a,b);
    output(mat_unos2);
    addition(mat_unos1,mat_unos2,&mat_addition);
    output_1(mat_addition,mat_unos1.m,mat_unos1.n);
    sub(mat_unos1,mat_unos2,&mat_sub);
    output_1(mat_sub,mat_unos1.m,mat_unos1.n);
    multiplication(mat_unos1,mat_unos2,&mat_mul);
    output_1(mat_mul,mat_unos1.m,mat_unos2.n);
    transponed(mat_unos1,&mat_trans);
    output_1(mat_trans,mat_unos1.m,mat_unos1.n);
    transponed(mat_unos2,&mat_trans1);
    cout << endl << endl;
    output_1(mat_trans1,mat_unos1.m,mat_unos1.n);
    return 0;

}
