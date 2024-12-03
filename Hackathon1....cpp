#include<stdio.h>
int main(){
	int a, b, c, d, choice, max, k = 1, xoa;
	int arr[50];
	int n;
	int l, r, mid;
	while(k>0){
	
	printf("\n--MENU---");
	printf("\n1.Nhap so phan tu can nhap va gia tri cac phan tu");
	printf("\n2.In ra cac gia tri phan tu dang quan li");
	printf("\n3.In ra gia tri lon nhat");
	printf("\n4.In ra gia tri la so nguyen to");
	printf("\n5.Them gia tri vao mang");
	printf("\n6.Xoa phan tu trong mang");
	printf("\n7.Sap xep cac phan tu trong mang");
	printf("\n8.Tim kiem phan tu trong mang");
	printf("\n9.Thoat");
	printf("\nNhap lua chon cua ban: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1: //Nhap so phan tu can nhap va cac gia tri phan tu
			printf("\nNhap kich thuoc phan tu cua mang: ");
			scanf("%d", &n);
			printf("\nNhap phan tu cho mang: ");
			for(int i=0; i<n; i++){
				printf("\nPhan tu thu %d: ", i);
				scanf("%d", &arr[i]);
			}
			break;
		case 2: //In ra cac gia tri phan tu dang quan li
			printf("Cac phan tu trong mang la: ");
			for(int i=0; i<n; i++){
				printf("%2d", arr[i]);
			}
			break;
		case 3: //In ra gia tri lon nhat
			for(int i=0; i<n; i++){
				if(arr[i]>max){
					max = arr[i];	
				}
			}
			printf("\nPhan tu lon nhat trong mang la: %d", max);
			break;
		case 4: //In ra phan tu la so nguyen to
			printf("Cac so nguyen to trong mang la: ");
			for(int i=0; i<n; i++){
			int SNT = arr[i];
			int KT = 1;
                if(SNT < 2){
                        KT = 0;
                }else{
                    for (int j = 2; j * j <= SNT; j++) {
                        if (SNT % j == 0) {
                            KT = 0;
                            break;
                            }
                        }
                    }

                    if(KT){
                        printf("%2d ", SNT);
                       
                    }
                }
			break;
		case 5://Them phan tu vao mang
			printf("Nhap vi tri can them: ");
			scanf("%d", &a);
			if(a>n || a<0){
				printf("Mang khong co vi tri nay");
				return 1;
			}
			printf("Nhap gia tri can them: ");
			scanf("%d", &b);
			for (int i = n; i > a; i--) {
		        arr[i] = arr[i - 1];
		    }
			    arr[a] = b;
			    n++;
		    printf("Mang sau khi them: ");
		    for (int i = 0; i < n; i++) {
		        printf("%d ", arr[i]);
		    }
		    printf("\n");
			break;
		case 6: //Xoa phan tu trong mang
				printf("Nhap vi tri can xoa: ");
		    scanf("%d", &xoa);
		    if (xoa<0 || xoa>=n) {
		        printf("Vi tri xoa khong hop le!\n");
		        return 1;
		    }
		    for (int i = xoa; i < n-1; i++) {
		        arr[i] = arr[i+1];
		    }
		    n--;
		    printf("Mang sau khi xoa: ");
		    for (int i=0; i < n; i++) {
		        printf("%d ", arr[i]);
		    }
			break;
		case 7://Sap xep cac phan tu trong mang tang dan
			for(int i=1; i<n; i++){
			int key = arr[i];
			int j = i-1;
			while(j>=0 && arr[j]>key){
				arr[j+1] = arr[j];
				j = j-1;
			}
			arr[j+1] = key;
			}
			printf("Mang sau khi sap xep la: \n");
			for(int i=0; i<n; i++){
				printf("%2d", arr[i]);
			}
			break;
		case 8:
			if(n == 0){
                printf("Mang chua duoc khai bao!");
            break;
            }
            l=0;
            r= n-1;
        printf("Nhap phan tu can tim: ");
        scanf("%d", &b);
        while (l <= r) {
            mid = l + (r - l)/2;
            if(arr[mid] == b) {
                printf("Tim thay tai vi tri %d", mid + 1 );
            break;
            }
            if(arr[mid] > b) {
                r = mid-1;
            }else {
                l = mid+1;
            }
        }
            printf("Khong co phan tu do trong mang: ");
			break;
		case 9:{
			printf("Thoat!");
			k--;
			break;
		}
			return 0;
		default:
			printf("Khong co chuc nang nay");
			break;
	}
	}
}
