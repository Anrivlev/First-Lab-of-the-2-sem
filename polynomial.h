#include <stdio.h>
#include <stdlib.h>
#include <windef.h>
typedef enum {INTEGER, REAL} Eltype;
typedef struct
{
    Eltype eltype;
    int size;
    void *values;
} Polynomial;
Polynomial createPolynomial(Eltype eltype, int size){
    Polynomial polynomial;
    polynomial.eltype = eltype;
    polynomial.size = size;

    int typesize;
    switch(eltype){
        case INTEGER:
            typesize = sizeof(int);
            break;
        case REAL:
            typesize = sizeof(double);
            break;
        default:
            break;
    }
    polynomial.values = calloc(size, typesize);
    return polynomial;
}
void destroyPolynomial(Polynomial polynomial)
{
    if(polynomial.size == 0)
    {
        return;
    }
    free(polynomial.values);
    return;
}
Polynomial addpoly(Polynomial a,Polynomial b)
{
    if (a.eltype != b.eltype)
    {
        exit(1);
    }
    int size = max(a.size,b.size);
    Polynomial result = createPolynomial(a.eltype, size);
    for(int i = 0; i<(size);i++)
    {
        if(a.eltype == INTEGER)
        {
            if(i < min(a.size,b.size))
            {
                ((int *) result.values)[i] = ((int *) a.values)[i] + ((int *) b.values)[i];
            } else if(a.size>b.size)
            {
                ((int *) result.values)[i] = ((int *) a.values)[i];
            } else if(b.size>a.size)
            {
                ((int *) result.values)[i] = ((int *) b.values)[i];
            }
        } else if(a.eltype == REAL)
        {
            if(i < min(a.size,b.size))
            {
            ((double*)result.values)[i] = ((double*)a.values)[i] + ((double*)b.values)[i];
            } else if(a.size>b.size)
            {
                ((double *) result.values)[i] = ((double *) a.values)[i];
            } else if(b.size>a.size)
            {
                ((double *) result.values)[i] = ((double *) b.values)[i];
            }
        }
    }
    return result;
}
Polynomial scalarmultiply(Polynomial p, double scal)
{
    Polynomial result = createPolynomial(p.eltype, p.size);
    for(int i = 0;i<p.size;i++)
    {
        if(p.eltype == INTEGER)
        {
            ((int*)result.values)[i] = ((int*)p.values)[i] *(int)scal;
        }
        else if(p.eltype == REAL)
        {
            ((double*)result.values)[i] = ((double*)p.values)[i] * (double)scal;
        }
    }
    return result;
}
Polynomial multiplypoly(Polynomial a, Polynomial b)
{
    if (a.eltype != b.eltype)
    {
        exit(1);
    }
    int size = (a.size+b.size-1);
    Polynomial result = createPolynomial(a.eltype, size);
    for (int i = 0; i <= result.size; i++)
    {
        if(result.eltype == INTEGER)
        {
            ((int*)result.values)[i]=0;
        } else if(result.eltype == REAL)
        {
            ((double*)result.values)[i]=0;
        }
    }
    for (int i = 0; i < a.size; i++)
    {
        for (int j = 0; j < b.size; j++)
        {
            if(a.eltype == INTEGER)
            {
                ((int*)result.values)[i + j] = ((int*)result.values)[i + j] + ((int*)a.values)[i] * ((int*)b.values)[j];
            } else if(a.eltype == REAL)
            {
                ((double*)result.values)[i + j] = ((double*)result.values)[i + j] + ((double*)a.values)[i] * ((double*)b.values)[j];
            }
        }
    }
    return result;
}
double valuepoly(Polynomial a, double x)
{
    double result = 0;
    double xpower = 1;
    for(int i = 0; i<a.size; i++)
    {
        if(a.eltype == INTEGER)
        {
            result =(int)result + ((int*)a.values)[i] * (int)xpower;
            xpower = xpower*x;
        } else if(a.eltype == REAL)
        {
            result = (double)result + ((double*)a.values)[i] * (double)xpower;
            xpower = xpower*x;
        }
    }
    return result;
}
Polynomial compositionpoly(Polynomial a, Polynomial b)
{
    if (a.eltype != b.eltype)
    {
        exit(1);
    }
    int size =((a.size-1)*(b.size-1))+1;
    Polynomial result = createPolynomial(a.eltype, size);
    Polynomial c = createPolynomial(a.eltype, size);
    Polynomial d = createPolynomial(a.eltype, size);
    if(result.eltype == INTEGER)
    {
        for (int i = 0; i < result.size; i++)
        {
            ((int*)result.values)[i]=0;
            ((int*)c.values)[i]=0;
        }
        ((int*)result.values)[0]=((int*)a.values)[0];
        for (int i = 0; i< b.size; i++)
        {
            ((int*)c.values)[i]=((int*)b.values)[i];
        }
        for (int i = 0; i<c.size; i++)
        {
            ((int*)result.values)[i]=((int*)result.values)[i]+((int*)a.values)[1]*((int*)c.values)[i];
        }
        for(int i = 2; i<a.size; i++)
        {
            for(int j = 0; j< c.size; j++)
            {
                for(int k = 0; k<b.size; k++)
                {
                    ((int*)d.values)[j + k] = ((int*)d.values)[j + k] + ((int*)c.values)[j] * ((int*)b.values)[k];
                }
            }
            for(int j = 0; j< result.size; j++)
            {
                ((int*)result.values)[j]=((int*)result.values)[j]+((int*)a.values)[i]*((int*)d.values)[j];
            }
            for( int i =0; i<c.size; i++)
            {
                ((int*)c.values)[i]=((int*)d.values)[i];
            }
        }

    } else if(result.eltype == REAL)
    {

        for (int i = 0; i < result.size; i++)
        {
            ((double*)result.values)[i]=0;
            ((double*)c.values)[i]=0;
        }
        ((double*)result.values)[0]=((double*)a.values)[0];
        for (int i = 0; i< b.size; i++)
        {
            ((double*)c.values)[i]=((double*)b.values)[i];
        }
        for (int i = 0; i<c.size; i++)
        {
            ((double*)result.values)[i]=((double*)result.values)[i]+((double*)a.values)[1]*((double*)c.values)[i];
        }
        for(int i = 2; i<a.size; i++)
        {
            for(int j = 0; j< c.size; j++)
            {
                for(int k = 0; k<b.size; k++)
                {
                    ((double*)d.values)[j + k] = ((double*)d.values)[j + k] + ((double*)c.values)[j] * ((double*)b.values)[k];
                }
            }
            for(int j = 0; j< result.size; j++)
            {
                ((double*)result.values)[j]=((double*)result.values)[j]+((double*)a.values)[i]*((double*)d.values)[j];
            }
            for( int i =0; i<c.size; i++)
            {
                ((double*)c.values)[i]=((double*)d.values)[i];
            }
        }

    }
    destroyPolynomial(c);
    destroyPolynomial(d);
    return result;
}
void printpoly(Polynomial p)
{
    if(p.eltype == INTEGER)
    {
        for( int i = p.size-1; i>0; i--)
        {
            printf("%d*x^%d + ", ((int*)p.values)[i],i);
        }
        printf("%d", ((int*)p.values)[0]);
    } else if(p.eltype == REAL)
    {
        for( int i = p.size-1; i>0; i--)
        {
            printf("%lf*x^%d+", ((double*)p.values)[i],i);
        }
        printf("%lf", ((double*)p.values)[0]);
    }
    printf("\n");
}
Polynomial scanpoly()
{
    Polynomial polynomial;

    printf("%s\n", "type of polynomial:\n1. int\n2. real\n");
    int type;
    scanf("%d", &type);
    printf("\n");

    printf("%s\n", "size of polynomial:");
    int size;
    scanf("%d", &size);
    printf("\n");

    Eltype eltype;
    if(type == 1)
    {
        eltype = INTEGER;
    } else if(type == 2)
    {
        eltype = REAL;
    }
    polynomial = createPolynomial(eltype, size);
    printf("%s\n", "Coefficients of the Polynomial (from C0 to Cn)");
    for(int i=0;i<polynomial.size;i++)
    {
        if(eltype == INTEGER)
        {
            scanf("%d", &((int*)polynomial.values)[i]);
        } else if (eltype == REAL)
        {
            scanf("%lf", &((double*)polynomial.values)[i]);
        }
    }
    printf("\n");
    return polynomial;
}
void interface()
{
    Polynomial a;
    a.size = 0;
    Polynomial b;
    b.size = 0;
    Polynomial r;
    r.size = 0;
    double n;
    int vvod;
    while(1)
    {
        printf("%s\n",
               "1. Create a Polynomial A\n"
               "2. Create a Polynomial B\n"
               "3. Create a number n\n"
               "4. R = A+B\n"
               "5. R = A*B\n"
               "6. R = n*A\n"
               "7. m = A(n)\n"
               "8. R = A(B)\n"
               "9. exit\n");
               scanf("%d",&vvod);
               printf("\n");
               switch(vvod) {
                   case 1:
                       destroyPolynomial(a);
                       a = scanpoly();
                       break;
                   case 2:
                       destroyPolynomial(b);
                       b = scanpoly();
                       break;
                   case 3:
                       printf("%s\n", "number n:");
                       scanf("%lf", &n);
                       printf("\n");
                       break;
                   case 4:
                       r = addpoly(a, b);
                       printpoly(r);
                       break;
                   case 5:
                       r = multiplypoly(a, b);
                       printpoly(r);
                       break;
                   case 6:
                       r = scalarmultiply(a, n);
                       printpoly(r);
                       break;
                   case 7:
                       if (a.eltype == INTEGER) {
                           printf("%d\n", (int)valuepoly(a, n));
                       } else if (a.eltype == REAL) {
                           printf("%lf\n", valuepoly(a, n));
                       }
                       break;
                   case 8:
                       r = compositionpoly(a, b);
                       printpoly(r);
                       break;
                   case 9:
                       return;
                   default:
                       exit(1);
               }
        destroyPolynomial(r);
    }
}