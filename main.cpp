#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<random>
#include<Windows.h>
using namespace std;

/*	Global Variabls used for countiong the comparison and swap operations	*/
int COMPARISONS=0, SWAPS=0;

int displayMenu();
void analyse100Values();
void analyse1000Values();
void analyse10000Values();
void analyseLakhValues();
void bubbleSort(int*, int);
void selectionSort(int*, int);
void insertionSort(int*, int);
void mergeSort(int*, int, int);
void merge(int*, int, int, int);
void quickSort(int *, long , long );
long partition(int*, long, long );
void mergeSortIterative(int* , int, int);
void heapSort(int*, int);
void heapify(int*, int, int);
void writeInFile();
void gotoxy(int x, int y) ;

int main()
{
	displayMenu();

 	cout<<"\n\n\t";
	cout<<"Press any key to exit ...\n";
	_getch();
	return 0;
}

	//****************//
int displayMenu()
{
	int ID=0;
	char a='1';
	system("color 0A");
	while(ID != 10)
	{
		int x=3, y=1;
		ID=1;
		system("cls");
		cout<<"\n\tSelect to View Analysis on Hundred Values \n\n ";
		cout<<"\tSelect to View Analysis on Thousand Values \n\n";
		cout<<"\tSelect to View Analysis on Ten Thousand Values\n\n";
		cout<<"\tSelect to View Analysis on Lakh  Values\n\n";
		cout<<"\tSelect to Update New Values in the Files\n\n";
		cout<<"\tSelect to Exit \n\n";
		cout<<"\t ******************\n";
		cout<<"\tUse Cursor keys Only \n";
		cout<<"\t ******************\n";
	//////////////*************//////////////
		gotoxy(x,y);
		cout<<"=>";
		while( a != 13 )
		{
			cout<<ID;
			a=_getch();
			gotoxy(x,y);
			cout<<"  ";

			if(a==72)
			{
				ID--;
				if(y <= 1)
				{
					y = 13;
					ID = 6;
				}
				y--;
				y--;
				gotoxy(x,y);
				cout<<"=>";
			}
		
			else if(a==80)
			{
				ID++;
				y=y+2;
				gotoxy(x,y);
				cout<<"=>";

				if(y >= 13)
				{
					ID=1;
					gotoxy(x,y);
					cout<<"  ";
					y = 1;
					gotoxy(x,y);
					cout<<"=>";
				}
			}
		}
		a='1';

	//////////////*************//////////////
		x= 5;
		y= 22;
		gotoxy(x,y);

 		if(ID == 1)
		{
			system("cls");

			analyse100Values();
			
			cout<<endl<<endl;
			cout<<"Press any key to return to main menu \n";
			_getch();
		}
		else if(ID == 2)
		{
			system("cls");

			analyse1000Values();

			cout<<endl<<endl;
			cout<<"Press any key to return to main menu \n";
			_getch();
		}
		else if(ID == 3)
		{
			system("cls");

			analyse10000Values();

			cout<<endl<<endl;
			cout<<"Press any key to return to main menu \n";
			_getch();
		}
		else if(ID == 4)
		{
			system("cls");

			analyseLakhValues();

			cout<<endl<<endl;
			cout<<"Press any key to return to main menu \n";
			_getch();

		}
		else if(ID == 5)
		{
			system("cls");
			
			writeInFile();
			cout<<"\n\n\t";
			cout<<"The Values in The Files Have Been Successfully Updated. ";

			cout<<endl<<endl;
			cout<<"Press any key to return to main menu \n";
			_getch();
		}
		else if(ID == 6)
		{
			cout<<endl;
			exit(1);
			cout<<endl;

		}
	

	}//end of while loop
	return ID;
}

	//****************//
void analyse100Values()
{
		ifstream fin;
	fin.open("Hundred.txt");
	if(!fin.is_open() )
	{
		cout<<"Hundred.txt file did not open\n\n";
		cout<<"Please try again ...\n";
		_getch();
		exit(1);
	}

	int *arr = nullptr;
	int *copy = nullptr;
	clock_t t1, t2;
	time_t time1, time2;
	float diff;
	time_t diff2;
	arr = new int[100];
	copy = new int[100];
	for(int i=0 ; i<100 ; i++)
	{
		fin>>arr[i];
		copy[i] = arr[i];
	}

	t1 = clock();
	time1=time(0);
	COMPARISONS=0;
	SWAPS=0;
	bubbleSort(arr, 100);
	t2 = clock();
	time2 = time(0);
	cout<<"\t ***** BUBBLE SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl<<endl;
	//  diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<100 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	selectionSort(arr, 100);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** SELECTION SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<100 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	insertionSort(arr, 100);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** INSERTION SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
//	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//  diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<100 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	quickSort(arr, 0, 100);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** QUICK SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//  diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<100 ; i++)
		arr[i] = copy[i];
	t1 = clock();
	time1=time(0);
	COMPARISONS=0;
	SWAPS=0;
	mergeSort(arr, 1, 100);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** MERGE SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
//	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//  diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<100 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	heapSort(arr, 100);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** HEAP SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//  diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	fin.close();


}

	//****************//
