#include <iostream>
#include <complex>
using namespace std;

 class Vector_Complex{

private:
    int numar_elemente;
    complex <double> v[100];

public:
    Vector_Complex ()
    { numar_elemente = 0;
        for (int i = 0; i < numar_elemente; i++)
            v[i] = 0;

    }
    Vector_Complex (complex <double> nr, int el)
    {   numar_elemente = el;
        for (int i = 0; i < el; i++)
            v[i] = nr;
    };

    Vector_Complex(const Vector_Complex &z)
    { numar_elemente=z.numar_elemente;
      for (int i = 0; i< z.numar_elemente; i++)
            v[i] = z.v[i];

    };

    ~Vector_Complex();

    friend ostream& operator<<(ostream &x, const Vector_Complex& z);

    friend istream& operator>>( istream  &x, Vector_Complex &z );

    void Vector_Module(Vector_Complex z, double x[]);

    int size(Vector_Complex z)
    { return z.numar_elemente;
    };

    void Sortare_Module(Vector_Complex &z, double x[]);

    complex<double> Suma_Complexe(Vector_Complex z);

    friend  complex<double> operator * (Vector_Complex const &, Vector_Complex const &);

    void citire(int &n, Vector_Complex v[100]);
};

Vector_Complex :: ~Vector_Complex()
{    numar_elemente = 0;
};

ostream& operator<<(ostream& x, const Vector_Complex& z)
{   x<<'\n';
    x<<z.numar_elemente<<" Elemente";
    x<<'\n';
    for (int i = 0; i < z.numar_elemente; i++)
        x << z.v[i] << " ";
    return x;
}

istream& operator>>(istream& x, Vector_Complex& z)
{   cout<<"Dati numarul de elemente: ";
    x>>z.numar_elemente;
    for (int i = 0; i < z.numar_elemente; i++)
    {cout<<"Dati elementul "<<i<<" sub forma (real, imaginar) : ";
        x >> z.v[i];
        };
    return x;
}

void Vector_Complex :: Vector_Module(Vector_Complex z, double x[])
{ for (int i = 0; i < z.numar_elemente; i++)
     x[i] = abs(z.v[i]);
};

void Vector_Complex ::Sortare_Module(Vector_Complex &z, double x[])
{ for (int i = 0; i < z.numar_elemente-1; i++)
    for(int j = i+1; j < z.numar_elemente; j++)
        if (x[i] > x[j])
        {complex<double> q;
         q=z.v[i];
         z.v[i]=z.v[j];
         z.v[j]=q;
        }
};

complex<double> Vector_Complex ::Suma_Complexe(Vector_Complex z)
{   complex <double> s;
    s=(0,0);
    for(int i=0; i<z.numar_elemente; i++)
        s=s+z.v[i];
    return s;
};

complex<double> operator *(Vector_Complex const &x, Vector_Complex const &y)
{ complex<double> ob3(0,0);
    for (int i = 0; i < x.numar_elemente; i++)
        ob3+=x.v[i] * y.v[i];
  return ob3;
};

void citire(int &n, Vector_Complex ob[100])
{   cout<<"Numarul de obiecte care se citesc: ";
    cin>>n;
  for (int i=0; i<n; i++)
      cin>>ob[i];
  for(int i=0; i<n; i++)
      cout<<"Obiectul "<<i+1<<" "<<ob[i];

};

int main() {
        Vector_Complex ob[100];
        int n;
        complex<double> scalarp, c;
        double x[100];

        citire(n, ob);

        ob[0].Vector_Module(ob[0], x);
        cout<<"\n"<<"Vectorul de module pentru primul element este: "<<"\n";
        for(int i = 0; i < ob[0].size(ob[0]); i++)
        { cout<<x[i]<<" ";
        }

        ob[0].Sortare_Module(ob[0], x);
        cout<<"\n"<<"Vectorul sortat dupa module este:"<<ob[0];

        c=ob[0].Suma_Complexe(ob[0]);
        cout<<"\n"<<"Suma elementelor este "<<c;

        scalarp= ob[0] * ob[1];
        cout<<"\n"<<"Produsul scalar al primilor doi vectori este: "<<scalarp;
    return 0;
}
