// *************************************************** 
// Find prime number and display them
// ***************************************************

#include <iostream>                  // for standard I/O: keyboard and monitor 
#include <iomanip>                   // output format

using namespace std;                 // cin and cout are easy

const int MAX_NUMBER = 1050;

bool isPrime(int); 

int  main( )
{
   int   i, j=0;                        // how to declare variables, integer
   int prime[MAX_NUMBER] = {0}; //all zeros, try no initailization 
   int maxprime;

   prime[j++] = 2;

   cout << "input a max number" << endl;
   cin >> maxprime;

   if (maxprime <=2)
   {cout << "No prime numbers\n";
     return 1;
     }
   cout << setw(5) << 2 ;

   for (i = 3; i <= maxprime; i++)
      if ( isPrime (i) )
      {
         cout << setw(5) << i ;
         if  (j%5 == 4 ) 
              cout << endl ;
         prime[j] = i;
         j++;
      }

   cout << "\nThere are " << j << " prime numbers," << endl ;   

//return 0;   
//   prime [j] = 0;   // I had problems without initailization 

   cout << endl;
   cout << "Prime numnbers between " << 2 << " and " << maxprime << ":\n"
               << endl;
    
  
   i = 0;
   while (prime [i] != 0)
   {
      cout << setw(5) << prime[i] ;
      if  (i%5 == 4 ) 
         cout << endl;
      i++;          // where i++?
   }


   cout << "\nThere are " << i << " prime numbers," << endl ;  // i or i+1?


   return 0 ;        
}

bool isPrime( int n) 
{
   int i;

   if (n==1) 
      return false;
   else if (n==2)
      return true;

   for (i = 2; i <= (n/2); i++)
//   for (i = 2; i*i <= n; i++) // i<= sqrt(n), it works
       if (n%i == 0)   // what if we have the prime array?  
          return false;

   return true;

}
