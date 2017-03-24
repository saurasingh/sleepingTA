#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <pthread.h>  
#include <semaphore.h>  
#include <time.h> 
 
#include"sleepingTA.h"

void taSleepingTime(void)
{ 
	int time = rand() % SLEEP_MAX + 1; 
 	sleep(time); 
 }

void* teachingAssistant() 
 { 
 	while(1) 
 	{ 
 		sem_wait(&studentSemaphore);	 
 		pthread_mutex_lock(&mutex);  		 
 		printf("Teaching Assistant helping student %d\n",seat[studentSeated]);	 
 		seat[studentSeated]=0; 
 		counter--; 		 
 		printf("Student seating on seats 1-2-3 sequentially : %d  %d  %d\n",seat[0],seat[1],seat[2]); 
 		studentSeated = (studentSeated + 1) % MAX_SEAT;  		 
		if ( counter == 0)
		{
		printf("		Teaching Assistant finish helping Student going to sleep.\n");
		taSleepingTime();  
		}
 		pthread_mutex_unlock(&mutex); 	  
 		sem_post(&teachingAssistantSemaphore); 
 	}
 } 

 void* studentRequiredHelp(void* studentIdentification) 
 { 
 	int identification = *(int*)studentIdentification; 
 	printf(" %d student reached for Teaching Assistant help\n",identification);		 
 	 
 	while(1) 
 	{ 
 		taSleepingTime(); 
   		pthread_mutex_lock(&mutex);  
		if(MAX_SEAT > counter)	 
 		{ 
 			seat[seatAvailable] = identification;  					 
 			printf("	 %d students seated at hallway waiting for Teaching Assistant help\n",identification); 
 			printf("          students waiting outside TA office on seats 1-2-3  :  %d  %d  %d\n",seat[0],seat[1],seat[2]); 
			seatAvailable = (seatAvailable+1) % MAX_SEAT; 
			counter++; 
			pthread_mutex_unlock(&mutex); 			
 	 		sem_post(&studentSemaphore); 
			if (counter == 1)
			{			
			printf("Wake sleeping Teaching Assistant for his/her help\n");
			}
 			sem_wait(&teachingAssistantSemaphore); 
 		} 
 		else 
 		{  			 
 			pthread_mutex_unlock(&mutex);  			 
 			printf("No more seats available as TA is busy.Student %d is resuming programing and will be back later\n",identification);		 
 		} 
 	}				 
 } 
 
 
 


 

int main(int argc, char **argv)
	{ 
 	
 	printf("How many students want to get help from Teaching Assistant ? "); 
 	scanf("%d", &totalStudent); 
	pthread_t studentThread[totalStudent]; 
 	pthread_t teachingAssistantThread; 
	int studentIdentificationNumber[totalStudent];
	for ( in = 0; in < totalStudent; in++ ) 
	{
      		studentIdentificationNumber[ in ] = in + 1; 
	}
 	 

	if (totalStudent==0)
	{
		printf ("No student are seated..TA going to sleep! \n");
		exit(-1);
	}
    	sem_init(&studentSemaphore,0,0); 
 	sem_init(&teachingAssistantSemaphore,0,1); 
 	srand(time(NULL));   
 	pthread_mutex_init(&mutex,NULL); 
 	pthread_create(&teachingAssistantThread,NULL,teachingAssistant,NULL); 
 	for(in = 0; in < totalStudent; in++) 
 	{ 
 		studentIdentificationNumber[in] = in+1; 
 		pthread_create(&studentThread[in], NULL, studentRequiredHelp, (void*) &studentIdentificationNumber[in]); 
 	
 	 }
 	pthread_join(teachingAssistantThread, NULL);  	 
 	for(in = 0; in < totalStudent;in++) 
 	{ 
 		pthread_join(studentThread[in],NULL); 
 	}	 
 	 
 	return 0; 
 } 
  
 
 
