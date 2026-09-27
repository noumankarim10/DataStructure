#include <iostream>
using namespace std;
void pointersToPointers( ) {
int a = 10;
int *ptr1 = &a;
int **ptr2 = &ptr1;      int ***ptr3 = &ptr2;     int ****ptr4 = &ptr3;
//printing addresses.
cout<<"\n printing addresses \n"
    <<"\n address of int variable: &a = "<<&a
    <<"\n address of ptr to int variable: &ptr1 = "<<&ptr1
    <<"\n address of ptr to ptr-int variable: &ptr2 = "<<&ptr2
    <<"\n address of ptr to ptr to ptr-int variable &ptr3 = "
    <<&ptr3
    <<"\n address of ptr to ptr to ptr to ptr-int variable &ptr4 = "
    <<&ptr4
    <<endl;

//printing values.
cout<<"\n printing values "
    <<"\n value of variable a = "<<a
    <<"\n value of variable a by dereferencing ptr-int: *ptr1 = "
    <<*ptr1
    <<"\n value of variable a by dereferencing ptr to ptr-integer: **ptr2 = "
    <<**ptr2
    <<"\n value by dereferencing ptr to to ptr to ptr-integer: ***ptr3 = "
    <<***ptr3
    <<"\n value by dereferencing ptr to to ptr to ptr to ptr-integer: ****ptr4 = "
    <<****ptr4<<endl;

/*
//test your concept.
cout<<"\n test pointer to pointer concepts"
    <<"\n ptr1 ?: = "<<ptr1
    <<"\n *ptr2 ?: = "<<*ptr2
    <<"\n **ptr2 ?: = "<<**ptr2
    <<"\n *ptr3 ?: = "<<*ptr3
    <<"\n **ptr3 ?: = "<<**ptr3
    <<"\n ***ptr3 ?: = "<<***ptr3
    <<"\n *ptr4 ?: = "<<*ptr4
    <<"\n **ptr4 ?: = "<<**ptr4
    <<"\n ***ptr4 ?: = "<<***ptr4
    <<"\n ****ptr4 ?: = "<<****ptr4
    <<endl;

*/
}
void ArrayOfpointersToPointers(){
int v1=19,v2=20,v3[3] = {31,32,33}, v4[3] = {41,42,43};
int *v1ptr = &v1, *v2ptr = &v2, *v3ptr = v3, *v4ptr = v4;
int **v1ptrptr = &v1ptr, **v2ptrptr=&v2ptr,
    **v3ptrptr=&v3ptr, **v4ptrptr=&v4ptr;
int ***aoptrtoptr[4];
aoptrtoptr[0] = &v1ptrptr;
aoptrtoptr[1] = &v2ptrptr;
aoptrtoptr[2] = &v3ptrptr;
aoptrtoptr[3] = &v4ptrptr;
for (int i=0; i<4; i++){
    if (i==0){
        cout<<"\n value of variable v1 = "<<***aoptrtoptr[i];
        continue;
    }else if (i==1){
        cout<<"\n value of variable v1 = "<<***aoptrtoptr[i];
        continue;
    }
    cout<<"\n printing value of array = ";
    for(int j=0; j<3; j++)
        cout<<*(**aoptrtoptr[i] + j)<<"\t";
    cout<<endl;
}
/*
cout<<"\n address of v3 array = "<<v3<<endl;
cout<<"\n address of v4 array = "<<v4<<endl;
*/
}
int* passingAndReturningPointers(int *xptr,int *y){
    (*xptr)++;
    (*y)++;
    return y;
}
void passing1DArrays(int a1[],int a1size,int (&a2)[5]){
/*
    cout<<"\n size of a1 = "<<sizeof(a1);
    cout<<"\n size of a2 = "<<sizeof(a2);
    cout<<"\n address of first location in a1 = "<<a1;
    cout<<"\n address of second location in a1 + 1 = "<<a1+1;
    cout<<"\n address of (location?) in through &a1 = "<<&a1;
    cout<<"\n address of second location in a1 through &a1 + 1 = "<<&a1+1;
    cout<<"\n address of first location in a2 = "<<a2;
    cout<<"\n address of second location in a2 + 1 = "<<a2+1;
    cout<<"\n address of second location in a2 through &a2 + 1 = "<<&a2+1;
*/
/*
    cout<<"\n  values in a1 through loop using sizeof operator (effects of decay) :\n  ";
    for (int i=0; i<sizeof(a1)/sizeof(a1[0]); i++)
        cout<<a1[i]<<"\t";

    cout<<"\n value is in a1 through loop my using size passed as a separate parameter :\n ";
    for (int i=0; i<a1size; i++)
        cout<<a1[i]<<"\t";

    cout<<"\n  values in a2 through loop=  ";
    for (int i=0; i<sizeof(a2)/sizeof(a2[0]); i++)
        cout<<a2[i]<<"\t";
*/
}
void passingMDArrayByCopyStyle(int arr[][3], int rows) {
    cout<<"\n printing contents of MD Array \n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void passingMDArrayByReferenceStyle(int (&arr)[4][3]) {
    cout<<"\n printing contents of MD Array \n";
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        for (int j = 0; j < sizeof(arr[0])/sizeof(arr[0][0]); ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int* returningStaticArray() {
    static int arr[5] = {10, 20, 30, 40, 50};
    return arr; // Return pointer to the array
}
void dynamicMemoryAllocation( ){
//dynamic memory allocation.
    int *dyiptr1 = new int;
    *dyiptr1 = 300;
    int *dyiptr2 = new int(10);
    int *dyarr = new int[3];
    dyarr[0] = 1;
    dyarr[1] = 2;
    dyarr[2] = 3;
    cout<<"\n address of dyiptr1 = "<<dyiptr1
    <<", value of dyiptr1 = "<<*dyiptr1;
    cout<<"\n address of dyiptr2 = "<<dyiptr2
    <<", value of dyiptr2 = "<<*dyiptr2;
    cout<<"\n contents of dynamic array = ";
    for (int i=0;i<3; i++)
        cout<<dyarr[i]<<"\t";
/*
    delete dyiptr1;
    delete dyiptr2;
    delete[] dyarr;
*/
/*
    cout<<"\n dangling pointer dyiptr1 value = "<<*dyiptr1;
    cout<<"\n dangling pointer dyiptr1 value = "<<*dyiptr2;
*/
/*
    dyiptr1 = nullptr;
    dyiptr2 = nullptr;
    dyarr = nullptr;
    //cout<<"\n  dyiptr1 value after assigning nullptr = "<<*dyiptr1;
    //cout<<"\n dyiptr2 value after assigning nullptr = "<<*dyiptr2;


// */
/*
    if (dyiptr1 != nullptr)
        cout<<"\n  dyiptr1 value after assigning nullptr = "<<*dyiptr1;
    if (!dyiptr2)
        cout<<"\n dyiptr2 contains null value.";
    else
        cout<<"\n dyiptr2 value after assigning nullptr = "<<*dyiptr2;
*/
/*
// printing addresses of array locations:
    cout<<"\n address of dyarr location 0 using &dyarr[0] = "<< &dyarr[0] <<", or dyarr = "<<dyarr;
    cout<<"\n address of dyarr location 0 using &dyarr[1] = "<< &dyarr[1] <<", or dyarr = "<<dyarr+1;
    cout<<"\n address of dyarr location 0 using &dyarr[2] = "<< &dyarr[2] <<", or dyarr = "<<dyarr+2;
*/
}
int main()
{
/*
    //pointersToPointers();
    //ArrayOfpointersToPointers();
*/
/*
   int x=786,y=800;
   int *xptr = &x; int *yptr = nullptr;
   yptr = passingAndReturningPointers(xptr,&y);
   cout<<"\n x = "<<*xptr<<"\n y = "<<*yptr;
*/
    /*
    arrays are always passed as pointers by default, passing by copy of array is not possible in c++.
    when an array is passed by-copy style, it always decays into a pointer of first element in first dimension.
    1D Array: int arr[5] decays to int* arr.
    2D Array: int arr[3][4] decays to int (*arr)[4], which is a pointer to an array of 4 elements.
    3D Array: int arr[2][3][4] decays to int (*arr)[3][4], which is a pointer to a 2D array of 3x4 elements.
    */
/*
    int a1[4]={1,2,3,4}, a1size=4, a2[5]={5,6,7,8,9};
    cout<<"\n inside main function, &a1 (first location) = "<<&a1<<", or a1= "<<a1;
    cout<<"\n inside main function, &a1 + 1 (location?) = "<<&a1 + 1<<", or a1(without decay)= "<<a1 + 1;
    cout<<"\n inside main function, &a2 (first location)= "<<&a2<<", or a2= "<<a2;
    passing1DArrays(a1,a1size,a2);
*/
/*
    int arr[4][3], rows=4,value=1;
      for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        for (int j=0; j<sizeof(arr[0])/sizeof(arr[0][0]); j++)
            arr[i][j] = value++;
    passingMDArrayByCopyStyle(arr,rows);
    passingMDArrayByReferenceStyle(arr);

*/
/*
int* arptr = returningStaticArray();
cout << "Array elements: ";
for (int i = 0; i < 5; i++) {
        cout << arptr[i] << " ";
}
*/
   dynamicMemoryAllocation();
    return 0;
}
