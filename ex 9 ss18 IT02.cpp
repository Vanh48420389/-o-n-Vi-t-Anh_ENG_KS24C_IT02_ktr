#include  <stdio.h>
#include  <string.h>

int main(){
	int choice;
	int phanTu=5;
	int viTri;
	struct Dish{
	int id ;
	char name[100]; 
	int price;	
	};
	struct Dish menu[100]={
	{1,"cha ca", 12},
	{2,"cha muc", 60},
	{3,"ca loc",20},
	{4,"ca chep",30},
	{5,"cha ruoi",200},
	};
	do{
		printf("1.In ra cac phan tu co trong menu\n");
		printf("2.Them 1 phan tu vao vi tri chi dinh\n");
		printf("3.Sua 1 phan tu o vi tri chi dinh \n");
		printf("4.Xoa 1 phan tu o vi tri chi dinh \n");
		printf("5.Sap xep cac phan tu\n");
		printf("6.Tim kiem phan tu theo name nhap vao \n");
		printf("7.Thoat Chuong Trinh\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
			for (int i = 0; i < phanTu; i++) {
			printf(" %d.%s:%d\n", menu[i].id, menu[i].name, menu[i].price); 
			}
			break;
			case 2:
				struct Dish monMoi;
				printf("Nhap vi tri muon them gia tri  : ");
				scanf("%d",&viTri);
				printf("Nhap id mon muon them : ");
				scanf("%d",&monMoi.id);
				fflush(stdin);
				printf("Nhap ten mon moi:");
				fgets(monMoi.name,sizeof(monMoi.name),stdin);
				monMoi.name[strcspn(monMoi.name, "\n")] = '\0';
				printf("Nhap gia tien cho mon moi :");
				scanf("%d",&monMoi.price);
				for(int i=5; i>viTri;i--){
					menu[i] = menu[i - 1];
				}
				phanTu++;
				menu[viTri] = monMoi;
				for (int i = 0; i < phanTu; i++) {
				printf(" %d.%s:%d\n", menu[i].id, menu[i].name, menu[i].price); 
				}
			break;
			case 3:
				struct Dish suaMon; 
				printf("Nhap vi tri can sua: "); 
				scanf("%d", &viTri); 
				if (viTri < 0 || viTri > phanTu) { 
				printf("Vi tri khong hop le\n"); 
				} else { 
					printf("Nhap id mon moi : "); 
					scanf("%d", &suaMon.id); 
					fflush(stdin);
					printf("Nhap Ten mon moi: "); 
					fgets(suaMon.name,sizeof(suaMon.name),stdin); 
					suaMon.name[strcspn(suaMon.name,"\n")]='/0';					
					printf("Nhap gia mon moi moi: "); 
					scanf("%d", &suaMon.price); 
					menu[viTri] = suaMon; 
				}
				for (int i = 0; i < phanTu; i++) {
					printf(" %d.%s:%d\n", menu[i].id, menu[i].name, menu[i].price); 
				}
				
			break; 
			case 4:
				struct Dish xoaMoi;
				printf("Nhap vi tri muon them gia tri  : ");
				scanf("%d",&viTri);
				printf("Nhap id mon muon them : ");
				scanf("%d",&monMoi.id);
				fflush(stdin);
				printf("Nhap ten mon moi:");
				fgets(monMoi.name,sizeof(monMoi.name),stdin);
				monMoi.name[strcspn(monMoi.name, "\n")] = '\0';
				printf("Nhap gia tien cho mon moi :");
				scanf("%d",&monMoi.price);
				for(int i=5; i>viTri;i--){
					menu[i] = menu[i - 1];
				}
				phanTu++;
				menu[viTri] = monMoi;
				for (int i = 0; i < phanTu; i++) {
				printf(" %d.%s:%d\n", menu[i].id, menu[i].name, menu[i].price); 
				}
	
			break; 
			case 5:
				printf("1.Giam dan theo price\n");
				printf("2.Tang dan theo price\n");
				int luaChon;
				printf("Nhap lua chon cua ban :");
				scanf("%d", &luaChon);
				switch(luaChon){
					case 1:
						for (int i = 0; i < phanTu - 1; i++) {
							for (int j = 0; j < phanTu - i -1; j++) { 
								if (menu[j].price < menu[j+1].price) { 
									struct Dish temp = menu[j]; 
									menu[j] = menu[j+1]; 
									menu[j+1] = temp; 
								} 
							} 
						}
						for (int i = 0; i < phanTu; i++) {
							printf(" %d.%s:%d\n", menu[i].id, menu[i].name, menu[i].price); 
						}
					break;
					case 2:
						for (int i = 0; i < phanTu - 1; i++) { 
							for (int j = 0; j < phanTu -i -1; j++) { 
								if (menu[j].price > menu[j+1].price) { 
									struct Dish temp = menu[j]; 
									menu[j] = menu[j+1]; 
									menu[j+1] = temp; 
								} 
							} 
						}
						for (int i = 0; i < phanTu; i++) {
							printf(" %d.%s:%d\n", menu[i].id, menu[i].name, menu[i].price); 
						}		
					break;
					default: 
					printf("Lua chon khong hop le\n");		
				}
			 
			break;
			case 6:
				printf("a.Tim kiem tuyen tinh");
				printf("b.Tim kiem nhi phan");
			break;
			case 7:
				printf("THOAT CHUONG TRINH");
			break;
			default: 
				printf("Lua chon khong hop le\n");
		}		
	}while (choice!=7);
	return 0;
}
