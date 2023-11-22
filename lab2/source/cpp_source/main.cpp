#include"closest_points.h"
#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

int
main()
{
    ClosestPoints clp = ClosestPoints();
    Timer tm = Timer();
    clp.ReadFile("../data.txt");
    tm.start();
    clp.SortCoordinate();
    clp.Divide();
    tm.stop();
    clp.PrintClosest();
    cout << "Time: " << tm.elapsedMilliseconds() << "ms" << endl;
    tm.start();
    clp.Bruteforce();
    tm.stop();
    cout << "Bruteforce Time: " << tm.elapsedMilliseconds() << "ms" << endl;
    return 0;
}
