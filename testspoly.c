#include "polynomial.h"
    void ADDTEST1()
    {
    printf("addpoly for int\n");
       Polynomial poly1 = createPolynomial(INTEGER,3);
        ((int *)poly1.values)[0]=2;
        ((int *)poly1.values)[1]=1;
        ((int *)poly1.values)[2]=3;
       Polynomial poly2 = createPolynomial(INTEGER,4);
        ((int *)poly2.values)[0]=1;
        ((int *)poly2.values)[1]=6;
        ((int *)poly2.values)[2]=7;
        ((int *)poly2.values)[3]=8;
       Polynomial poly3 = addpoly(poly1,poly2);
       Polynomial poly4 = addpoly(poly2,poly1);
       for(int i = 0; i<4; i++)
       {
           if(((int*)poly3.values)[i] == ((int*)poly4.values)[i])
           {
               printf("OK\n");
           } else printf("NOT OK\n");
       }
       if(((int*)poly3.values)[0] == 3)
       {
           printf("OK\n");
       } else printf("NOT OK\n");
       if(((int*)poly3.values)[1] == 7)
       {
           printf("OK\n");
       } else printf("NOT OK\n");
       if(((int*)poly3.values)[2] == 10)
       {
           printf("OK\n");
       } else printf("NOT OK\n");
       if(((int*)poly3.values)[3] == 8)
       {
           printf("OK\n");
       } else printf("NOT OK\n");
       destroyPolynomial(poly1);
       destroyPolynomial(poly2);
       destroyPolynomial(poly3);
       destroyPolynomial(poly4);
    }
    void ADDTEST2()
    {
        printf("addpoly for real\n");
        Polynomial poly1 = createPolynomial(REAL,3);
        ((double *)poly1.values)[0]=2.3;
        ((double *)poly1.values)[1]=1.7;
        ((double *)poly1.values)[2]=3.8;
        Polynomial poly2 = createPolynomial(REAL,4);
        ((double *)poly2.values)[0]=1.7;
        ((double *)poly2.values)[1]=6.8;
        ((double *)poly2.values)[2]=7.9;
        ((double *)poly2.values)[3]=8.7;
        Polynomial poly3 = addpoly(poly1,poly2);
        Polynomial poly4 = addpoly(poly2,poly1);
        for(int i = 0; i<4; i++)
        {
            if(((double*)poly3.values)[i] == ((double*)poly4.values)[i])
            {
                printf("OK\n");
            } else printf("NOT OK\n");
        }
        if(((double*)poly3.values)[0] == 4.0)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double*)poly3.values)[1] == 8.5)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double*)poly3.values)[2] == 11.7)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double*)poly3.values)[3] == 8.7)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        destroyPolynomial(poly1);
        destroyPolynomial(poly2);
        destroyPolynomial(poly3);
        destroyPolynomial(poly4);
    }
    void SCALARMULTTEST1()
    {
        printf("scalarmultiply for int\n");
        Polynomial poly1 = createPolynomial(INTEGER,3);
        ((int *)poly1.values)[0]=2;
        ((int *)poly1.values)[1]=1;
        ((int *)poly1.values)[2]=3;
        int n = 7;
        Polynomial poly2 = scalarmultiply(poly1,n);
        if(((int*)poly2.values)[0] == 14)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((int*)poly2.values)[1] == 7)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((int*)poly2.values)[2] == 21)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        destroyPolynomial(poly1);
        destroyPolynomial(poly2);
    }
    void SCALARMULTTEST2()
    {
        printf("scalarmultiply for real\n");
        Polynomial poly1 = createPolynomial(REAL,3);
        ((double*)poly1.values)[0]=2.5;
        ((double*)poly1.values)[1]=1.7;
        ((double*)poly1.values)[2]=3.6;
        double n = 7.2;
        Polynomial poly2 = scalarmultiply(poly1,n);
        if(((double*)poly2.values)[0] == 18)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double*)poly2.values)[1] == 12.24)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double*)poly2.values)[2] == 25.92)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        destroyPolynomial(poly1);
        destroyPolynomial(poly2);
    }
    void MULTTEST1()
    {
        printf("multiplypoly for int\n");
        Polynomial poly1 = createPolynomial(INTEGER,2);
        ((int*)poly1.values)[0]=2;
        ((int*)poly1.values)[1]=1;
        Polynomial poly2 = createPolynomial(INTEGER,3);
        ((int*)poly2.values)[0]=1;
        ((int*)poly2.values)[1]=5;
        ((int*)poly2.values)[2]=10;
        Polynomial poly3 = multiplypoly(poly1,poly2);
        Polynomial poly4 = multiplypoly(poly2,poly1);
        for(int i = 0; i<4; i++)
        {
            if(((int*)poly3.values)[i],((int*)poly4.values)[i]);
        }
        if(((int*)poly3.values)[0] == 2)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((int*)poly3.values)[1] == 11)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((int*)poly3.values)[2] == 25)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((int*)poly3.values)[3] == 10)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        destroyPolynomial(poly1);
        destroyPolynomial(poly2);
        destroyPolynomial(poly3);
        destroyPolynomial(poly4);
    }
    void MULTTEST2()
    {
        printf("multiplypoly for real\n");
        Polynomial poly1 = createPolynomial(REAL,2);
        ((double*)poly1.values)[0]=2.5;
        ((double*)poly1.values)[1]=1.5;
        Polynomial poly2 = createPolynomial(REAL,3);
        ((double*)poly2.values)[0]=1.0;
        ((double*)poly2.values)[1]=5.2;
        ((double*)poly2.values)[2]=10.5;
        Polynomial poly3 = multiplypoly(poly1,poly2);
        Polynomial poly4 = multiplypoly(poly2,poly1);
        for(int i = 0; i<4; i++)
        {
            if(((double*)poly3.values)[i] == ((double*)poly4.values)[i])
            {
                printf("OK\n");
            } else printf("NOT OK\n");
        }
        if(((double*)poly3.values)[0] == 2.5)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double*)poly3.values)[1] == 14.5)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double*)poly3.values)[2] == 34.05)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double*)poly3.values)[3] == 15.75)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        destroyPolynomial(poly1);
        destroyPolynomial(poly2);
        destroyPolynomial(poly3);
        destroyPolynomial(poly4);
    }
    void VALUETEST1()
    {
        printf("valuepoly for int\n");
        Polynomial poly1 = createPolynomial(INTEGER, 3);
        ((int*)poly1.values)[0] = 2;
        ((int*)poly1.values)[1] = 1;
        ((int*)poly1.values)[2] = 3;
        int x = 7;
        int y = valuepoly(poly1, x);
        if(y == 156)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        destroyPolynomial(poly1);
    }
    void VALUETEST2()
    {
        printf("valuepoly for real\n");
        Polynomial poly1 = createPolynomial(REAL, 3);
        ((double*)poly1.values)[0] = 2.5;
        ((double*)poly1.values)[1] = 1.2;
        ((double*)poly1.values)[2] = 3.7;
        double x = 3.0;
        double y = valuepoly(poly1, x);
        if(y == 39.4)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        destroyPolynomial(poly1);
    }
    void COMPTEST1()
    {
        printf("compositionpoly for int\n");
        Polynomial poly1 = createPolynomial(INTEGER, 3);
        ((int*)poly1.values)[0] = 2;
        ((int*)poly1.values)[1] = 1;
        ((int*)poly1.values)[2] = 1;
        Polynomial poly2 = createPolynomial(INTEGER, 3);
        ((int*)poly2.values)[0] = 1;
        ((int*)poly2.values)[1] = 5;
        ((int*)poly2.values)[2] = 10;
        Polynomial poly3 = compositionpoly(poly1, poly2);
        if(((int *) poly3.values)[0] == 4)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((int *) poly3.values)[1] == 15)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((int *) poly3.values)[2] == 55)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((int *) poly3.values)[3] == 100)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((int *) poly3.values)[4] == 100)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        destroyPolynomial(poly1);
        destroyPolynomial(poly2);
        destroyPolynomial(poly3);
    }
    void COMPTEST2()
    {
        printf("compositionpoly for real\n");
        Polynomial poly1 = createPolynomial(REAL, 3);
        ((double*)poly1.values)[0] = 2;
        ((double*)poly1.values)[1] = 1;
        ((double*)poly1.values)[2] = 1;
        Polynomial poly2 = createPolynomial(REAL, 3);
        ((double*)poly2.values)[0] = 1;
        ((double*)poly2.values)[1] = 5;
        ((double*)poly2.values)[2] = 10;
        Polynomial poly3 = compositionpoly(poly1, poly2);
        if(((double *)poly3.values)[0] == 4)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double *) poly3.values)[1] == 15)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double *) poly3.values)[2] == 55)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double *) poly3.values)[3] == 100)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        if(((double *) poly3.values)[4] == 100)
        {
            printf("OK\n");
        } else printf("NOT OK\n");
        destroyPolynomial(poly1);
        destroyPolynomial(poly2);
        destroyPolynomial(poly3);
    }
int main(int argc, char **argv)
{
    ADDTEST1();printf("\n");
    ADDTEST2();printf("\n");
    SCALARMULTTEST1();printf("\n");
    SCALARMULTTEST2();printf("\n");
    MULTTEST1();printf("\n");
    MULTTEST2();printf("\n");
    VALUETEST1();printf("\n");
    VALUETEST2();printf("\n");
    COMPTEST1();printf("\n");
    COMPTEST2();printf("\n");
    interface();
    return 0;
}