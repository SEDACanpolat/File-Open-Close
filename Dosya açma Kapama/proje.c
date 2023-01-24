#include <stdio.h>
#include <stdlib.h>
void fgetAnswers(){ 
    FILE *b;
	FILE *hata;
	int Numara,soru_numarasi,i,kacirilan_soru[45]; 
	char cevap_anaht[45],cevap[45];
	b=fopen("examdat.txt","r"); // dosyanýn okunmasý (read=dosyayý okuma)
	hata=fopen("report.txt","w"); // dosyaya yazma (writing=dosya yazma iþlemi)
	if(b==NULL){ //Henüz deðeri atanmamýþ olan ya da hiçbir deðere sahip olmayan þeyleri ifade etmek için kullandýk.
		printf("Dosya okunmadi");
	}
	else{
	    fscanf(b,"%d %s",&soru_numarasi,&cevap_anaht); //%d=integer(tam sayi) %s=string(karakter) demektir.
			// dosyanin ilk kýsmýnýn bastýrýlmasý
		fprintf(hata,"Exam Report\n");
		fprintf(hata,"puan");
		for(i=0;i<soru_numarasi;i++){
			fprintf(hata,"%d",i+1); // soru numaralarýný yazan döngü.
		}
		fprintf(hata,"\ncevap");
		for(i=0;i<soru_numarasi;i++){ //// for döngüsü =i deðerini 0 ata i soru numarasi küçük olana kadar i yi birer birer arttýr.
			fprintf(hata,"%c",cevap_anaht[i]); // cevap anahtarýný yazan döngü.
		}
		fprintf(hata,"\n\n  total_puan(%c)\n"); 
		while(fscanf(b,"%d %s",&Numara,cevap)!=EOF) // verilerin okunmasý EOF kullanmamýzýn sebebi dosyanýn bittiði haberini vermesidir.
		{
			double total_puan=0; //double þeklinde total_puaný atama iþlemi yaptýk..
			for(i=0;i<soru_numarasi;i++){
		        if(cevap_anaht[i]==cevap[i])
					total_puan++; 
				else
					kacirilan_soru[i]+=1; // kaç kiþinin soruyu kaçýrdýðý iþlemi.
			}
			int not=(double)100/soru_numarasi * total_puan; // Yüzdesel total puaný verir.
			fprintf(hata,"%d\n",Numara,not); // dosyaya öðrencinin notunu yazdýrma iþine yarar.
		}
		fprintf(hata,"\n");
		fprintf(hata,"soru");
		for(i=0;i<soru_numarasi;i++){
	        fprintf(hata,"%d",i+1); // soru numarasý 
		}
		fprintf(hata,"\n");
		fprintf(hata,"kacirilan_soru");
		for(i=0;i<soru_numarasi;i++){
		    fprintf(hata,"%d",kacirilan_soru[i]); // kaçýrýlan_soru sayýsýný vermektedir.
		}
		printf("Report.txt adli dosya olusturuldu...");
	}
	fclose(b); //fclose=dosyayý kapama iþlemi için kullanýlýr. FIlE*b yi kapattýk.
	fclose(hata); // FILE*hata 
	}
int main(){
	int n;
	printf("Lutfen Baslamak icin bir rakam giriniz:");
	scanf("%d",&n);	
	fgetAnswers(); //Fonksiyon iþlemini kapadýk.
	return 0;
	}
