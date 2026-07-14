#include <iostream>

using namespace std;

void p1()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++)
            cout << "*";

        cout << "\n";
    }
}

void p2()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=i; j++)
            cout << "*";

        cout << "\n";
    }
}

void p3()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=i; j++)
            cout << j;

        cout << "\n";
    }
}

void p4()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=i; j++)
            cout << i;

        cout << "\n";
    }
}

void p5()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=5; j>=i; j--)
            cout << "*";

        cout << "\n";
    }
}

void p6()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=5; j>=i; j--)
            cout << (6-j);

        cout << "\n";
    }
}

void p7()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=5; j>i; j--)
            cout << " ";

        for(int j=i; j>=1; j--)
            cout << "*";

        for(int j=(i-1); j>=1; j--)
            cout << "*";

        cout << "\n";
    }
}

void p8()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=(i-1); j>=1; j--)
            cout << " ";

        for(int j=5; j>=i; j--)
            cout << "*";

        for(int j=5; j>i; j--)
            cout << "*";

        cout << "\n";
    }
}

void p9()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=5; j>i; j--)
            cout << " ";

        for(int j=i; j>=1; j--)
            cout << "*";

        for(int j=(i-1); j>=1; j--)
            cout << "*";

        cout << "\n";
    }

    for(int i=1; i<=5; i++)
    {
        for(int j=(i-1); j>=1; j--)
            cout << " ";

        for(int j=5; j>=i; j--)
            cout << "*";

        for(int j=5; j>i; j--)
            cout << "*";

        cout << "\n";
    }
}

void p10()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=i; j++)
            cout << "*";

        cout << "\n";
    }

    for(int i=1; i<=4; i++)
    {
        for(int j=4; j>=i; j--)
            cout << "*";

        cout << "\n";
    }
}

void p11()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=i; j>=1; j--)
        {
            if(j%2 == 0) cout << "0";

            else cout << "1";
        }

        cout << "\n";
    }
}

void p12()
{
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=i; j++)
            cout << j;

        for(int j=(4-i); j>=1; j--)
            cout << "  ";

        for(int j=i; j>=1; j--)
            cout << j;

        cout << "\n";
    }
}

void p13()
{
    int k = 1;

    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=i; j++)
            cout << k++ << " ";

        cout << "\n";
    }
}

void p14()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=i; j++)
            cout << char(64 + j);

        cout << "\n";
    }
}

void p15()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=5; j>=i; j--)
            cout << char(70 - j);

        cout << "\n";
    }
}

void p16()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=i; j++)
            cout << char(64 + i);

        cout << "\n";
    }
}

void p17()
{
    for(int i=1; i<=4; i++)
    {
        for(int j=4; j>i; j--)
            cout << " ";

        for(int j=1; j<=i; j++)
            cout << char(64 + j);

        for(int j=(i-1); j>=1; j--)
            cout << char(64 + j);

        cout << "\n";
    }
}

void p18()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=i; j>=1; j--)
            cout << char(70 - j) << " ";

        cout << "\n";
    }
}

void p19()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=5; j>=i; j--)
            cout << "*";

        for(int j=(i-1); j>=1; j--)
            cout << "  ";

        for(int j=5; j>=i; j--)
            cout << "*";

        cout << "\n";
    }

    for(int i=2; i<=5; i++)
    {
        for(int j=i; j>=1; j--)
            cout << "*";

        for(int j=5; j>=(i+1); j--)
            cout << "  ";

        for(int j=i; j>=1; j--)
            cout << "*";

        cout << "\n";
    }
}

void p20()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=i; j++)
            cout << "*";

        for(int j=(5-i); j>=1; j--)
            cout << "  ";

        for(int j=i; j>=1; j--)
            cout << "*";

        cout << "\n";
    }

    for(int i=1; i<=4; i++)
    {
        for(int j=4; j>=i; j--)
            cout << "*";

        for(int j=i; j>=1; j--)
            cout << "  ";

        for(int j=4; j>=i; j--)
            cout << "*";

        cout << "\n";
    }
}

void p21()
{
    for(int i=1; i<=2; i++)
    {
        for(int j=2; j>=i; j--)
            cout << "*";

        for(int j=(i-1); j>=1; j--)
            cout << "  ";

        for(int j=2; j>=i; j--)
            cout << "*";

        cout << "\n";
    }

    for(int i=1; i<=2; i++)
    {
        for(int j=i; j>=1; j--)
            cout << "*";

        for(int j=2; j>=(i+1); j--)
            cout << "  ";

        for(int j=i; j>=1; j--)
            cout << "*";

        cout << "\n";
    }
}

void p22()
{
    for(int i=4; i>=1; i--)
    {
        for(int j=3; j>=i; j--)
            cout << (j+1) << " ";

        for(int j=(2*i - 1); j>=1; j--)
            cout << i << " ";

        for(int j=(i+1); j<=4; j++)
            cout << j << " ";

        cout << "\n";
    }

    for(int i=1; i<=3; i++)
    {
        for(int j=2; j>=i; j--)
            cout << (j+2) << " ";

        for(int j=1; j<=(2*i + 1); j++)
            cout << i+1 << " ";

        for(int j=(i+2); j<=4; j++)
            cout << j << " ";

        cout << "\n";
    }
}

int main()
{
    p1();

    cout << "\n";

    p2();

    cout << "\n";

    p3();

    cout << "\n";

    p4();

    cout << "\n";

    p5();

    cout << "\n";

    p6();

    cout << "\n";

    p7();

    cout << "\n";

    p8();

    cout << "\n";

    p9();

    cout << "\n";

    p10();

    cout << "\n";

    p11();

    cout << "\n";

    p12();

    cout << "\n";

    p13();

    cout << "\n";

    p14();

    cout << "\n";

    p15();

    cout << "\n";

    p16();

    cout << "\n";

    p17();

    cout << "\n";

    p18();

    cout << "\n";

    p19();

    cout << "\n";

    p20();

    cout << "\n";

    p21();

    cout << "\n";

    p22();

    return 0;
}
