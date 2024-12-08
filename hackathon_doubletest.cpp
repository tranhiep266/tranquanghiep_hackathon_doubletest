#include <stdio.h>
int main(){
    int arr[100],length,menu;
    while(menu!=15){
        printf("\nMENU\n");
        printf("1. Nhap so luong va gia tri cho cac phan tu\n");
        printf("2. In mang (arr[0]=..., arr[1]=...)\n");
        printf("3. Dem so luong so hoan hao\n");
        printf("4. Dem so luong so nguyen to\n");
        printf("5. Tim gia tri lon thu hai (khong sap xep)\n");
        printf("6. Tim gia tri nho thu hai (khong sap xep)\n");
        printf("7. Them phan tu tai vi tri\n");
        printf("8. Xoa phan tu tai vi tri\n");
        printf("9. Sap xep mang tang dan (sap xep chen)\n");
        printf("10. Sap xep mang giam dan (sap xep chen)\n");
        printf("11. Tim kiem phan tu (Tim kiem nhi phan)\n ");
        printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
        printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
        printf("14. Dao nguoc mang\n");
        printf("15. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d",&menu);

        if(menu==1){
            printf("Nhap kich thuoc cua mang: ");
            scanf("%d",&length);
            for (int i=0;i<length; ++i){
                printf("Nhap phan tu thu %d: ",i+1);
                scanf("%d",&arr[i]);
            }
        }
        
        else if(menu==2){
            printf("Cac phan tu trong mang: \n");
            for(int i=0;i<length; ++i){
                printf("arr[%d] = %d\n",i,arr[i]);
            }
        }
        
        else if(menu==3){
            int count=0;
            for(int i=0;i<length;++i){
                int sum=1;
                for(int j=2;j*j<=arr[i];++j){
                    if (arr[i] % j == 0){
                        sum+=j;
                        if(!(arr[i]/j ==j)){
                            sum+=arr[i]/j;
                        }
                    }
                    if(sum == arr[i] && arr[i] >= 6){
                        count++;
                        printf("%d ", arr[i]);
                    }
                }
            }
            printf("So luong so hoan hao: %d",count);
        }
        
        else if(menu==4){
            int count=0;
            for (int i=0;i<length; ++i){
                int prime=0;
                for (int j=2;j*j<=arr[i];++j){
                    if(arr[i]%j==0){
                        prime=1;
                        break;
                    }
                }
                if(!prime&&arr[i]>=2){
                    ++count;
                }
            }
            printf("So luong cac phan tu la so nguyen to trong mang: %d",count);
        }
        
        else if(menu==5){
            int max=arr[0],max2;
            for(int i=1;i<length;++i){
                if(arr[i]>max){
                    max2=max;
                    max=arr[i];
                }
                else if(arr[i]>max2&&arr[i]!=max)
                    max2=arr[i];
            }
            printf("Phan tu lon thu hai trong mang: %d",max2);
        }
        
        else if(menu==6){
            int min=arr[0],min2;
            min2=(arr[0]<arr[1])?arr[1]:arr[0];
            for(int i=1;i<length;++i){
                if(arr[i]<min){
                    min2=min;
                    min=arr[i];
                }
                else if(arr[i]<min2&&arr[i]!=min){
                    min2=arr[i];
                }
            }
            printf("Phan tu nho thu hai trong mang: %d", min2);
        }
        
        else if(menu==7){
            int value_add,index_add;
            printf("Nhap gia tri can them: ");
            scanf("%d",&value_add);
            printf("Nhap vi tri can them: ");
            scanf("%d",&index_add);

            if(index_add>length){
                arr[index_add-1]=value_add;
                length=index_add;
            }else{
                for(int i=length;i>=index_add;--i){
                    arr[i]=arr[i-1];
                }
                arr[index_add-1]=value_add;
                length++;
            }
        }
        
        else if(menu == 8){
            int index_del;
            printf("Nhap vi tri can xoa: ");
            scanf("%d",&index_del);
            for(int i=index_del-1;i<length-1;++i){
                arr[i]=arr[i+1];
            }
            --length;
        }
        
        else if(menu==9){
            for(int i=1;i<length;++i){
                int temp=arr[i],j=i-1;
                while(j>=0&&arr[j]>temp){
                    arr[j+1]=arr[j];
                    --j;
                }
                arr[j + 1] = temp;
            }
        }
        
        else if(menu==10){
            for(int i=1;i<length;++i){
                int temp=arr[i],j=i-1;
                while(j>= 0&&arr[j]<temp){
                    arr[j+1] = arr[j];
                    --j;
                }
                arr[j+1]=temp;
            }
        }
        
        else if(menu==11){
            int value_find;
            printf("Nhap phan tu can tim: ");
            scanf("%d",&value_find);
            int found=0;
            int left=0,right=length-1;
            while(left<=right){
                int k=(left+right);
                if (arr[k]==value_find){
                    printf("Gia tri %d ton tai trong mang\n", value_find);
                    found=1;
                    break;
                }else if(arr[k]<value_find){
                    left=k+1;
                }else{
                    right=k-1;
                }
            }
            if(!found){
                printf("Gia tri %d khong ton tai trong mang\n",value_find);
            }
        }
        
        else if(menu==12){
            int newLength=length;
            for(int i=0;i<newLength;++i){
                for(int j=i+1;j<newLength;++j){
                    if(arr[i]==arr[j]){
                        for(int k=j;k<newLength-1;++k){
                            arr[k] = arr[k + 1];
                        }
                        newLength--;
                        j--;
                    }
                }
            }
            length = newLength;
        }
        
        else if(menu==13){
            int odd[length],even[length];
            int j=0,k=0;
            for (int i=0;i<length; ++i){
                if(arr[i]%2==0){
                    even[j++]=arr[i];
                }else{
                    odd[k++] = arr[i];
                }
            }
            for(int i=1;i<j;++i){
                int temp=even[i],t=i-1;
                while(t>=0&&even[t]>temp){
                    even[t+1]=even[t];
                    --t;
                }
                even[t+1] = temp;
            }
            for(int i=1;i<k;++i){
                int temp=odd[i],t=i-1;
                while(t>=0&&odd[t]>temp){
                    odd[t+1]=odd[t];
                    --t;
                }
                odd[t+1]=temp;
            }
            for(int i=0;i<j;++i){
                arr[i]=even[i];
            }
            for(int i=0;i<k;++i){
                arr[j+i]=odd[i];
            }
        }
        
        else if(menu == 14){
            for(int i=0;i<length/2;++i){
                int temp=arr[i];
                arr[i]=arr[length-i-1];
                arr[length-i-1]=temp;
            }
        }
        
        else if(menu == 15){
            printf("Tam biet\n");
            return 0;
        }else{
            printf("Nhap lai\n");
        }
    }
}

