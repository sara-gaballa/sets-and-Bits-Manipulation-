#include <iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
//part-1
int getBit(int number,int position){
    return (1 &(number >> (position)));
}
int setBit(int number, int position){
    return ((number & ~(1 << position)) | (1 << position));
}
int clearBit(int number, int position){
    return (number & ~(1 << position));
}
int updateBit(int number, int position, bool value){
   if(value == 1){
    setBit(number,position);
   }
   else {
     clearBit( number, position);
   }
}
//part-2
string* print(string arr[],int Size,int solution){
    string arrreturn[Size];
    int j=0;
    for(int i=0;i<Size;i++){
        if(getBit(solution,Size-1-i)==1){
            arrreturn[j]= arr[i];
            cout << arrreturn[j] <<" ";
            j++;
        }
    }
    return arrreturn;
}
string* Union_of_two_sets(string universal[],int Size ,int arrss[],int firstsubset,int secondsubset){
    int solution = arrss[firstsubset]|arrss[secondsubset];
    return print(universal, Size, solution);

}

string* Intersection_of_two_sets(string universal[],int Size ,int arrss[],int firstsubset,int secondsubset){
    int solution = arrss[firstsubset]&arrss[secondsubset];
    return print(universal, Size, solution);

}

string* complement_of_sets(string universal[],int Size ,int arrss[],int subset){
    int solution = ~arrss[subset];
    return print(universal, Size, solution);

}

//part-3
int bits_manipulation(int arr[], int Size){
    int result = 0;
    for(int i =0 ;i < Size; i++)
        result = (result ^ arr[i]);
    return result;
}

int32_t main() {
    cin.tie(0),iostream::sync_with_stdio(0);
    string statement,part_number;
    int number,position;
    cout <<"press (1) for part1 or (2) for part2 or (3) for part3 or (0) for Exit: "<<endl;
    cin>>part_number;

    while(part_number!="0"){

    if(part_number=="1"){

    cout<<"choose{get,set,clear,update,exit}"<<endl;
    cin >> statement;
    while(statement!="exit"){
    cout<<"Enter number and position"<<endl;
    cin >> number;
    cin >> position;
    if(statement=="set"){
    cout << setBit(number,position);}
    else if(statement=="clear"){
    cout << clearBit(number,position);}
    else if(statement=="get"){
    cout << getBit(number,position);}
    else if(statement=="update"){
        cout<<"enter the update value"<<endl;
        bool value;
        cin>> value;
        cout << updateBit(number,position,value);}
    cout<<"\nchoose{get,set,clear,update,exit}"<<endl;
    cin >> statement;
    }

    }


    else if(part_number=="2"){
        int numberofsets,Size=0;
        string Universal_elements;
        string universal[1000],subset[1000];
        cout << "Enter the Universal set elements: " <<endl;
        cin >>Universal_elements;
            while(cin.get()!= '\n'){
                universal[Size]=Universal_elements;
                Size++;
                cin >> Universal_elements;
            }
        universal[Size] = Universal_elements;
        Size++;
        int bits=pow(2,Size)-1;
        cout << "Enter number of subsets: " <<endl;
        cin>>numberofsets;
        int arrss[numberofsets];
        int number_of_sets = numberofsets;
        int sets_number=0;
        arrss[sets_number]=bits;
        sets_number++;
        cout << "Enter the subset elements(if the subset is null enter NULL)" <<endl;
        for (int j = 0; j < numberofsets; j++) {
           arrss[sets_number]=0;
           while(1){
                string set_input;
                cin>>set_input;
                if(set_input!="NULL"){
                    for (int k = 0; k<Size; k++) {
                        if(set_input==universal[k]){
                            arrss[sets_number]=setBit(arrss[sets_number],Size-1-k);
                        break;
                        }
                    }
                }
                else if(set_input=="NULL"){
                    arrss[sets_number]=bits;
                }
            if(cin.get()== '\n'){
                break;
            }
        }
        sets_number++;
        number_of_sets--;
        if(number_of_sets!=0){
        cout << "Enter the next subset elements(if the subset is null enter NULL)" <<endl;}
        }
        cout << "Enter 1 for Union or 2 for intersection or 3 for complement or 0 for exit" <<endl;
        string chose;
        cin >> chose;
        while(chose!="0"){
        if(chose == "1"){
            int firstsubset,secondsubset;
            cout << "Enter number of 2 subsets to get union " <<endl;
            cin >> firstsubset;
            cin >> secondsubset;
            Union_of_two_sets(universal,Size, arrss, firstsubset, secondsubset);
        }

        if(chose == "2"){
            int firstsubset,secondsubset;
            cout << "Enter number of 2 subsets to get intersection " <<endl;
            cin >> firstsubset;
            cin >> secondsubset;
            Intersection_of_two_sets(universal,Size, arrss, firstsubset, secondsubset);
        }

        if(chose == "3"){
            int subset;
            cout << "Enter number of the subset to get the complement " <<endl;
            cin >> subset;
            complement_of_sets(universal, Size , arrss, subset);
        }
        cout << "\nEnter 1 for Union or 2 for intersection or 3 for complement or 0 for exit" <<endl;
        cin >> chose;
        }
}

    else if(part_number=="3"){
        cout << "1 for Enter the elements of array , 0 for exit" <<endl;
        int input;
        cin >> input;
        while(input!=0){
        cout << "Enter the elements of array:" <<endl;
        int arr[1000];
        int elements,i=0;
        cin >>elements;
        while(cin.get()!= '\n'){
            arr[i]=elements;
            i++;
            cin >> elements;
        }
        arr[i]=elements;
        i++;
        cout << "the single number is: " << bits_manipulation(arr, i) << endl;
        cout << "1 for Enter the elements of array , 0 for exit" <<endl;
        cin >> input;
    }

    }
    cout <<"\npress (1) for part1 or (2) for part2 or (3) for part3 or (0) for Exit: "<<endl;
    cin >> part_number;
    }
}

