#include <iostream>
using namespace std;
class HashTable {
private:
    string* table;
    int S;
    int n = 0;
public:

    HashTable(int size)
    {
        S = size;
        n = 0;
        table = new string[S];
        for (int i = 0; i < size; i++)
            table[i] = " ";
    }

    int getHashValue(string s)
    {

        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            sum += c;
        }
        return sum % S;
    }
    bool isEmpty() { return n == 0; }
    bool isFull() { return n == S; }
    double loadFactor()
    {
        return (double)n/S;
     }
    bool insert(string name)
    {
        int index = getHashValue(name);
        int ind = index;
        while (index < S)
        {
            if (table[index] == " ")
            {
                table[index] = name;
                n++;
                return true;

            }
            cout << "Index " << index << " visited.Space not found." << endl;
            index=index+1;
        }
        for (int i = ind - 1; i >= 0; i--)
        {
            if (table[i] == " ")
            {
                table[i] = name;
                n++;
                return true;

            }
            cout << "Index " << i << " visited.Space not found." << endl;
            

        }
        return false;
        
    }
    
    bool search(string name)
    {
        for (int i = 0; i < S; i++)
        {
            if (table[i] == name)
                return true;
        }
        return false;
    }
    bool remove(string name)
    {
        for (int i = 0; i < S; i++)
        {
            if (table[i] == name)
            {
                table[i] = " ";
                n--;
                return true;
            }
        }
        return false;

    }
    void display()
    {
        for (int i = 0; i < S; i++)
        {
            cout << i << ") ";
            if (table[i] != " ")
                cout << table[i] << endl;
            else
                cout << "Empty" << endl;
        }
    }
};

int main()
{
    HashTable H(300);
    cout << "Can BOB be inserted? ";
    cout << H.insert("BOB") << endl;
    cout << "Can OBB be inserted?";
    cout<< H.insert("OBB")<<endl;
    H.display();
    cout<<endl<<H.search("BOB")<<endl;
    cout << "Can be removed? " << H.remove("OBB") << endl;
    H.display();
   cout<<endl<<"Load Factor: " << H.loadFactor();
        return 0;
}

