#include <iostream>
#include <complex>
using namespace std;

 class vector_complex{

private:
    int numar_elemente;
    complex <double> v[100];

public:

    explicit vector_complex (complex <double> nr=0, int el=0)
    {   numar_elemente = el;
        for (int i = 0; i < el; i++)
            v[i] = nr;
    };

    vector_complex(const vector_complex &z)
    { numar_elemente=z.numar_elemente;
      for (int i = 0; i< z.numar_elemente; i++)
            v[i] = z.v[i];

    };

    ~vector_complex();

    friend ostream& operator<<(ostream &x, const vector_complex& z);

    friend istream& operator>>( istream  &x, vector_complex &z );

    double *vector_module();

    int size()
    { return numar_elemente;
    };

    void sortare_module();

    complex<double> suma_complexe();

    friend  complex<double> operator * (vector_complex const &, vector_complex const &);


};

vector_complex :: ~vector_complex()
{    numar_elemente = 0;
}

ostream& operator<<(ostream& x, const vector_complex& z)
{   x<<'\n';
    x<<z.numar_elemente<<" Elemente";
    x<<'\n';
    for (int i = 0; i < z.numar_elemente; i++)
        x << z.v[i] << " ";
    return x;
}
istream& operator>>(istream& x, vector_complex& z)
{   cout<<"Dati numarul de elemente: ";
    x>>z.numar_elemente;
    for (int i = 0; i < z.numar_elemente; i++)
    {cout<<"Dati elementul "<<i<<" sub forma (real, imaginar) : ";
        x >> z.v[i];
        }
    return x;
}
double q[100];
double *vector_complex :: vector_module( )
{
    for (int i = 0; i < numar_elemente; i++)
     q[i] = abs(v[i]);
    return q;
}

void vector_complex ::sortare_module()
{
    double *a=vector_module();
    for (int i = 0; i < numar_elemente-1; i++)
    for(int j = i+1; j < numar_elemente; j++)
        if (a[i] > a[j])
        {complex<double> t;
         t=v[i];
         v[i]=v[j];
         v[j]=t;
        }

}

complex<double> vector_complex ::suma_complexe() {
    complex<double> s;
    for (int i = 0; i < numar_elemente; i++)
        s = s + v[i];
    return s;
}

complex<double> operator *(vector_complex const &x, vector_complex const &y)
{ complex<double> ob3(0,0);
    for (int i = 0; i < x.numar_elemente; i++)
        ob3+=x.v[i] * y.v[i];
  return ob3;
}

void citire(int &n, vector_complex ob[100])
{   cout<<"Numarul de obiecte care se citesc: ";
    cin>>n;
  for (int i=0; i<n; i++)
      cin>>ob[i];
  for(int i=0; i<n; i++)
      cout<<"Obiectul "<<i+1<<" "<<ob[i];

}
double *x;
int main() {
        vector_complex ob[100];
        int n;
        complex<double> scalarp, c;

        citire(n, ob);

        x=ob[0].vector_module();
        cout<<"\n"<<"Vectorul de module pentru primul element este: "<<"\n";
        for(int i = 0; i < ob[0].size(); i++)
        { cout<<x[i]<<" ";
        }

        ob[0].sortare_module();
        cout<<"\n"<<"Vectorul sortat dupa module este:"<<ob[0];

        c=ob[0].suma_complexe();
        cout<<"\n"<<"Suma elementelor este "<<c;

        scalarp= ob[0] * ob[1];
        cout<<"\n"<<"Produsul scalar al primilor doi vectori este: "<<scalarp;
    return 0;
}
