#include <iostream>
#include <fstream>

using namespace std;
int n, m;

struct Link
{
    double data;
    Link* next;
};

double* readFromFile(const char* fileName, int& count)
{
    Link* first = 0;
    Link* last = 0;
    Link* link;
    ifstream in(fileName);
    double d;
    count = 0;
    while (in >> d)
    {
        count++;
        link = new Link;
        link->data = d;
        link->next = 0;
        if (last == 0)
        {
            first = last = link;
        }
        else
        {
            last->next = link;
        }
        last = link;
    }
    double* arr = new double[count];
    link = first;
    for (int i = 0; i < count; i++)
    {
        arr[i] = link->data;
        link = link->next;
    }
    while (first)
    {
        link = first;
        first = first->next;
        delete link;
    }
    return arr;
}

void outToFile(const char* filename, double* arr, int count)
{
    ofstream out(filename);
    for (int i = 0; i <= count - 1; i++)
    {
        out << arr[i] << " ";
    }
}

void readFile()
{
    std::ifstream fin("data.txt");
    int val = 0, rows = 0, cols = 0, numItems = 0;

    while (fin.peek() != '\n' && fin >> val)
    {
        cout << val << ' ';
        ++numItems;
    }
    cols = numItems;// # of columns found

    cout << '\n';
    while (fin >> val)
    {
        ++numItems;
        cout << val << ' ';
        if (numItems % cols == 0) cout << '\n';
    }
    rows = numItems / cols;
    //cout << "rows = " << rows << ", cols = " << cols << '\n';
    n = rows;
    m = cols;
}

int main()
{

    int count = 0;
 

    readFile();
   // cout << "put the x and y: \n";
   // cin >> n >> m;
    //n++, m++;
    int* array = new int[n];
   // cout << "put varabiles: \n";


    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
    }

    double* arr = readFromFile("data.txt", count);
    





    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i * m + j] << "\n";
             a[i][j] = arr[i * m + j];
             arr[i * m + j] = 0;
             cout << a[i][j] << " " << i << " " << j << "\n";
        }
    }

    

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            a[i][j] = abs(a[i][j]);
        }
    }


    for (int i = 0 ; i < n; i++)
    {
        bool first = true;
        for (int j = 0, minj = a[i][0] ; j < m; j++)
        {
            if (a[i][j] < minj || first == true)
            {
                if (first)
                {
                    first = false;
                }
                minj = a[i][j];
                array[i] = minj;
                arr[i] = minj;
                cout << arr[i] << " here boi \n";
            }
        }
    }
    // cout << arr[0] << " <--- this one 0 ";
    // cout << arr[1] << " <--- this one 1";

    // Deallocation:
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;


    for(int i = 0; i < n; i++)
    {
        cout << array[i] << "\n";

    }


    delete[] array;



    cout << count << " here";
    outToFile("results.txt", arr, count);
    delete[] arr;


    system("pause");
    return 0;
}