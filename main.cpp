#include <iostream>
#include <math.h>
#include <iomanip>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main() {
    cout << "xp = "; cin >> xp; cout << "xk = "; cin >> xk; cout<<"dx = ";cin>>dx; cout<<"e = ";cin>>e; cout << endl;
    x = xp;
    while ( x <= xk ){
        sum();
        cout << x <<" " 
             << S      <<" "
             << exp(x) << " "
             << n      << endl;
        x += dx;
    }
    cin.get();
    return 0;
}

namespace nsVar{
    extern int n;
    extern double x, xp, xk, dx, e, a, S, result;
};

namespace nsVar{
    int n;
    double x, xp, xk, dx, e, a, S, result;
};

namespace nsDod{
    void dod();
};

#include "dod.h"
#include "var.h"

using namespace nsVar;

void nsDod::dod(){
    a *= ((x * x) * ((2*n - 1) / (2*n + 1)));
}

namespace nsSum{
    void sum();
};

#include <math.h>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum(){
    n = 0;
    a = 2 * x; 
    S = a;
    do{
        n++;
        dod();
        S += a;
    } while(fabs(a) > e);
}