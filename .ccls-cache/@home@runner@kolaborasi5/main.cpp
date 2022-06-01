#include <iostream>
#include <cmath>
using namespace std;

class kasus{
private:
  int banyak,pilihan,target,low,high,hasil, id[30], telp[30];
  string nama[30], jabatan[30];
  int a,d;
  string b,c;

public:
  void input();
  void output();
  int BinarySearch1(int a[],int target,int low,int high);
  int BinarySearch2(int a[],int target,int low,int high);
  void sortASC();
  void sortDSC();
};

void kasus::input(){
  cout<<"Banyak data : "; cin>>banyak;
  for(int i=0; i<banyak; i++){
    cout<<endl;
    cout<<"Data ke-"<<i+1<<" : "<<endl;
    cout<<"Masukkan ID karyawan : "; cin>>id[i];
    cin.ignore();
    cout<<"\nMasukkan nama Karyawan : "; getline(cin,nama[i]);
    cout<<"\nMasukkan jabatan karyawan : "; getline(cin,jabatan[i]);
    cout<<"\nMasukkan no.telp karyawan : "; cin>>telp[i];
  }
  
}

void kasus::sortASC(){
  for(int i=0; i<banyak; i++){
    for(int j=0; j<banyak-1; j++){
      if(id[j]>id[j+1]){
        //id
        a=id[j];
        id[j]=id[j+1];
        id[j+1]=a;
        //nama
        b=nama[j];
        nama[j]=nama[j+1];
        nama[j+1]=b;
        //jabatan
        c=jabatan[j];
        jabatan[j]=jabatan[j+1];
        jabatan[j+1]=c;
        //telp
        d=telp[j];
        telp[j]=telp[j+1];
        telp[j+1]=d;
      }
    }
  }
}

void kasus::sortDSC(){
  for(int i=0; i<banyak; i++){
    for(int j=0; j<banyak-1; j++){
      if(id[j]<id[j+1]){
        //id
        a=id[j];
        id[j]=id[j+1]; 
        id[j+1]=a;
        //nama
        b=nama[j];
        nama[j]=nama[j+1];
        nama[j+1]=b;
        //jabatan
        c=jabatan[j];
        jabatan[j]=jabatan[j+1];
        jabatan[j+1]=c;
        //telp
        d=telp[j];
        telp[j]=telp[j+1];
        telp[j+1]=d;
      }
    }
  }
}

void kasus::output(){
  cout<<endl;
  cout<<"Pilihan Sorting"<<endl;
  cout<<"1.Ascending"<<endl;
  cout<<"2.Descending"<<endl;
  cout<<"Masukkan pilihan sorting  : ";cin>>pilihan;
  if(pilihan==1){
    sortASC();
  }
  else{
    sortDSC();
  }
  cout<<"\t\t\t\t\t\t\t\t\t\tData Setelah Sorting\t\t\t\t\t\t"<<endl;
  cout<<"|| \t\tID\t\t || \t\tNama\t\t || \t\t Jabatan \t\t || \t\tNo Telp\t\t||"<<endl;
  for(int i=0; i<banyak; i++){
    cout<<"\t\t\t\t"<<id[i]<<"\t\t\t\t"<<nama[i]<<"\t\t\t\t"<<jabatan[i]<<"\t\t\t\t"<<telp[i]<<endl;
  }


  cout<<"Masukkan ID Target  : ";cin>>target;
  low=0;
  high=banyak-1;
  if(pilihan==1){
    hasil=BinarySearch1(id,target,low,high);
  }
  else{
    hasil=BinarySearch2(id,target,low,high);
  }
  if(hasil== -1){
    cout<<"Data Tidak Ditemukan"<<endl;
  }
  else{
    cout<<"Data Ditemukan"<<endl;
    cout<<"||\t\tID\t\t||\t\tNama\t\t||\t\tJabatan\t\t||\t\tNo Telp\t\t||"<<endl;
    cout<<"\t\t\t\t"<<id[hasil]<<"\t\t\t\t"<<nama[hasil]<<"\t\t\t\t"<<jabatan[hasil]<<"\t\t\t\t"<<telp[hasil]<<endl;
  }
}

int kasus::BinarySearch1(int a[],int target,int low,int high){
  while(low<=high){
		int mid = low + (high - low )/2;
		if(a[mid]==target){
			return mid;
		}
		else if(a[mid]<target){
			low = mid + 1;
		}
		else{
			high = mid -1;
		}
	}
	return -1;
}
int kasus::BinarySearch2(int a[],int target,int low,int high){
  while(low<=high){
		int mid = low + (low - high )/2;
		if(a[mid]==target){
			return mid;
		}
		else if(target<a[mid]){
			low = mid + 1;
		}
		else{
			high = mid -1;
		}
	}
	return -1;
}


int main() {
  kasus x;
  x.input();
  x.output();
  return 0;
}