#include <stdio.h>

int n ;
void printArr( int arr[] , int n );               //function declaration
void remove_dupplicates( int arr[] , int *n );    // here n is passed by reference as its value should be altered in main too

int main(){

    printf("\nThis programme finds Union of the given arrays \n");
    int n , m ;     // n & m are sizes for array 1 % 2
    printf("\nenter size for 1st array : ");
    scanf("%d",&n);
    printf("enter elements for 1st array of size %d : ",n);

    int arr1[n];
    for (int i = 0 ; i < n ; i++){
        scanf("%d",&arr1[i]);
    }
    printf("enter size for 2nd array : ");
    scanf("%d",&m);
    printf("enter elements for 2nd array of size %d : ",m);

    int arr2[m];
    for (int i = 0 ; i < m ; i++){
        scanf("%d",&arr2[i]);
    }


    //merging 2 arrays for finding union...
    int mer_arr[n+m];
    for (int i = 0 ; i < n ;  i++ ){
            mer_arr[i] = arr1[i] ;
    }
    for (int i = n , j = 0 ; i < n+m , j < m ; i++ , j++ ){
            mer_arr[i] = arr2[j] ;
    }


    // sorting array ...
    int temp ;
    for (int i = 0 ; i  < n+m ; i++){
        for (int j = i+1 ; j < n+m ; j++){
            if (mer_arr[i] > mer_arr[j]){
                temp = mer_arr[i] ;
                mer_arr[i] = mer_arr[j];
                mer_arr[j] = temp ;
            }
        }
    }


    int k = n+m ;

    printf("\nUnion set of 2 arrays is : ");
    // removing repeating elements from union set
    remove_dupplicates(mer_arr , &k );

    printArr(mer_arr , k );
    return 0 ;

}


void printArr( int arr[] , int n ){  // function to print array
    for (int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
}

void remove_dupplicates(int arr[] , int *n ){  // function to remove duplicate elements from array
    int j = 0 ;
    for ( int i = 0 ; i < *n ; i++ ){
        if ( arr[i] != arr[i+1] ){
            // adding value to array only if adjacent values are not same
            arr[j++] = arr[i] ;
        }
    }
    *n = j ;   // updating size of array .
}
