//! #include "D:\patry\Documents\Programming\algos\bettercode.cpp"
//TODO: print table (can be multidimensional), time operations (feg program run time)
/* #region //* ------BETTERCODE------ */
#include <bits/stdc++.h>
using namespace std;

/* #region //* ---VARIABLES--- */
bool debug_mode = false;        //? debug on/off (default off)
bool pragma_mode = false;       //? pragma witchcraft on/off (default off)

/* #endregion */

/* #region //* ---SUPERFORS--- */
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define _FOR3(i, a, n, inc) for(auto i = (a); (inc) > 0 ? i < (n) : i >= (n); i += (inc))
#define _FOR2(i, a, n) _FOR3(i, a, n, 1)
#define _FOR1(i, n) _FOR2(i, 0, n)
#define _FOR0(n) _FOR1(i, n)
#define FOR(...) GET_MACRO(__VA_ARGS__, _FOR3, _FOR2, _FOR1, _FOR0)(__VA_ARGS__)

/* #endregion */

/* #region //* ---DEBUG--- */
#define cerr if(debug_mode) cerr               //? debug out
#define debug(...) if(debug_mode) _debug(0, #__VA_ARGS__, __VA_ARGS__);      //? debug print query

template<typename T>                                                //? debug _print last query
void _debug(int ptr, string s, T x){
    if(s[ptr] >= '0' && s[ptr] <= '9'){         //if number
        while(ptr < s.size()) ++ptr;
    } else{
        while(ptr < s.size())
            cerr << s[ptr++];
        cerr << " = ";
    }
    cerr << x << '\n';
}

template<typename T, typename... tail_types>                        //? debug _print all queries
void _debug(int ptr, string s, T x, tail_types... tail){
    if((s[ptr] >= '0' && s[ptr] <= '9') || (s[ptr] == '"')) {         // if number
        while(s[ptr] != ',')++ptr;
    } else{
        while(s[ptr] != ',')
            cerr << s[ptr++];
        cerr << " = ";
    }
    cerr << x << ", ";

    ptr++;                      // skip ','
    while(s[ptr] == ' ') ptr++;    // depends on user input (1,2,3) / (1, 2, 3)
    _debug(ptr, s, tail...);
}

/* #endregion */

/* #region //* ---SPEEDUP--- */
#define fastio(out) if(!debug_mode) ios_base::sync_with_stdio(false);cin.tie(0);if(out){cout.tie(0);}  //? 0/1 == cout.tie off/on

/* #endregion */

/* #region //* ---SHORTCUTS--- */
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi vector<int>

#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (a).size()
#define PB push_back

#define elif else if
#define setup_rand() srand(time(0))

/* #endregion */

/* #region //* ---TIME--- */
#define NOW() chrono::high_resolution_clock::now()

/* #endregion */

/* #region ---PRAGMA WITCHCRAFT--- */
#if pragma_mode
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")  //Optimization flags
#pragma GCC option("march=native","tune=native","no-zero-upper")            //Enable AVX
#pragma GCC target("avx2")                                                  //Enable AVX
#include <x86intrin.h>                                                      //AVX/SSE Extensions
#endif

/* #endregion */

/* #region //* ---STRING FORMATING--- */
//TODO
// string format(const char* s) {
//     return s;
// }

// template <typename T, typename... Args>
// string format(const char* s, const T &x, const Args &... args) {
//     string r;
//     while(*s != '{') r += *s++;
//     r += to_string(x); s++;
//     r += format(++s, args...);
//     return r;
// }

/* #endregion */

/* #endregion */