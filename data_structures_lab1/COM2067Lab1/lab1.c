#include<stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){

    char matris[15][15];

    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            scanf(" %c",&matris[i][j]);
        }
    } 
    char kelime[15];
    scanf("%s",kelime);



    int uzunluk=strlen(kelime);
    bool bulduMu=0;

    int buldu[15][15]={0};

    //yukarı aşağı sağ sol arama:
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(kelime[0]==matris[i][j]){
                if((j+1)>=uzunluk){ //sola sığar mı kontrolü
                    int k;
                    for (k=0;k<uzunluk;k++){
                        if(kelime[k]!=matris[i][j-k]){
                            break;
                        }                   
                    }
                    if(k==uzunluk){
                        for(int l=j;l>j-k && l>=0;l--){
                            buldu[i][l]=1;
                        }
                        bulduMu=1;
                        
                    }
                }
            }    
        }                
          
    } 

    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(kelime[0]==matris[i][j]){
                if(j+uzunluk<=15){  //sağa sığar mı
                    int k;
                    for (k=0;k<uzunluk;k++){
                        if(kelime[k]!=matris[i][j+k]){
                            break;
                        }                   
                    }
                    if(k==uzunluk){
                        for(int l=j;l<j+k ;l++){
                            buldu[i][l]=1;
                        }
                        bulduMu=1;
                        
                    }
                }
            }    
        }
    } 

        for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(kelime[0]==matris[i][j]){
                if((i+1)>=uzunluk){ //yukarı sığar mı 
                    int k;
                    for (k=0;k<uzunluk;k++){
                        if(kelime[k]!=matris[i-k][j]){
                            break;
                        }                   
                    }
                    if(k==uzunluk){
                        for(int l=i;l>i-k && l>=0;l--){
                            buldu[l][j]=1;
                        }
                        bulduMu=1;
                        
                    }
                }
            }    
        }
    }

    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(kelime[0]==matris[i][j]){
                if(i+uzunluk<=15){  //aşağı sığar mı
                    int k;
                    for (k=0;k<uzunluk;k++){
                        if(kelime[k]!=matris[i+k][j]){
                            break;
                        }                   
                    }
                    if(k==uzunluk){
                        for(int l=i;l<i+k;l++){
                            buldu[l][j]=1;
                        }
                        bulduMu=1;
                        
                    }
                }
            }    
        }
    }

    //diagonal arama:

     for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(kelime[0]==matris[i][j]){
                if((j+1)>=uzunluk && (i+1)>=uzunluk){ //sol üst çapraz
                    int k;
                    for (k=0;k<uzunluk;k++){
                        if(kelime[k]!=matris[i-k][j-k]){
                            break;
                        }                   
                    }
                    if(k==uzunluk){
                        for(int l=0;l<k;l++){
                            buldu[i-l][j-l]=1;
                        }
                        bulduMu=1;
                        
                    }
                }
            }    
        }                
          
    } 

    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(kelime[0]==matris[i][j]){
                if(j+uzunluk<=15 && (i+1)>=uzunluk){  //sağa üst çapraz
                    int k;
                    for (k=0;k<uzunluk;k++){
                        if(kelime[k]!=matris[i-k][j+k]){
                            break;
                        }                   
                    }
                    if(k==uzunluk){
                        for(int l=0;l<k;l++){
                            buldu[i-l][j+l]=1;
                        }
                        bulduMu=1;
                        
                    }
                }
            }    
        }
    } 

        for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(kelime[0]==matris[i][j]){
                if(i+uzunluk<=15 && (j+1)>=uzunluk){ //sol alt çapraz
                    int k;
                    for (k=0;k<uzunluk;k++){
                        if(kelime[k]!=matris[i+k][j-k]){
                            break;
                        }                   
                    }
                    if(k==uzunluk){
                        for(int l=0;l<k;l++){
                            buldu[i+l][j-l]=1;
                        }
                        bulduMu=1;
                        
                    }
                }
            }    
        }
    }

    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(kelime[0]==matris[i][j]){
                if(i+uzunluk<=15 && j+uzunluk<=15){  //sağ alt çapraz
                    int k;
                    for (k=0;k<uzunluk;k++){
                        if(kelime[k]!=matris[i+k][j+k]){
                            break;
                        }                   
                    }
                    if(k==uzunluk){
                        for(int l=0;l<k;l++){
                            buldu[i+l][j+l]=1;
                        }
                        bulduMu=1;
                        
                    }
                }
            }    
        }
    }


    //çıktı
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(buldu[i][j]==1){
            printf("%c ",matris[i][j]);

            }else{
                printf("* ");
            }
        }
        printf("\n");
    }

    return 0; 
}