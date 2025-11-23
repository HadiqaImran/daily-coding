#include <iostream>
#include <cstdlib>
using namespace std;
class HashTable {
private:
    int* table;
    int S;
public:
    ~HashTable() { delete[] table; }

    HashTable(int value)
    {
        S = value;
        table = new int[S];
        for (int i = 0; i < S; i++)
            table[i] = -1;
    }
    int Hash(int x)
    {
        return x % S;
    }

    bool insert(int v)
    {
        int index = Hash(v);

        if (table[index] == -1)
        {
            table[index] = v;
            return true;
        }


        return false;

    }

};
int getRandomNumber(int start, int end) {
    return rand() % (end - start + 1) + start;
}

int experiment(int s)
{
    int count = 0;
    HashTable H(s);
    bool x = true;
    while (x == true)
    {
        x = H.insert(getRandomNumber(1, 100));
        if (x == false) break;
        count++;
    }
    return count;

}

int main()
{
    srand(static_cast<unsigned>(time(0))); // seed random generator
    const int numExperiments = 50;
    cout << "Table Size\tAverage Inserted\n";
    cout << "-----------\t----------------\n";
    // Run experiments for table sizes 10, 20, 30, ..., 100
    for (int S = 10; S <= 100; S += 10)
    {
        double totalInserted = 0.0;
        for (int i = 0; i < numExperiments; i++)

            totalInserted += experiment(S);
        double averageInserted = totalInserted / numExperiments;
        cout << S << "\t\t" << averageInserted << endl;


    }
    return 0;
}