#include <iostream>
#include <fstream>
using namespace std;
struct Huff
{
    int data;
    Huff *left, *right;
};
Huff *createNode(int data);
int search(int arr[], int strt, int end, int value);
int *key(int in[], int level[], int size_in, int size_level)
{
    int *newArr = new int[size_in];
    int curr = 0;
    for (int i = 0; i < size_level; i++)
    {

        if (search(in, 0, size_in - 1, level[i]) != -1)
        {
            newArr[curr] = level[i];
            curr++;
        }
    }
    return newArr;
}
Huff *create(int in[], int level[], int inStrt,
             int inEnd, int size)
{

    if (inStrt > inEnd)
        return NULL;

    Huff *node = createNode(level[0]);

    if (inStrt == inEnd)
        return node;

    int iIndex = search(in, inStrt, inEnd, node->data);
    int *newleft = key(in, level, iIndex, size);
    int *newRight = key(in + iIndex + 1, level, size - 1, size);
    node->left = create(in, newleft, inStrt, iIndex - 1, iIndex - inStrt);
    node->right = create(in, newRight, iIndex + 1, inEnd, inEnd - iIndex);
    delete[] newleft;
    delete[] newRight;
    return node;
}

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Huff *createNode(int data)
{
    Huff *node = new Huff();
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

string decode(Huff *root, string eData)
{
    Huff *cur = root;
    string decoded = "";
    for (int i = 0; i < eData.size(); i++)
    {

        if (eData[i] == '0')
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }

        if (cur->left == NULL && cur->right == NULL)
        {
            decoded += (char)cur->data;
            cur = root;
        }
    }
    return decoded;
}

int main(int argc, char *argv[])
{

    ifstream inorder;
    int data;
    inorder.open(argv[1]);

    int inLen = 0;
    int inArr[1000];
    while (inorder >> data)
    {
        inArr[inLen] = data;
        inLen++;
    }

    inorder.close();
    ifstream level;

    level.open(argv[2]);

    int len = 0;
    int arr[1000];
    while (level >> data)
    {
        arr[len++] = data;
    }
    level.close();
    Huff *root = create(inArr, arr, 0, inLen - 1, inLen);
    ifstream encode;
    string tData, eData = "";
    encode.open(argv[3]);
    string decoded;
    while (encode >> tData)
    {

        eData += tData;
    }

    decoded = decode(root, eData);
    cout << decoded;
    return 0;
}