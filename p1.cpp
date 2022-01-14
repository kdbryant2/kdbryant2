#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>
using namespace std;
int w ;
void Print(string data[5000][50], int row, int col);
void cols(string data[5000][50], int col);
void search_cols(string data[5000][50], int row, int col, string col_name, string value);
void printRow(string data[5000][50],int row_num,int col){
    for(int i = 0 ; i < col ; i++){
        cout<<setw(w)<<data[row_num][i];
    }
    cout<<endl;
}
void min(string data[5000][50], int row, int col, string col_name);
void max(string data[5000][50], int row, int col, string col_name);
void Average(string data[5000][50], int row, int col, string col_name);
int main(int argc, char* argv[]){

    if (argc != 3) {
        cout << "Usage: ./a database.csv #col_width"<< endl;
        exit(0);
    }

    fstream Input;
    Input.open(argv[1]);
    //Input.open(argv[1],ios::in);
    string line;
    string data[5000][50];
    int row=0,col;

    if (!Input.is_open()) {
      cout << "Failed to open \"" << argv[1] << "\"" << endl;
      return 0;
   }

 while(getline(Input,line)){
        col = 0;
        stringstream ss(line);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        data[row][col]= substr;
        col++;
    }

        row++;
 }

w = atoi(argv[2]);
string UserInput = "";
while(UserInput!="quit"){
    cout<<"Enter a command or \"help\" for a command list:\n";

    getline(cin,UserInput);
    string fun;
    stringstream ss(UserInput);
    getline(ss,fun,' ');
    if(fun=="help"){
       cout<<"command list:\n        print\n        cols\n        search *|col_name val\n        min col_name\n        max col_name\n        avg col_name\n";
    }
    else if(fun =="quit"){
       exit(0);
    }
    else if(fun=="print"){
      Print(data,row,col);
    }
    else if(fun=="cols"){
       cols(data,col);


    }
    else if(fun=="avg"){
        
          getline(ss,fun);
          if(fun[0]=='\"'){
              fun = fun.substr(1,fun.length()-2);
          }
            Average(data,row,col,fun);
    }
        else if(fun=="min"){
       
          getline(ss,fun);
             if(fun[0]=='\"'){
              fun = fun.substr(1,fun.length()-2);
          }
        min(data,row,col,fun);
    }
        else if(fun=="max"){
         getline(ss,fun);
            if(fun[0]=='\"'){
              fun = fun.substr(1,fun.length()-2);
          }
        max(data,row,col,fun);
 }
 else if(fun=="search"){
            string word,val;
     getline(ss,fun);
     stringstream ss(fun);


     if(fun[0]=='\"'){
     

          getline(ss,word,'\"');
        getline(ss,word,'\"');

        getline(ss,val,' ');
        getline(ss,val);
         if(val[0]=='\"'){
              val = val.substr(1,val.length()-2);
          }
        
    }
    else{
        getline(ss,word,' ');
         getline(ss,val);
            if(val[0]=='\"'){
              val = val.substr(1,val.length()-2);
          }
         
    }
   
    search_cols(data,row,col,word,val);
    }
else{
    cout<<"Invalid command\n";
    }
}
    return 0;
} 
void Print(string data[5000][50], int row, int col){
 for(int i = 0 ; i < row ; i++){
       for(int j = 0 ; j < col ; j++){
           cout<<setw(w)<<data[i][j];
       }
       cout<<endl;
   }
}
void cols(string data[5000][50], int col) {
    for (int i = 0; i < col; i++) {
        cout << data[0][i] <<endl;
    }
}
void search_cols(string data[5000][50], int row, int col, string col_name, string value) {
    if(col_name == "*"){
       int flag = 0;
        for(int j = 1 ; j < row ; j++){
            for(int i = 0 ; i < col ; i++){
        if(data[j][i]==value){
             if(flag==0){
                printRow(data,0,col);
            }
        flag = 1;
          printRow(data,j,col);
          break;
        }
    }}
    if(flag==0) cout<<"No results\n";
    return;
    }
    int i ;
    for (i = 0; i < col; i++) {
        if (data[0][i] ==col_name ){
            break;
        }
    }
    if(i==col){
        cout<<"Invalid column \""<<col_name<<"\"\n";
        return;
    }
    int flag = 0;
    for(int j = 1 ; j < row ; j++){
        if(data[j][i]==value){
            if(flag==0){
                printRow(data,0,col);
            }
            flag = 1;
          printRow(data,j,col);
        
        }
    }
    if(flag == 0) cout<<"No results\n";
}

void min(string data[5000][50], int row, int col, string col_name){

int ind;
for(ind = 0 ; ind< col ; ind++){
    if(data[0][ind]==col_name){
        break;
    }
}
  if(ind==col){
        cout<<"Invalid column \""<<col_name<<"\"\n";
        return;
    }
double min = 10000;
for(int i = 1 ; i < row ; i++){
    if(data[i][ind]=="") break;
    if(min>stof(data[i][ind])) min = stof(data[i][ind]);
}
if(min==10000){
   cout<<"The min for col \""<<col_name<<"\" = N/A"<<endl;
}
else cout<<"The min for col \""<<col_name<<"\" = "<<min<<endl;

}

void max(string data[5000][50], int row, int col, string col_name){

int ind;
for(ind = 0 ; ind< col ; ind++){
    if(data[0][ind]==col_name){
        break;
    }
}
  if(ind==col){
        cout<<"Invalid column \""<<col_name<<"\"\n";
        return;
    }
double min = -10000;
for(int i = 1 ; i < row ; i++){
    if(data[i][ind]=="") break;
    if(min<stof(data[i][ind])) min = stof(data[i][ind]);
}
if(min==-10000){
    cout<<"The max for col \""<<col_name<<"\" = N/A"<<endl;
}
else cout<<"The max for col \""<<col_name<<"\" = "<<min<<endl;

}

void Average(string data[5000][50], int row, int col, string col_name){

int ind;
for(ind = 0 ; ind< col ; ind++){
    if(data[0][ind]==col_name){
        break;
    }
}
  if(ind==col){
        cout<<"Invalid column \""<<col_name<<"\"\n";
        return;
    }
float sum = 0;
int num = 0;
for(int i = 1 ; i < row ; i++){

        if(data[i][ind]!="")  {
            sum = sum + stof(data[i][ind]);
            num++;
        }
}
if(num==0){
    cout<<"The avg for col \""<<col_name<<"\" = N/A"<<endl;
}

else cout<<"The avg for col \""<<col_name<<"\" = "<<sum/num<<endl;
}