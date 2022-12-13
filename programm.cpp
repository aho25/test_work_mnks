#include <iostream>
#include <iomanip>
#define ARRAY_LENGTH 12
#define ARRAY_DEPTH 2
void print_array (const int arr[][ARRAY_DEPTH]);


using namespace std;

const int space = 4;
const int n = 4;

int
main ()
{
  int count = 2;
  int mArray[ARRAY_LENGTH][ARRAY_DEPTH] = {
    {1, 10}, {2, 11}, {3, 11}, {4, 11}, {5, 11},
    {6, 10}, {7, 11}, {8, 11}, {9, 11}, {10, 11}, {11, 10}

  };

  print_array (mArray);

  for (int i = 0; i < ARRAY_LENGTH; i++)
    {
      if (mArray[i][1] == mArray[i + 1][1] and mArray[i][1] == mArray[i + 2][1] and count != n)	 //ищем равные пары
	{
	  mArray[i + 1][0] = 0;
	  count++;
	}
      else
	{
	  count = 2;
	};
    }
/*  for(int i=0; i<8;i++)
   {
       for (int j=0;j<8;j++)
       {
       cout<<"\n"<<i<<"=>i"<<j<<"=>j"<<mArray[i][j];
       }
   }
*/
//при 3 нет 3 8 
//при 4 нет 3 4 8 9 
//оставить 1ый н-тый и последний отчет
  for (int i = 0; i < ARRAY_LENGTH; i++)	//убрать нулевые вхождения и смещение на позицию i
    {
      if (mArray[i][0] == 0)
	{
	  for (int j = i; j < ARRAY_LENGTH && mArray[j][1] != 0; j++)
	    {
	      mArray[j][0] = mArray[j + 1][0];
	      mArray[j][1] = mArray[j + 1][1];
	    }
	}
    }

  cout << endl;
  print_array (mArray);
  return 0;
}



void
print_array (const int arr[][ARRAY_DEPTH])
{
  for (int i = 0; i < ARRAY_LENGTH; i++)
    {
      if (arr[i][0] != 0)
	{
	  cout << "(" << arr[i][0] << "," << arr[i][1] << ")" << setw (space);
	}
    }

}
