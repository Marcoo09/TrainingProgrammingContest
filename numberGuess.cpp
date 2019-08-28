// ProgrammingContest.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*We are thinking in a number P between (A,B] , after each guess we will
receie a feedback saying if this guess is lower or higher than P
*/

/*
Algorithm:
- Read line with the number T which indicates the number of tests cases
- For each test case read a line which indicates the A and B numbers with ranges
- In the following line you will read a number N with the max number of guess

*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// #include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

int main()
{
    int t;
    //Read t
    scanf("%d", &t);
    vector<int> possibleNumbers;

    while (t > 1)
    {
        int a, b, n;
        //Read a
        //Read b
        scanf("%d%d", &a, &b);
        //Read n
        scanf("%d", &n);
        //Genero array con números entre a y b
        for (int i = a + 1; i <= b - a; i++)
            possibleNumbers.pb(i);

        char *response = NULL;
        int indexToSearch = (b - a) / 2;

        while (n > 1)
        {
            //Busco según la response que tengo
            //Obtengo conjetura
            //Envío conjetura
            //Recibo respuesta
            //Me muevo según conjetura
            int guess = possibleNumbers[indexToSearch];
            cout << guess << endl;
            scanf("%s", response);

            if (response == "TOO_SMALL")
            {
                //Es más chico
                //Me muevo a la derecha
                a = indexToSearch;
                indexToSearch = (b - a) / 2;
            }
            else if (response == "TOO_BIG")
            {
                //Es más grande
                //Me muevo a la izquierda
                b = indexToSearch;
                indexToSearch = (b - a) / 2;
            }
            else
            {
                //Es correcta or out of bond
                break;
            }
            n--;
        }
        t--;
    }
}

/*Solution of contest in C*/

#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int id = 1; id <= T; ++id)
    {
        int A, B, N, done = 0;
        scanf("%d %d %d", &A, &B, &N);
        for (++A; !done;)
        {
            int mid = A + B >> 1;
            char result[32];
            printf("%d\n", mid);
            fflush(stdout);
            scanf("%s", result);
            if (!strcmp(result, "CORRECT"))
                done = 1;
            else if (!strcmp(result, "TOO_SMALL"))
                A = mid + 1;
            else
                B = mid - 1;
        }
    }
    return 0;
}

/*Solution in C++*/

#include <iostream>
#include <string>

int main()
{
    int num_test_cases;
    std::cin >> num_test_cases;
    for (int i = 0; i < num_test_cases; ++i)
    {
        int lo, hi;
        std::cin >> lo >> hi;
        int num_tries;
        std::cin >> num_tries;
        int head = lo + 1, tail = hi;
        while (true)
        {
            int m = (head + tail) / 2;
            std::cout << m << std::endl;
            std::string s;
            std::cin >> s;
            if (s == "CORRECT")
                break;
            if (s == "TOO_SMALL")
                head = m + 1;
            else
                tail = m - 1;
        }
    }
    return 0;
}