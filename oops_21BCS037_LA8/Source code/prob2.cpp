#include <iostream>
#include <bits/stdc++.h>
#include "./point.h"
#include "./pointN.h"
#include "./line.h"
#include "./vector.h"
#include <chrono>
using namespace std::chrono;
using namespace std;
slowSort(Element *e[], int n)
{
    int i, j;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        while (j >= 0 && (e[j]->norm() > e[i]->norm()))
        {
            e[j + 1] = e[j];
            j--;
        }
        e[j + 1] = e[i];
    }
}
// Prob 3------------------------->
fastSort(Element *e[], int n)
{
    int i, j;
    bool sub;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        sub = e[j]->norm() > e[i]->norm();
        while (j >= 0 && sub)
        {
            e[j + 1] = e[j];
            j--;
            sub = e[j]->norm() > e[i]->norm();
        }
        e[j + 1] = e[i];
    }
}
sperformance(Element *e[], int n)
{
    auto start = high_resolution_clock::now();
    slowSort(e, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time = " << duration.count() << "\xE6s" << endl;
    return duration.count();
}
fperformance(Element *e[], int n)
{
    auto start = high_resolution_clock::now();
    fastSort(e, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time = " << duration.count() << "\xE6s" << endl;
    return duration.count();
}
int main()
{
    int sizes[4] = {100, 1000, 10000, 100000};
    for (int i = 0; i < 4; i++)
    {
        int s = sizes[i];
        Element *all[s];
        for (int j = 0; j < s; j++)
        {
            if (j % 3 == 0)
            {
                double _x = rand_gen();
                double _y = rand_gen();
                all[j] = new Point(_x, _y);
            }
            else if (j % 3 == 1)
            {
                double _x = rand_gen();
                double _y = rand_gen();
                all[j] = new Vector(_x, _y);
            }
            else if (j % 3 == 2)
            {
                int _n = ((rand() % 10) + 2);
                PointN *temp = new PointN(_n);
                temp->setRandom();
                all[j] = temp;
            }
        }
        double eff1 = 0;
        double eff2 = 0;
        cout << "Data Size = " << s << endl;
        cout << "Slow Sort: ";
        eff1 = sperformance(all, s);
        cout << "Fast Sort: ";
        eff2 = fperformance(all, s);
        cout << "Efficiency -- " << eff1 / eff2 << endl;
    }
    return 0;
}