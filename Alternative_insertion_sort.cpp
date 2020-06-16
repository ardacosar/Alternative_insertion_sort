#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct MyArray{
	
	int *array;
	
	int getSize()
	{ return size; }
	
	void controlFirstTenArrayData()
	{
		for(int i = 0; i < 10; i++)
		{
			cout<<array[i]<< " ";
		}
		cout<<" | First Ten Data"<<endl;
	}
	
	void controlLastTenArrayData()
	{
		for(int i = 10; i > 0; i--)
		{
			cout<<array[size - i]<< " ";
		}
		cout<<" | Last Ten Data"<<endl;
	}
	
	MyArray(int size_)
	{
		size = size_;
		array = new int[size];
	}
	
	private:
	int size;
	
};

void fillArrayWithRandomData(MyArray );
void processTimeCalculator(MyArray , char* );
int* insertData(MyArray , int , int );
int* insertionSort(MyArray );

int main()
{
	srand(time(NULL));
	
	MyArray array1(1000),array2(5000),array3(10000);
	
	fillArrayWithRandomData(array1);
	fillArrayWithRandomData(array2);
	fillArrayWithRandomData(array3);

	processTimeCalculator(array1, "Insertion Sort");  // 0.001
	processTimeCalculator(array2, "Insertion Sort");  // 0.036
	processTimeCalculator(array3, "Insertion Sort");  // 0.137

}
void fillArrayWithRandomData(MyArray ar)
{
	int length = ar.getSize();
	for (int i = 0; i < length ; i++)
	{
		ar.array[i] = rand()% 10000;
	}
}


void processTimeCalculator(MyArray ar,char* method)
{
	clock_t start, end;

	start = clock();
	ar.array = insertionSort(ar);
	end = clock();

	cout << method << " - " << ar.getSize() << " data : " << (float)(end - start) / CLOCKS_PER_SEC << "\n\n";
	ar.controlFirstTenArrayData();
	ar.controlLastTenArrayData();
	cout << "----------------------------------------------------------------" << "\n\n";
}

int* insertData(MyArray ar, int dataToBeMoved, int placeToMove)
{
	int length = ar.getSize();
	int j = 1;
	int *tmp = new int[length];
	
	for(int i = 0; i < placeToMove; i++)
	{
		tmp[i] = ar.array[i];
	}
	
	tmp[placeToMove] = ar.array[dataToBeMoved];
	
	for(int i = placeToMove + 1; i < length; i++)
	{
		if(i == dataToBeMoved + 1)
		{ j=0; }
		tmp[i] = ar.array[i-j];
	}
	ar.array = tmp;
	return tmp;
}
int*  insertionSort(MyArray ar)
{
	int length = ar.getSize();
	int index, i, j;
	for (i = 1; i < length; i++) // Choose pivot
	{
		index = i;
		for (j = i-1; j >= 0; j--) // Find index that has more value then pivot has
		{

			if (ar.array[i] < ar.array[j])
			{
				index = j;
			}
	
		}
		if(i != index)
		{ ar.array = insertData(ar, i, index); }
	}
	return ar.array;
}
