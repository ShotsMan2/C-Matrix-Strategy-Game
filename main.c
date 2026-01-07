#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matris[9][9],a,i,j,yerlestirilenpiyon,uygunluk,kaynak,hedef,konum[9][9],ksatir,ksutun,hsatir,hsutun,satirfark,sutunfark;
    int yemedurumu,kura,sayac,pcyedi,k,normaldurum,hamle,adim,yedim,pcpiyonyemeadedi=0;

    srand(time(NULL));

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            matris[i][j]=0;
        }
    }

    yerlestirilenpiyon=0;
    while(yerlestirilenpiyon<8){
        i=rand()%9;
        j=rand()%9;

        if(matris[i][j]==0){
            matris[i][j]=1;
            yerlestirilenpiyon++;
        }
    }

    yerlestirilenpiyon=0;
    while(yerlestirilenpiyon<8){
        i=rand()%9;
        j=rand()%9;

        if(matris[i][j]==0){

            uygunluk=1;

            if(i+2<9 && j+2<9){
                if(matris[i+2][j+2]==1){
                    uygunluk=0;
                }
            }
            if(i+2<9 && j-2>=0){
                if(matris[i+2][j-2]==1){
                    uygunluk=0;
                }
            }
            if(i-2>=0 && j+2<9){
                if(matris[i-2][j+2]==1){
                    uygunluk=0;
                }
            }
            if(i-2>=0 && j-2>=0){
                if(matris[i-2][j-2]==1){
                    uygunluk=0;
                }
            }
            if(uygunluk==1){
                matris[i][j]=2;
                yerlestirilenpiyon++;
            }
        }
    }

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(matris[i][j]==0){
                printf("  .");
            }
            else{
                printf("%3d",matris[i][j]);
            }
        }
        printf("\n");
    }

    adim=1;

    do{
        do{
            printf("\n");

    a=1;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            konum[i][j]=a;
            printf("%3d",konum[i][j]);
            a++;
        }
        printf("\n");
    }

    printf("\n");

        uygunluk=1;

        printf("kaynak konumu girin: ");
        scanf("%d",&kaynak);

    printf("hedef konumu girin: ");
    scanf("%d",&hedef);

    if(1>kaynak || kaynak>81){
        printf("kaynak konumunu 1 ile 81 arasinda giriniz. \n\n");
        uygunluk=0;
        continue;
    }

    if(1>hedef || hedef>81){
        printf("hedef konumunu 1 ile 81 arasinda giriniz. \n\n");
        uygunluk=0;
        continue;
    }

    ksatir=(kaynak-1)/9;
    ksutun=(kaynak-1)%9;

    hsatir=(hedef-1)/9;
    hsutun=(hedef-1)%9;

    satirfark=ksatir-hsatir;
    if(satirfark<0){
        satirfark=satirfark*-1;
    }

    sutunfark=ksutun-hsutun;
    if(sutunfark<0){
        sutunfark=sutunfark*-1;
    }

    if(matris[ksatir][ksutun]!=1){
        printf("kendi piyonunuzu secin. \n\n");
        uygunluk=0;
        continue;
    }

    yedim=0;

    if(matris[hsatir][hsutun]==2){
        if(satirfark==2 && sutunfark==2){
            int ortasutun=(ksutun+hsutun)/2;
            int ortasatir=(ksatir+ksutun)/2;

            if(matris[ortasatir][ortasutun]!=2){
                matris[hsatir][hsutun]=1;
                matris[ksatir][ksutun]=0;
                yedim=1;
            }
            else{
                printf("Arada bilgisayarın piyonu olduğundan yiyemezsiniz. \n");
                uygunluk=0;
                continue;
            }
        }
    }

    if(yedim==0){
        if(matris[hsatir][hsutun]!=0){
        printf("Yeme durumunuz yoksa hedef hucreyi bos secin. \n\n");
        uygunluk=0;
        continue;
    }

    if(satirfark>1 || sutunfark>1){
        printf("yalnizca bir birim hareket edebilirsiniz. \n\n");
        uygunluk=0;
        continue;
    }
    }

    if(sutunfark==0){
        printf("dikey hareket yasaktir. \n\n");
        uygunluk=0;
        continue;
    }

    }while(uygunluk==0);

    matris[ksatir][ksutun]=0;
    matris[hsatir][hsutun]=1;
    printf("hamle basarili. \n\n");

    adim++;

    if(adim>=5 && pcpiyonyemeadedi>=1){
        break;
    }

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(matris[i][j]==0){
                printf("  .");
            }
            else{
                printf("%3d",matris[i][j]);
            }
        }
        printf("\n");
    }

    yemedurumu=0;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(matris[i][j]==2){
                if(i+2<=8 && j+2<=8){
                    if(matris[i+2][j+2]==1 && matris[i+1][j+1]!=1){
                    yemedurumu++;
                    }
                }
                if(i+2<=8 && j-2>=0){
                    if(matris[i+2][j-2]==1 && matris[i+1][j-1]!=1){
                    yemedurumu++;
                    }
                }
                if(i-2>=0 && j+2<=8){
                    if(matris[i-2][j+2]==1 && matris[i-1][j+1]!=1){
                    yemedurumu++;
                    }
                }
                if(i-2>=0 && j-2>=0){
                    if(matris[i-2][j-2]==1 && matris[i-1][j-1]!=1){
                    yemedurumu++;
                    }
                }
            }
        }
    }

    if(yemedurumu>0){
        kura=rand()%yemedurumu;
        sayac=0;
        pcyedi=0;

         for(i=0;i<9 && pcyedi==0;i++){
         for(j=0;j<9 && pcyedi==0;j++){
            if(matris[i][j]==2){
                if(pcyedi==0 && i+2<=8 && j+2<=8){
                    if(matris[i+2][j+2]==1 && matris[i+1][j+1]!=1){
                        if(kura==sayac){
                            matris[i+2][j+2]=2;
                            matris[i][j]=0;
                            pcyedi=1;
                        }
                        sayac++;
                    }
                }
                if(pcyedi==0 && i+2<=8 && j-2>=0){
                    if(matris[i+2][j-2]==1 && matris[i+1][j-1]!=1){
                        if(kura==sayac){
                            matris[i+2][j-2]=2;
                            matris[i][j]=0;
                            pcyedi=1;
                        }
                        sayac++;
                    }
                }
                if(pcyedi==0 && i-2>=0 && j+2<=8){
                    if(matris[i-2][j+2]==1 && matris[i-1][j+1]!=1){
                        if(kura==sayac){
                            matris[i-2][j+2]=2;
                            matris[i][j]=0;
                            pcyedi=1;
                        }
                        sayac++;
                    }
                }
                if(pcyedi==0 && i-2>=0 && j-2>=0){
                    if(matris[i-2][j-2]==1 && matris[i-1][j-1]!=1){
                        if(sayac==kura){
                            matris[i-2][j-2]=2;
                            matris[i][j]=0;
                            pcyedi=1;
                        }
                        sayac++;
                    }
                }
            }
        }
    }
        if(pcyedi==1){
            pcpiyonyemeadedi++;
        }
        printf("\n\n");
        printf("Bilgisayar hamle yapti.");
    }

    else{
        int ny[]={0,0,-1,-1,1,1};
        int nx[]={-1,1,-1,1,-1,1};
        int ni,nj;

        normaldurum=0;

        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(matris[i][j]==2){
                    for(k=0;k<6;k++){
                        ni=i+ny[k];
                        nj=j+nx[k];
                        if(ni>=0 && ni<=8 && nj>=0 && nj<=8){
                            if(matris[ni][nj]==0){
                                normaldurum++;
                            }
                        }
                    }
                }
            }
        }
        if(normaldurum>0){
        kura=rand()%normaldurum;
        sayac=0;
        hamle=0;

        for(i=0;i<9 && hamle==0;i++){
            for(j=0;j<9 && hamle==0;j++){
                if(matris[i][j]==2){
                    for(k=0;k<6;k++){
                        ni=i+ny[k];
                        nj=j+nx[k];
                        if(ni>=0 && ni<=8 && nj>=0 && nj<=8){
                            if(matris[ni][nj]==0){
                                if(sayac==kura){
                                    matris[ni][nj]=2;
                                    matris[i][j]=0;
                                    hamle=1;
                                    printf("\n\n Bilgisayar hamle yapti.\n");
                                    break;
                                }
                                sayac++;
                            }
                        }
                    }
                }
            }
        }
    }
    else{
        printf("bilgisayar hamle yapamıyor. \n\n");
    }
    }

    adim++;

    printf("\n");

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(matris[i][j]==0){
                printf("  .");
            }
            else{
                printf("%3d",matris[i][j]);
            }
        }
        printf("\n");
    }

    }while(adim<=5 || pcpiyonyemeadedi==0);

    return 0;
}
