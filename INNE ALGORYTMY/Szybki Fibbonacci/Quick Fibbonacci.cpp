#include <iostream>
#include <utility>
using namespace std;
typedef long long int LLI;

void mult_matrix(LLI a[2][2], LLI b[2][2], LLI w[2][2]){
    LLI temp[2][2];
    temp[0][0] = w[0][0]; temp[1][0] = w[1][0]; temp[0][1] = w[0][1]; temp[1][1] = w[1][1];
    //A = AA + BC                                       //  [A, B]
    temp[0][0] = a[0][0]*b[0][0] + a[1][0]*b[0][1];        //  [C, D]
    //B = AB + BD
    temp[1][0] = a[0][0]*b[1][0] + a[1][0]*b[1][1];        //  [A, B]
    //C = CA + DC                                       //  [C, D]
    temp[0][1] = a[0][1]*b[0][0] + a[1][1]*b[0][1];
    //D = CB + DD                                       //  [AA+BC, AB+BD]
    temp[1][1] = a[0][1]*b[1][0] + a[1][1]*b[1][1];        //  [CA+DC, CB+DD]

    w[0][0] = temp[0][0]; w[1][0] = temp[1][0]; w[0][1] = temp[0][1]; w[1][1] = temp[1][1];
}
//TODO fast pot od matrix
void pot(LLI a[2][2], LLI n, LLI w[2][2]){
    LLI copy[2][2];
    copy[0][0] = a[0][0]; copy[1][0] = a[1][0]; copy[0][1] = a[0][1]; copy[1][1] = a[1][1];
    while(n > 0){
        if(n%2 == 0){
            n /= 2;
            mult_matrix(copy, copy, copy);
        }
        else{
            n--;
            mult_matrix(a, copy, w);
            a = w;
            n /= 2;
            mult_matrix(copy, copy, copy);
        }
    }
}

LLI fib(LLI n){
    if(n == -1){
        return 0;
    }

    LLI w[2][2], a[2][2];
    a[0][0] = 1; a[1][0] = 1; a[0][1] = 1; a[1][1] = 0;
    w[0][0] = 1; w[1][0] = 1; w[0][1] = 1; w[1][1] = 1;
    pot(a, n, w);
    return w[1][0];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    LLI n;
    cin >> n;
    n--;
    cout << fib(n) << "\n";

    return 0;
}