#include <iostream>
#include <complex>
using namespace std;

class VectorComplex{

private:
    int numar_elemente;
    complex <double> v[100];

public:

    explicit VectorComplex (complex <double> nr=0, int el=0)
    {
        numar_elemente = el;
        for (int i = 0; i < el; i++)
            v[i] = nr;
    }

     VectorComplex(const VectorComplex &z)
    {
        numar_elemente=z.numar_elemente;
        for (int i = 0; i< z.numar_elemente; i++)
            v[i] = z.v[i];
    }

    ~VectorComplex();

    friend ostream& operator<<(ostream &out, const VectorComplex& z);

    friend istream& operator>>( istream  &in, VectorComplex &z );

    double *vector_module();

    int size()
    {
        return numar_elemente;
    }

    void sortare_module();

    complex<double> suma_complexe();

    friend complex<double> operator * (VectorComplex const &, VectorComplex const &);

};

VectorComplex :: ~VectorComplex()
{
    numar_elemente = 0;
}

ostream& operator<<(ostream& out, const VectorComplex& z)
{
    out << '\n';
    out << z.numar_elemente<<" Elemente";
    out << '\n' << '[';
    for (int i = 0; i < z.numar_elemente; i++)
        if (i != z.numar_elemente-1)
            out << z.v[i] << ", ";
        else
            out << z.v[i] << ']';
    out << " ";
    return out;
}
istream& operator>>(istream& in, VectorComplex& z)
{
    cout << "Dati numarul de elemente: ";
    in >> z.numar_elemente;
    for (int i = 0; i < z.numar_elemente; i++)
    {
        cout << "Dati elementul " << i+1 << " sub forma (real, imaginar) : ";
        in >> z.v[i];
    }
    return in;
}

double *VectorComplex :: vector_module( )
{
    double *q = new double[100];
    for (int i = 0; i < numar_elemente; i++)
     q[i] = abs(v[i]);
    return q;
}

void VectorComplex :: sortare_module()
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
    delete a;
}

complex<double> VectorComplex ::suma_complexe()
{
    complex<double> s;
    s = (0,0);
    for (int i = 0; i < numar_elemente; i++)
        s = s + v[i];
    return s;
}

complex<double> operator *(VectorComplex const &x, VectorComplex const &y)
{
    complex<double> ob3(0,0);
    for (int i = 0; i < x.numar_elemente; i++)
        ob3+=x.v[i] * y.v[i];
    return ob3;
}

void citire(int &n, VectorComplex ob[100])
{
    cout<<"Numarul de obiecte care se citesc: ";
    cin>>n;
    for (int i=0; i<n; i++)
          cin>>ob[i];
    for(int i=0; i<n; i++)
          cout<<"Obiectul "<<i+1<<" "<<ob[i]<<'\n';
}



int main() {

        VectorComplex ob[100];
        int n;
        complex<double> scalarp, c;

        citire(n, ob);

        double *x;
        x=ob[0].vector_module();
        cout << "\n" << "Vectorul de module pentru primul element este: " << "\n";
        for(int i = 0; i < ob[0].size(); i++)
            {
                cout << x[i] << " ";
            }
        delete x;

        ob[0].sortare_module();
        cout << "\n" << "Vectorul sortat dupa module este:" << ob[0];

        c=ob[0].suma_complexe();
        cout << "\n" << "Suma elementelor este " << c;

        scalarp= ob[0] * ob[1];
        cout << "\n" << "Produsul scalar al primilor doi vectori este: " << scalarp;


    return 0;
}
