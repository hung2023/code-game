#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
using namespace std;

void game_keo_bua_bao ();
char a[3][3]={'0','1','2','3','4','5','6','7','8'};
int x,y;
char nguoichoiX = 'X';
char nguoichoiO = 'O';
/*
a00 a01 a02
a10 a11 a12
a20 a21 a22
*/
char  ktra(){
	if(a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == 'X'||
	   a[1][0] == 'X' && a[1][1] == 'X' && a[1][2] == 'X'||
	   a[2][0] == 'X' && a[2][1] == 'X' && a[2][2] == 'X'||
	   /*hang ngang */
	   a[0][0] == 'X' && a[1][0] == 'X' && a[2][0] == 'X'||
	   a[0][1] == 'X' && a[1][1] == 'X' && a[2][1] == 'X'||
	   a[0][2] == 'X' && a[1][2] == 'X' && a[2][2] == 'X'||
	   /* hang doc*/
	   a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X'||
	   a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == 'X'
	   /* duong cheo*/){
	   	return 'X';
	}
	else if(a[0][0] == 'O' && a[0][1] == 'O' && a[0][2] == 'O'||
	   a[1][0] == 'O' && a[1][1] == 'O' && a[1][2] == 'O'||
	   a[2][0] == 'O' && a[2][1] == 'O' && a[2][2] == 'O'||
	   /*hang ngang */
	   a[0][0] == 'O' && a[1][0] == 'O' && a[2][0] == 'O'||
	   a[0][1] == 'O' && a[1][1] == 'O' && a[2][1] == 'O'||
	   a[0][2] == 'O' && a[1][2] == 'O' && a[2][2] == 'O'||
	   /* hang doc*/
	   a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O'||
	   a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == 'O'
	   /* duong cheo*/){
	   	return 'O';
	   }
	return 'hoa';
}

void vebanco(){
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ;j++){
			cout<<a[i][j]<<"  ";
		}
		cout<<"\n\n";
	}
}

void thayX(){
	cout<<"nhap vi tri tuong ung voi so ma ban muon danh: ";
	cin>>x;
	if(x <= 2){
		for(int i = 0 ; i <= 2 ;i++){
			if(x == i){
				a[0][i] = nguoichoiX;
			}
		}
	}
	else if(x <= 5 && x >= 3){
		for(int i = 0 ; i <= 2 ;i++){
			if(x - 3 == i){
				a[1][i] = nguoichoiX;
			}
		}
	}
	else if(x <= 8 && x >= 6){
		for(int i = 0 ; i <= 2 ;i++){
			if(x - 6 == i){
				a[2][i] = nguoichoiX;
			}
		}
	}
}
void thayO(){
	cout<<"nhap vi tri tuong ung voi so ma ban muon danh: ";
	cin>>y;
	if(y <= 2){
		for(int i = 0 ; i <= 2 ;i++){
			if(y  == i){
				a[0][i] = nguoichoiO;
			}
		}
	}
	else if(y <= 5 && y >= 3){
		for(int i = 0 ; i <= 2 ;i++){
			if(y - 3 == i){
				a[1][i] = nguoichoiO;
			}
		}
	}
	else if(y <= 8 && y >= 6){
		for(int i = 0 ; i <= 2 ;i++){
			if(y - 6 == i){
				a[2][i] = nguoichoiO;
			}
		}
	}
}

int tim_ng_thang(){
	int b;
	if(ktra() == 'X'){
			cout<<"\nX da thang!\n";
			b = 10;
		}
		else if(ktra() == 'O'){
			cout<<"\nO da thang";b = 10;
		}
		else if(ktra() == 'Hoa'){
			cout<<"Hoa!";b = 10;
		}
	return b;
}

void game_co_caro (){
	int b ,c;
		vebanco();
	while(c != 0){	
		while(b = 1){
			thayX();
			vebanco();
			if(tim_ng_thang() == 10) break;
			thayO();
			vebanco();
			if(tim_ng_thang() == 10) break;
		}
		cout<<"0:thoat  1:chuyen sang keo bua bao 2:choi tiep \nLua chon cua ban: ";
		cin>>c;
		if(c == 1) game_keo_bua_bao ();
	}
}
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
using namespace std;

// 1 :keo 2:bua 3:bao
void maytinh(int &maytinh1){
	srand((int)time(0));
	maytinh1 = rand()%2;
}
void xuli(int a,int &maytinh1){
	switch(a){
		case 0:	break;
		case 2:
			cout<<"ban:bua\n";
			switch(maytinh1){
				case 0:
					cout<<"may tinh:keo"<<"\nban da thang!";
				break;
				case 1:
					cout<<"may tinh:bua"<<"\nHoa!";
				break;
				case 2:
					cout<<"may tinh:bao"<<"\nban thua!";
				break;
		}
		break;
		case 1:
			cout<<"ban:keo\n";
			switch(maytinh1){
				case 0:
					cout<<"may tinh:keo"<<"\nHoa!";
				break;
				case 1:
					cout<<"may tinh:bua"<<"\nban thua!";
				break;
				case 2:
					cout<<"may tinh:bao"<<"\nban da thang!";
				break;
			}
			break;
		case 3:
			cout<<"ban:bao\n";
			switch(maytinh1){
				case 0:
				cout<<"may tinh:keo"<<"\nban thua!";
				break;
				case 1:
					cout<<"may tinh:bua"<<"\nban da thang!";
				break;
				case 2:
					cout<<"may tinh:bao"<<"\nHoa!";
				break;
			}
		break;
		case 4:game_co_caro ();break;
			
		default : cout<<"Khong hop le,vui long nhap lai!"; break;
	}
}
void game_keo_bua_bao (){
	int  a;
	int maytinh1;
	cout<<"1:keo  2:bua  3:bao  0:thoat  4:chuyen sang tro co caro";
	while(a != 0){
		cout<<"\nlua chon cua ban: ";
		cin>>a;
		maytinh(maytinh1);
		xuli(a ,maytinh1);
		cout<<"\n\n";
	}

}
main(){
	int luachon;
	cout<<"0: thoat  1: co caro  2:keo bua bao \n Nhap lua chon cua ban: ";
	while(luachon != 0){
			cin>>luachon;
		switch(luachon){
			case 0:break;
			case 1:
				game_co_caro ();
			break;
			case 2:
				game_keo_bua_bao ();
			break;
		}
		
	}
}

