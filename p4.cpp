#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
unsigned long djb2(string str)
{
    const char *ptr = str.c_str();
    unsigned long hash = 5381;
    int c;
    while ((c = *ptr++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}
class Person
{
public:
    string id;
    string firstName;
    string lastName;
    string email;
    string phone;
    string city;
    string state;
    string postalCode;
    Person() {}
    Person(string id_in, string first_in, string last_in, string email_in, string phone_in, string city_in, string state_in, string postal_in)
    {
        id = id_in;
        firstName = first_in;
        lastName = last_in;
        email = email_in;
        phone = phone_in;
        city = city_in;
        state = state_in;
        postalCode = postal_in;
    }
    string GetValueForKey(string key)
    {
        if (key == "Id")
        {
            return id;
        }
        else if (key == "FirstName")
        {
            return firstName;
        }
        else if (key == "LastName")
        {
            return lastName;
        }
        else if (key == "Email")
        {
            return email;
        }
        else if (key == "Phone")
        {
            return phone;
        }
        else if (key == "City")
        {
            return city;
        }
        else if (key == "State")
        {
            return state;
        }
        else if (key == "PostalCode")
        {
            return postalCode;
        }
    }
    // finally, anywhere you were using p->City, use p->GetValueForKey() instead
};
class Entry
{
public:
    string key;
    vector<Person *> persons;
    Entry(string k, Person *p)
    {
        key = k;
        persons.push_back(p);
    }
};
class HashTable
{
public:
    vector<vector<Entry *>> table;
    string key;
    vector<string> headers;
    HashTable(ifstream &infile, int size, string keyIn)
    {
        table = vector<vector<Entry *>>(size);
        key = keyIn;
        string line;
        string token;
        getline(infile, line);
        istringstream iss(line);
        //vector<string> headers = vector<string>();
        headers = vector<string>();
        for (int i = 0; i < 8; i++)
        {
            getline(iss, token, '\t');
            headers.push_back(token);
        }
        Person *p;
        while (getline(infile, line))
        {
            istringstream iss(line);
            p = new Person();
            for (int i = 0; i < 8; i++)
            {
                getline(iss, token, '\t');
                if (headers[i] == "Id")
                {
                    p->id = token;
                }
                else if (headers[i] == "FirstName")
                {
                    p->firstName = token;
                }
                else if (headers[i] == "LastName")
                {
                    p->lastName = token;
                }
                else if (headers[i] == "Email")
                {
                    p->email = token;
                }
                else if (headers[i] == "Phone")
                {
                    p->phone = token;
                }
                else if (headers[i] == "City")
                {
                    p->city = token;
                }
                else if (headers[i] == "State")
                {
                    p->state = token;
                }
                else if (headers[i] == "PostalCode")
                {
                    p->postalCode = token;
                }
            }
            Insert(p);
        }
    }
    void Insert(Person *p)
    {                                                                  //GetValueforKey
        unsigned long i = djb2(p->GetValueForKey(key)) % table.size(); //was p->city
        vector<Entry *> entries = table.at(i);
        for (int j = 0; j < entries.size(); j++)
        {
            if (entries.at(j)->key == p->GetValueForKey(key)) //was p->city
            {
                entries.at(j)->persons.push_back(p);
                return;
            }
        }
        Entry *e = new Entry(p->GetValueForKey(key), p); //was p->city
        table.at(i).push_back(e);
    }
    void Print()
    {
        for (int i = 0; i < table.size(); i++)
        {
            vector<Entry *> entries = table.at(i);
            if (entries.size() > 0)
            {
                cout << i << ": ";
                for (int j = 0; j < entries.size(); j++)
                {
                    Entry *e = entries.at(j);
                    cout << e->key << " (" << e->persons.size() << "),";
                }
                cout << endl;
            }
        }
    }
    void Lookup(string val)
    {
        int i = djb2(val) % table.size();
        if (i >= table.size() || i < 0)
        {
            cout << "No results\n";
            return;
        }
        vector<Entry *> entries = table.at(i);

        if (entries.size() > 0)
        {
            for (int j = 0; j < entries.size(); j++)
            {

                Entry *e = entries.at(j);
                if (e->persons.at(0)->GetValueForKey(key) == val)
                {
                    cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
                    for (int k = 0; k < e->persons.size(); k++)
                    {

                        cout << e->persons.at(k)->GetValueForKey("Id") << ",";
                        cout << e->persons.at(k)->GetValueForKey("FirstName") << ",";
                        cout << e->persons.at(k)->GetValueForKey("LastName") << ",";
                        cout << e->persons.at(k)->GetValueForKey("Email") << ",";
                        cout << e->persons.at(k)->GetValueForKey("Phone") << ",";
                        cout << e->persons.at(k)->GetValueForKey("City") << ",";
                        cout << e->persons.at(k)->GetValueForKey("State") << ",";
                        cout << e->persons.at(k)->GetValueForKey("PostalCode");
                        cout << endl;
                    }
                    return;
                }
            }
        }

        cout << "No results\n";
    }
};

void getVal(istream &is, string &str)
{
    char ch;
    string line;

    is >> ch;
    getline(is, line);

    str = ch + line;
}

bool isValidKey(const string &key)
{
    string validKeys[8] = {"Id", "FirstName", "LastName", "Email", "Phone", "City", "State", "PostalCode"};
    for (int i = 0; i < 8; i++)
    {
        if (key == validKeys[i])
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    //vector<vector<Entry>> table;
    /*Person *p1 = new Person("14", "Desdemona", "Jenk", "djenkd@nationalgeographic.com", "315-832-7856", "Syracuse", "New York", "13224");
    Person *p2 = new Person("14", "Desdemona", "Jenk", "djenkd@nationalgeographic.com", "315-832-7856", "El Paso", "New York", "13224");
    Person *p3 = new Person("14", "Desdemona", "Jenk", "djenkd@nationalgeographic.com", "315-832-7856", "Saint Louis", "New York", "13224");
    Person *p4 = new Person("14", "Desdemona", "Jenk", "djenkd@nationalgeographic.com", "315-832-7856", "Saint Louis", "New York", "13224");
    
    ht.Insert(p1);
    ht.Insert(p2);
    ht.Insert(p3);
    ht.Insert(p4);*/

    //ht.Print();
    if (argc != 4)
    {
        cout << "Usage: ./a.out filename.txt table_size key" << endl;
        return 1;
    }

    string filename = argv[1];
    int tableSize = stoi(argv[2]);
    string key = argv[3];

    //table = vector<Entry>;

    ifstream file(filename);
    if (!file)
    {
        cout << "Unable to open " << filename << endl;
        return 2;
    }

    if (!isValidKey(key))
    {
        cout << "Invalid key: " << key << endl;
        return 3;
    }

    // This is an example of how to retreive the tokens from the input file
    // You will need to modify this to fit your needs to build the hash table
    /*string line, token;
    while (getline(file, line))
    {
        istringstream iss(line);
        while (getline(iss, token, '\t'))
        {
            cout << token << "\t";
        }
        cout << endl;
    }*/
    HashTable ht = HashTable(file, tableSize, key);
    cout << "Commands:" << endl
         << "\tprint" << endl
         << "\tlookup <key>" << endl
         << "\tquit" << endl;
    string cmd, val;
    while (1)
    {
        cout << endl
             << "Enter a command:" << endl;
        cin >> cmd;
        if (cmd == "quit")
        {
            break;
        }
        else if (cmd == "print")
        {
            ht.Print();
        }
        else if (cmd == "lookup")
        {
            getVal(cin, val);
            ht.Lookup(val);
        }
        else
        {
            getline(cin, val);
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}