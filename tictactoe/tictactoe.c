#include <stdio.h>
#include <stdlib.h>


int table(int n[9]){
	for(int j=0; j<9; j++){ 
		if(j%3==0 && j!=0){
			if(n[j]==11){
				printf("\n");
				printf("----------\nX | ");
			}else if(n[j]==22){
				printf("\n");
				printf("----------\nO | ");
			}else{
				printf("\n");
				printf("----------\n%d | ", n[j]);
			}	
		}else if(j!=2 && j!=5 && j!=8){
			if(n[j]==11){
				printf("X | ");
			}else if(n[j]==22){
				printf("O | ");			
			}else{
				printf("%d | ", n[j]);
			}
		}else{
			if(n[j]==11){
				printf("X");
			}else if(n[j]==22){
				printf("O");			
			}else{
				printf("%d", n[j]);
			}
		}
	}
	return 0;
}
int main(){
	int on=1;
	while(on==1){
		int choices[9];
		for(int i=0; i<9; i++){
			choices[i]=i;
		}
		table(choices);
		int count=0;
		while(count!=9){
			int play;
			printf("\nChoose a spot to play: ");
			scanf("%d", &play);
			if(choices[play]==play){
				if(count%2==0){
					choices[play]=11;
				}else{
					choices[play]=22;
				}
			}else{
				printf("\nThe game finished! You choosed an invalid option :(");
				break;
			}
		
			table(choices);
			if((choices[0]==choices[4] && choices[4]==choices[8]) || (choices[6]==choices[4] && choices[4]==choices[2])){
				printf("\nThe game finished!");
				break;
			}
			int test=0;
			for(int x=0;x<9;x=x+3){
			 	int partial = x/3;
				if(choices[x]==choices[x+1] && choices[x+1]==choices[x+2]){
					printf("\nThe game finished!");
					test=1;
				}else if(choices[partial]==choices[partial+3] && choices[partial+3]==choices[partial+6]){
					printf("\nThe game finished!");
					test=1;	
				}
			}
			if(test==1){
				break;
			}
			
			count++;
		}
		printf("\nIf you want to continue playing press 1:");
		scanf("%d", &on);	
	}
	
	
	return 1;
}
