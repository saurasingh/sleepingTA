#define MAX_SEAT 3   
#define SLEEP_MAX 10 
  
sem_t studentSemaphore; 
sem_t teachingAssistantSemaphore; 
  

pthread_mutex_t mutex; 
  
int seat[MAX_SEAT]; 
int seatAvailable = 0; 
int studentSeated = 0; 
int in;
int totalStudent; 
int counter = 0;   

void taSleepingTime(void); 
void* studentRequiredHelp(void* studentIdentification); 
void* teachingAssistant(); 
  
