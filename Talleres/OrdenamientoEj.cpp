#include<iostream>
using namespace std;
//ordenamiento de arrays
void ordBur(int arr[],int n){
    for(int i=0; i<n-1;i++){
        for(int j=0;j<n-1;j++){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
void vectOrd(int arr[],int tamanio){
    for (int i=0;i<tamanio;i++){
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}
int main(){
    int arr[]={7,2,5,3,5,6,1,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"el vector original es: "<<" ";
    vectOrd(arr,n);
    ordBur(arr,n);
    cout<<"el vector ordenado es: "<<" ";
    vectOrd(arr,n);
    return 0;
}