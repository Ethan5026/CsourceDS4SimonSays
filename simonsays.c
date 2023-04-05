
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int simonfun();
int timerfun(double time, double timer, int counter);
int loser(int rounds);
int loser2(int rounds);



// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./simonsays


int main(int argc, char *argv[])
{
	srand(time(NULL));
    int triangle, circle, x_button, square;
	int end = 0;
	int simon;
	double time;
	int timer=2000;
	int pressed;
	int counter=-1;
	printf("\n\nPlease press the Circle button to start Bop It!\n\n");
	int sum=1;
	circle=0;
	while (end!=1)
    {

		while(circle==0){
			 scanf("%lf, %d, %d, %d, %d",
              &time, &triangle, &circle, &x_button, &square);
			 
			 
			}
		while(sum!=0){
			scanf("%lf, %d, %d, %d, %d",
             &time, &triangle, &circle, &x_button, &square); 
		sum = triangle + circle + x_button + square;}
		printf("Welcome to Bop It!\n\n");
		while(end!=1){
			scanf("%lf, %d, %d, %d, %d",
             &time, &triangle, &circle, &x_button, &square); 
			counter +=1;
			simon=5;
			pressed=0;
			simon=simonfun();
			if(simon==0){
				printf("Press the Triangle button!");
				printf("\nYou have %d milliseconds to respond!\n\n", timer);
				pressed=timerfun(time, timer,counter);
				timer=timer-100;
				if(pressed==6)
					 break;
				if ((pressed!=1) && (pressed!=5)){
					end = loser(counter);
				}}
			
			else if(simon==1){
				printf("Press the Circle button!");
				printf("\nYou have %d milliseconds to respond!\n\n", timer);
				pressed=timerfun(time, timer,counter);
				timer=timer-100;
				if(pressed==6)
					 break;
				if ((pressed!=2) && (pressed!=5))
					end = loser(counter);
			}
			else if(simon==2){
				printf("Press the X button!");
				printf("\nYou have %d milliseconds to respond!\n\n", timer);
				pressed=timerfun(time, timer,counter);
				timer=timer-100;
				if(pressed==6)
					 break;
				if ((pressed!=3) && (pressed!=5))
					end = loser(counter);
			}
			else if(simon==3){
				printf("Press the Square button!");
				printf("\nYou have %d milliseconds to respond!\n\n", timer);
				pressed=timerfun(time, timer,counter);
				timer=timer-100;
				 if(pressed==6)
					 break;
			     if ((pressed!=4) && (pressed!=5))
					end = loser(counter);
			}
			
		}
    if(pressed==6)
				end = loser2(counter);

    
}
return 0;
}



int simonfun(){
	srand(time(NULL));
	int random;
	random=rand()%4;
	return random;
		}


int timerfun(double time, double timer, int counter){
	int triangle, circle, x_button, square;
	int sum;
	double thesecondcoming=0;
	int end = 0;
	int lit=0;
	int square1, circle1, triangle1, x_button1;
	while((thesecondcoming-time<(timer))&&(end==0)&& (lit==0)){
		if(lit!=0)
			break;
		thesecondcoming=0;
		triangle1=0;
		circle1=0;
		x_button1=0;
		square1=0;
		triangle=0;
		circle=0;
		x_button=0;
		square=0;
		
	
		scanf("%lf, %d, %d, %d, %d",
              &thesecondcoming, &triangle1, &circle1, &x_button1, &square1); 
		sum = triangle1 + circle1 + x_button1 + square1;
		if(sum!=0){
			
			square=square1;
			triangle=triangle1;
			circle=circle1;
			x_button=x_button1;}
		while((sum!=0)&&(lit==0)){
			scanf("%lf, %d, %d, %d, %d",
             &thesecondcoming, &triangle1, &circle1, &x_button1, &square1); 
			sum = triangle1 + circle1 + x_button1 + square1;
					
			if((thesecondcoming-time<(timer))&&(end==0)&&(sum==0)){
				if(triangle==1){
					triangle1=0;
					lit=1;
					return 1;
					break;}
				else if(circle==1){
					circle1=0;
					lit=1;
					return 2;
					break;}
				else if(x_button==1){
					x_button1=0;
					lit=1;
					return 3;
					break;}
				else if(square==1){
					square1=0;
					lit=1;
					return 4;
					break;
				}
			}
		}
	}
	
	if(thesecondcoming-time>(timer)){
		return 6;}
	return 5;
}
	


	
	
	


int loser(int rounds){
	int end;
	printf("Wrong button! :(\nYou lose!\nYou made it through %d rounds!\n\n", rounds);
	end=1;
	return end;

}

int loser2(int rounds){
	int end;
	printf("You ran out of time. :(\nThanks for playing!\nYou made it through %d rounds!", rounds);
	end=1;
	return end;
}
