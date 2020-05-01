#include<stdio.h>
#include<math.h>

#define author codermehraj
#define MAX 300000
#define MAX1 1000002

int Prime[MAX], nPrime; // list of prime and number of prime
bool mark[MAX1]; // for marking sieve approach

// for prime 0
// for not prime 1

void sieve(int n)
{
    int i, j, limit = sqrt(n * 1.0) + 2;

    mark[1] = 1; // as 1 is not a prime
    for(i = 4; i <= n; i += 2) mark[i] = 1;
    //almost all of the even number is not prime

    Prime[nPrime++] = 2;
    for(i = 3; i <= n; i += 2)
        // i prime hoile abar katbo
        if(mark[i]==0){
            Prime[nPrime++] = i; // jehetu age kati nai prime
            if(i <= limit){
            // limite kato limiter beshi jaile kata lagbe na cz kata ase already
                for(j = i * i; j <= n; j = j + (i * 2) ){
                    // i*i er gulao kata sesh
                    mark[j] = 1; // eta prime na cz i er gunitok
                }
            }
        }
        printf("Prime found :: %d\n",nPrime); // koto ta prime paisi
}


int main()
{
    int a,l;
    printf("Enter a number :: ");
    scanf("%d",&a);
    //a=900000;
    sieve(a);
    //if(mark[a]) printf("Not Prime");
    //else printf("Prime");
    for(l=0;l<nPrime;l++) printf("%d th prime >> %d\n",l+1,Prime[l]);
    return 0;
}