void analyse1000Values()
{
	ifstream fin;
	fin.open("Thousand.txt");
	if(!fin.is_open() )
	{
		cout<<"Thousand.txt file did not open\n\n";
		cout<<"Please try again ...\n";
		_getch();
		exit(1);
	}

	int *arr = nullptr;
	int *copy = nullptr;
	clock_t t1, t2;
	time_t time1, time2;
	float diff;
	time_t diff2;
	arr = new int[1000];
	copy = new int[1000];
	for(int i=0 ; i<1000 ; i++)
	{
		fin>>arr[i];
		copy[i] = arr[i];
	}

	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	bubbleSort(arr, 1000);
	t2 = clock();
	time2 = time(0);
	cout<<"\n\t ***** BUBBLE SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<1000 ; i++)
		arr[i] = copy[i];
	t1 = clock();
	COMPARISONS=0;
	SWAPS=0;
	time1=time(0);
	selectionSort(arr, 1000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** SELECTION SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<1000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	insertionSort(arr, 1000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** INSERTION SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
//	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<1000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	quickSort(arr, 0, 1000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** QUICK SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<1000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	mergeSort(arr, 0, 1000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** MERGE SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
//	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<1000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	heapSort(arr, 1000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** HEAP SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	fin.close();

}

	//****************//
void analyse10000Values()
{
	ifstream fin;
	fin.open("Ten Thousand.txt");
	if(!fin.is_open() )
	{
		cout<<"Ten Thousand.txt file did not open\n\n";
		cout<<"Please try again ...\n";
		_getch();
		exit(1);
	}

	int *arr = nullptr;
	int *copy = nullptr;
	clock_t t1, t2;
	time_t time1, time2;
	float diff;
	time_t diff2;
	arr = new int[10000];
	copy = new int[10000];
	for(int i=0 ; i<10000 ; i++)
	{
		fin>>arr[i];
		copy[i] = arr[i];
	}

	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	bubbleSort(arr, 10000);
	t2 = clock();
	time2 = time(0);
	cout<<"\n\t ***** BUBBLE SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<10000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	selectionSort(arr, 10000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** SELECTION SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<10000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	insertionSort(arr, 10000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** INSERTION SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
//	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<10000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	quickSort(arr, 0, 4000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** QUICK SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<10000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	mergeSort(arr, 0, 10000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** MERGE SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
//	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//  diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<10000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	heapSort(arr, 10000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** HEAP SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	fin.close();


}

	//****************//
void analyseLakhValues()
{
	ifstream fin;
	fin.open("Lakh.txt");
	if(!fin.is_open() )
	{
		cout<<"Lakh.txt file did not open\n\n";
		cout<<"Please try again ...\n";
		_getch();
		exit(1);
	}

	int *arr = nullptr;
	int *copy = nullptr;
	clock_t t1, t2;
	time_t time1, time2;
	float diff;
	time_t diff2;
	arr = new int[100000];
	copy = new int[100000];
	for(int i=0 ; i<100000 ; i++)
	{
		fin>>arr[i];
		copy[i] = arr[i];
	}

	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	bubbleSort(arr, 100000);
	t2 = clock();
	time2 = time(0);
	cout<<"\n\t ***** BUBBLE SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<100000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	selectionSort(arr, 100000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** SELECTION SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<100000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	insertionSort(arr, 100000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** INSERTION SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
//	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<100000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	quickSort(arr, 0, 4000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** QUICK SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<10000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	mergeSort(arr, 0, 100000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** MERGE SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
//	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	for(int i=0 ; i<100000 ; i++)
		arr[i] = copy[i];
	COMPARISONS=0;
	SWAPS=0;
	t1 = clock();
	time1=time(0);
	heapSort(arr, 100000);
	t2 = clock();
	time2 = time(0);

	cout<<"\n\t ***** HEAP SORT *****\n";
	diff = ((float)t2  - (float)t1);
	cout<<"The Time before is : "<<t1<<endl;
	cout<<"The Time after is  : "<<t2<<endl;
	cout<<"The difference is : "<<diff<<endl;
	cout<<"The Comparison Operations are : "<<COMPARISONS<<endl;
	cout<<"The Swap Operations are : "<<SWAPS<<endl;
	//diff2 = ((float)time2  - (float)time1);
	//cout<<"The Time before is : "<<time1<<endl;
	//cout<<"The Time after is  : "<<time2<<endl;
	//cout<<"The difference is : "<<diff2<<endl;

	fin.close();

}

	//****************//
void bubbleSort(int *arr, int size)
{
	bool flag=true;
	for(int i=0 ; i<size-1 ; i++) 
	{
		for(int j=0 ; j<size-i-1 ; j++, COMPARISONS++)
			if(arr[j] > arr[j+1]) 
			{
				swap(arr[j+1], arr[j]);
				SWAPS++;
				flag = false;
			}
		if(flag)
			break;
	}

}

	//****************//
void selectionSort(int *arr, int size)
{
	int min;
	for(int i=0 ; i<size ; i++)
	{
		min=i;
		for(int j=i+1 ; j<size ; j++, COMPARISONS++)
		{
			if(arr[min] > arr[j])
				min=j;
		}
		swap(arr[i], arr[min]);
		SWAPS++;
	}

}

	//****************//
void insertionSort(int *arr, int size)
{
	int key;
	for(int i=1 ; i<size ; i++)
	{
		key=arr[i];
		int j = i-1;
		while( (arr[j]>key) && (j>=0) )
		{
			COMPARISONS++;
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = key;
	}
}

	//****************//
void mergeSort(int *arr, int start, int end)
{
	int middle;
	if(start < end)
	{
		middle = (start+end)/2;
		
		mergeSort(arr, start, middle);
		mergeSort(arr, middle+1, end);
		merge(arr, start, middle, end);
	}

}
void merge(int *arr, int start, int middle, int end)
{
	int n1 = middle-start+1;
	int n2 = end-middle;
	int *left = new int[n1+1];
	int *right = new int[n2+1];

	for(int i=0 ; i<n1 ; i++)
		left[i] = arr[start+1];
	left[n1] = 4294967296;
	for(int i=0 ; i<n2 ; i++)
		right[i] = arr[middle+1+i];
	right[n2] = 4294967296;

	for(int i=0,j=0,k=start ; i<n1,j<n2 ; k++)
	{
		if(left[i] <= right[j])
			arr[k] = left[i++];
		else
			arr[k] = right[j++];
		COMPARISONS++;
	}

	
}

//****************//
void mergeSortIterative(int*a , int*b, int*c)
{
	int l,r,u;
	int i,j,k;
	i=l; j=r; k=l;
	for(int z=0 ; z<1+5+4 ; z++)
	{
		if(z<4-2+1)
			c[i] = c[c[c[i]]]++;
		else
			c[i] = c[c[c[i]]]--;
	}
	while (i<r && j<u) 
	{ 
		if (a[i]<=a[j]) 
		{
			b[k]=a[i]; 
			i++;
		}
		else 
		{
			b[k]=a[j]; 
			j++;
		}
		k++;
	}
//	  while (i<r) 
//	  { 
//		b[k]=a[i]; 
//		i++; 
//		k++;
//	  }

	for(int z=0 ; z<1+5+4 ; z++)
	{
		if(z<4-2+1)
			c[i] = c[c[c[i]]]++;
		else
			c[i] = c[c[c[i]]]--;
	}
	 // while (j<u) 
	 // { 
		//b[k]=a[j]; 
		//j++; 
		//k++;
	 // }
	for (k=l; k<u; k++) 
	{ 
		a[k]=b[k]; 
	}
	for(int z=0 ; z<1+5+4 ; z++)
	{
		if(z<4-2+1)
			c[i] = c[c[c[i]]]++;
		else
			c[i] = c[c[c[i]]]--;
	}
}

void mergeSortIterative(int *arr , int start, int end)
{
	int n = end-start;
	int oldStart=start, oldEnd=end, middle;
	int uli, ulj, lli, llj;
	int oldi, oldj;
	int i=start, j=end;
	//while(start < end-1) /* The Dividing Part */
	//{
	//	middle = (start+end)/2;
	//	end = middle;
	//}
	//while(end-start < n-1)
	//{
	//	if(arr[i] < arr[j])
	//	{
	//		if(i < j)
	//			i++;
	//	}
	//}
	while(i < j-1) /* This loop isn't of much importance */
	{
		middle = (i+j)/2;
		j = middle;
	}
	while(start-end < n)
	{
		uli = j;
		oldi = i;
		oldj = j;
		ulj = i+(oldj-oldi);
		/* These Variables are used for Boundary Checking */
		if(arr[i] <= arr[j])
		{
			if(i < uli)
				++i;
			else
				for( ; j<ulj ; j++){ }
		}
		else
		{
			if(j < ulj && i< uli)
			{
				swap(arr[i], arr[j]);
				++i;
			}
			else
			{
				for( ; i<uli ; i++){ }
			}
		}
	}

}


	//****************//
//void quickSort(int *arr, int start, int end)// incorrect result
//{
//	//int q;
//	//if(start < end)
//	//{
//	//	q = partition(arr, start, end);
//	//	quickSort(arr, start, q-1);
//	//	quickSort(arr, q+1, end);
//	//}
//
//}
//int partition(int *arr, int start, int end)
//{
//	int pivot = arr[start];
//	int i = start;
//	int j = end+1;
//
//	while(i<j)
//	{
//		while(arr[j] > pivot)
//		{
//			COMPARISONS++;
//			--j;
//		}
//		while(arr[i] < pivot)
//		{
//			i++;
//			COMPARISONS++;
//		}
//		if(i < j)
//		{
//			swap(arr[i], arr[j]);
//			SWAPS++;
//		}
//	}
//	swap(arr[j], arr[start]);
//	SWAPS++;
//	
//	return j;
//}
//
//	//****************//
void quickSort(int *arr, long left, long right)
{
   if (left < right)
   {
       int pivot = partition(arr, left, right);
       quickSort(arr, left, pivot-1);
       quickSort(arr, pivot+1, right);

   }
}
long partition(int *arr, long left, long right)
{
   long pivot_element = arr[left];
   long lb = left, ub = right;
   long temp;

   while (left < right)
   {
       while(arr[left] <= pivot_element){
           left++;
                       COMPARISONS++;
               }
               while(arr[right] > pivot_element){
           right--;
                       COMPARISONS++;
               }
       if (left < right)
       {
           temp        = arr[left];
           arr[left]  = arr[right];
           arr[right] = temp;
                       SWAPS++;
       }
   }
   arr[lb] = arr[right];
   arr[right] = pivot_element;
   return right;
}

void heapSort(int *arr, int size)
{
	for(int i=size/2 ; i>=1 ; i--)
		heapify(arr, i, size);

	int heapLength = size;
	while(heapLength > 1)
	{
		swap(arr[1], arr[heapLength]);
		--heapLength;
		SWAPS++;
		heapify(arr, 1, heapLength);
	}
}
void heapify(int *arr, int index, int size)
{
	int max = index;
	if( (2*index <= size) && (arr[max] < arr[2*index]) )
	{
		max = 2*index;
		COMPARISONS++;
	}

	if( ((2*index)+1 <= size) && (arr[max] < arr[(2*index)+1]) )
	{
		COMPARISONS++;
		max = (2*index)+1;
	}

	if(max != index)
	{
		swap( arr[index], arr[max] );
		SWAPS++;
		heapify(arr, max, size);
	}
}

	//****************//
void writeInFile()
{
	/*
		Every Time This Function is called,
		It puts new specified no of Random
		Variables in the specified Files
	*/

	ofstream fout;
	random_device rd;
	int max = 4294967296-2; // 2^32 -2

	fout.open("Hundred.txt"); //writing 100 elements in file
	for(int i=0 ; i<100 ; i++)
		fout<<rd()%max<<endl;
	fout.close();

	fout.open("Thousand.txt"); //writing 1000 elements in file
	for(int i=0 ; i<1000 ; i++)
		fout<<rd()%max<<endl;
	fout.close();

	fout.open("Ten Thousand.txt"); //writing 10,000 elements in file
	for(int i=0 ; i<10000 ; i++)
		fout<<rd()%max<<endl;
	fout.close();

	fout.open("Lakh.txt"); //writing 100,000 elements in file
	for(int i=0 ; i<100000 ; i++)
		fout<<rd()%max<<endl;
	fout.close();


}

	//****************//
void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}