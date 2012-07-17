#include <algorithm> 
#include <cstdio> 
#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <map> 
#include <set> 
#include <string> 
#include <utility> 
#include <vector> 

using namespace std; 


struct LampsGrid { 
   int mostLit( vector <string> initial, int K ) { // caret here 
      int res = 0; 
      for ( int i=0; i<(int)initial.size(); ++i ) { 
         int zeros = count(initial[i].begin(), initial[i].end(), '0'); 
         if ( zeros%2 == K%2 && zeros <= K ) { 
            res = max( res, count(initial.begin(), initial.end(), initial[i]) );
         } 
      } 
      return res; 
   } 
}; 