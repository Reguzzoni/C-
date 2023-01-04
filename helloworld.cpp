// Created by:  Amdrea Reguzzoni
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include <cmath>


void callExternalFunction()
{
    std::cout << "This is an external function" << std::endl;
}

int callExternalFunctionWhichReturnInt()
{
    return 1;
}

int callExternalFunctionWhichReturnIntWithParameter(int param1, int param2)
{
    return param1 + param2;
}

int sumFunction()
{
    int a, b, sum;
    std::cout << "Please, insert a number" << std::endl;
    std::cin >> a;
    std::cin >> b;
                
    sum = a + b;
    std::cout << sum << std::endl;
    return sum;
}

void test1() {
    int N;
    std::cout << "Hello World 2" << std::endl;
    std::cout << "Please, insert a number" << std::endl;
    std::cin >> N;

    std::cout << "The number is: " << N << std::endl;

    callExternalFunction();
    int result = callExternalFunctionWhichReturnInt();
    std::cout << "The result is: " << result << std::endl;

    int result2 = callExternalFunctionWhichReturnIntWithParameter(1, 2);
    std::cout << "The result2 is: " << result2 << std::endl;
}

int calculateCircleArea(int r) 
{
    return 3.14 * r * r;
} 

void duplicateByReference(int &a)
{
    a = a * 2;
}

void duplicateByValue(int a)
{
    a = a * 2;
}

int divide (int a, int b=2)
{
    int r;
    r=a/b;
        std::cout << "Divide Result " << r << std::endl;
    return (r);
}

void referenceVsPointer() 
{
    int firstvalue, secondvalue;
    int * mypointer;

    mypointer = &firstvalue;
    //mypointer = 10;
    *mypointer = 10;
    mypointer = &secondvalue;
    *mypointer = 20;
    std::cout << "firstvalue is " << firstvalue << '\n';
    std::cout << "secondvalue is " << secondvalue << '\n';
}

void referenceVsPointer2() 
{
    int numbers[5];
    int * p;
    p = numbers;  *p = 10;
    p++;  *p = 20;
    p = &numbers[2];  *p = 30;
    p = numbers + 3;  *p = 40;
    p = numbers;  *(p+4) = 50;
    for (int n=0; n<5; n++)
       std::cout << numbers[n] << ", ";

    int b = 5;
    // assigned the reference to p (it will become 6)
    //p = &b;

    // assigned value of cell p to 5 (it will stay 5)
    //*p = b;

    b++;

    std::cout << "p is " << p << '\n';
    std::cout << "&b is " << &b << '\n';
    std::cout << "*p is " << *p << '\n';
    std::cout << "b is " << b << '\n';

}

void staticVsDynamicMemoryAllocation()
{
    int * p;
    p = new int;
    *p = 5;
    std::cout << *p << '\n';
    delete p;
}


struct movies_t {
  string title;
  int year;
} mine, yours;

void printmovie (movies_t movie);

void pointerToStruct() {
    string mystr;

    movies_t amovie;
    movies_t * pmovie;
    pmovie = &amovie;

    cout << "Enter title: ";
    getline (cin, pmovie->title);
    cout << "Enter year: ";
    getline (cin, mystr);
    (stringstream) mystr >> pmovie->year;

    cout << "\nYou have entered:\n";
    cout << pmovie->title;
    cout << " (" << pmovie->year << ")\n";
}


void esercizio4() {
    int A[10], B[10];
    int p, x=0; 
    for (int i=0; i<=9; i++){  //legge l'array
        cin >> A[i];
    }
    for (int i=0; i<=9; i++){ //pongo uguali a 0 le componenti di B
        B[i]=0;
    }
    do {
        cout << "Inserisci un numero intero p positivo= ";
        cin >> p;
    } while (p<0);
    do {
        p=p-10;
    }while (p>0);
    p=p-1;
    for (int i=0; i<=9; i++){
        cout << "result into " << i << " " << p << " " << A[9-(p-i)] << endl;                             //questo sacro ciclo  per fare lo shift
        if (A[9-(p-i)]%10<=10){    //prende gli ultimi p numeri e li fa partire da 0
            B[i]=A[((9-(p-i)))%10]; //in questo caso 10-p(p=6)=4
        }
    }
    for (int j=0; j<=9; j++){  //restituisce l'array shiftato
        cout << B[j] << " ";
    }
    cout << endl;
}

int main()
{
    //test1();
    //sumFunction(4,5);
    //calculateCircleArea(5);

    /*
    int a = 5;
    int b = 5;
    duplicateByReference(a);
    std::cout << "The value of a is: " << a << std::endl;

    duplicateByValue(b);
    std::cout << "The value of b is: " << b << std::endl;
    */

    //divide(12);

    //referenceVsPointer2();
    //staticVsDynamicMemoryAllocation();

    //testMovie();
    
    /*string mystr;

    mine.title = "2001 A Space Odyssey";
    mine.year = 1968;

    cout << "Enter title: ";
    getline (cin,yours.title);
    cout << "Enter year: ";
    getline (cin,mystr);
    stringstream(mystr) >> yours.year;

    cout << "My favorite movie is:\n ";
    printmovie (mine);
    cout << "And yours is:\n ";
    printmovie (yours);

    */

    //pointerToStruct();
    esercizio4();
    return 0;
} 

void printmovie (movies_t movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}

