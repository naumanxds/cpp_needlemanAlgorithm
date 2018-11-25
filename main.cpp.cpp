#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
    string str1,str2;
    int diag=0,up=0,side=0,i,j,str1Len,str2Len;

    //===== Sequences Input by the user
    cout<<"== Enter 1st Sequence & press Enter : ";cin>>str1;
    cout<<"== Enter 2nd Sequence & press Enter : ";cin>>str2;cout<<endl<<endl;

    //===== Finding the length of the sequences entered by the user
    str1Len = str1.length();
    str2Len = str2.length();

    //===== Dynamic Array
    int** arr = new int *[str1Len+1];
    for (i=0; i<=str1Len;i++){
        arr[i] = new int[str2Len+1];
    }

    //===== Initializing 1st row and 1st column with indel multiple
    for(i=0;i<=str1Len;i++) {
        arr[i][0]= -2*i;
    }
    for(j=0;j<=str2Len;j++) {
        arr[0][j]= -2*j;
    }

    //===== Filling Matrix
    for(i=1;i<=str1Len;i++){
        for(j=1;j<=str2Len;j++){
            if(str1[i-1] == str2[j-1]){
                diag = arr[i-1][j-1]+10;
            }
            else {
                diag = arr[i-1][j-1]-5;
            }
            up = arr[i-1][j]-2;
            side = arr[i][j-1]-2;
            if(diag>=up && diag>=side){
                arr[i][j]=diag;
            }
            if(up>=diag && up >=side){
                arr[i][j]=up;
            }
            if(side>=diag && side>=up){
                arr[i][j]=side;
            }
        }
    }

    //===== Back tracking
    i=str1Len;j=str2Len;
    for(;i>0 || j>0;){
        if(i==0){
            str1="-"+str1;
            j--;
        }
        else if(j==0){
            str2="-"+str2;
            i--;
        }
        else if(str1[i-1]==str2[j-1] && arr[i][j]==arr[i-1][j-1]+10){
            i--;j--;
        }
        else if(str1[i-1]!=str2[j-1] && arr[i][j]==arr[i-1][j]-2){
            str2.insert(j,"-");
            i--;
        }
        else if(str1[i-1]!=str2[j-1] && arr[i][j]==arr[i][j-1]-2){
            str1.insert(i,"-");
            j--;
        }
        else{
            i--;j--;
        }
    }

    //===== Printing Matrix and Aligned Sequence
    cout<<"\nThe code will show only 1 optimum solution of the Alignment\n\n";
    cout<<"** Scoring Scheme : match = 10 , mismatch = -5 , indel = -2 **\n\n";
    cout<<"=============================================================\n\n\n";

    for(i=0;i<=str1Len;i++){
        for(j=0;j<=str2Len;j++){
            cout <<arr[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
    cout<<"\n==============================================================\n\n\n";
    cout<<"Output Sequence 1 : "<<str1<<endl;
    cout<<"Output Sequence 2 : "<<str2<<endl;

    //===== Deleting Dynamic Array
    for(i=0;i<str1Len+1;i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}
