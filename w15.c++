#include<iostream>
using namespace std;
class DynamicA
{
    int size;
    int *array;
    int capicity;
    // Resize function
    void resize()
        {
            int *temp;
            if(size == capicity)
            {
             temp = new int[2*capicity];
              
            }
            for(int i=0; i<size; i++)
            {
                temp[i] = array[i];
            }
            capicity = 2*capicity;
            delete []array;
            array = temp;  // current array hoga vo ab point  krega because function ktm ho jyaga to pointer destroy ho jyaga 
        }
public:
        ~DynamicA()// Destructor
        {
            delete []array;
            size = 0;
            capicity = 0;
        }
        DynamicA() // Constructor 
        {
            array = new int[1];
            size = 0;
            capicity = 1;
        }
        
        void Insert_Element(int value)   // insert Element in Array
        {
            if(size == capicity )
            {
              resize();
            }
              array[size] = value;
              size++;
        }
        void Show_Data()  // Show our Data
        {
            for(int i=0; i<size; i++)
            {
                cout<<array[i]<<" ";
            }
            cout<<"\nSize is "<<size;
            cout<<"\nCapicity is "<<capicity;
            cout<<"\n";
        }
        void Insert_shift(int index,int value)  // shift element 
        {
            if(size == capicity )
              resize();
            for(int i=size; i>index; i--)
            {
                array[i] = array[i-1]; 
            }
            array[index] = value;
            size++;
        }
        void Search_Element(int element)   // Search a number 
        {
            int coun;
            for(int i=0; i<size; i++)
            {
                if(array[i] == element)
                {
                    coun = 1;
                }
            }
            if(coun==1)
            cout<<"\nElement Found Sucess ";
            else 
            cout<<"\nElement Not Found ";
        }
        void Delet(int index)   // Delete a Element 
        { 
            for(int i=index; i<=size; i++)
            {
                 array [i] = array[i+1]; // yeh ye ho reha hai array[i] = array[i+1] mltb phlea vale index ko bhul jau or new index assign kro
            }
            size--;
        }
        void Shirnkto_fit()   // Srink and fit 
        {
            int *temp = new int[size]; 
            for(int i=0; i<size; i++)
            {
                temp[i] = array[i] ;
            }
            delete []array;
            array = temp;
            capicity = size ;
        }
        int at_(int index)
        {
           if(index<size)
           {
            return  array[index];
           }
           return -1;
        }
};
int main()
{
    DynamicA d1;
    d1.Insert_Element(10);
    d1.Insert_Element(20);
    d1.Insert_Element(40);
    d1.Insert_Element(30);
    d1.Insert_Element(50);
    d1.Insert_Element(60);

    d1.Show_Data();
    d1.Insert_shift(3,22);
    d1.Show_Data();
    d1.Delet(1);
    d1.Show_Data();
    d1.Search_Element(50);
    d1.Shirnkto_fit();
    d1.Show_Data();
    cout<<"\nIndex value is "<<d1.at_(2);
}