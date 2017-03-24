This is a Sleeping TA application.To run this follw following steps.

1. From the drive run "make" , as make file is include it will execute and will create executabe. 
If by any reason it fails because of system configuration non compatibility Use below command

gcc -o sleepingTA sleepingTA.o -lpthread

after this you can run "./sleepingTA" to runthe executable.
 
 


2. Two screen shots are include. 
	1. If you see 1.png you will notice that as soon as you run this application it will ask you 
	   number of student looking for TA help.
	2. Then it will display on Prompt 'n' different student reached for TA help. Number there dennote student like
	   '2' denote 2nd student like wise '4' 4th student.
	3. It will also display which student is sitting on which chair like " 1-2-3 sequentially" means three chairs arranged in that    		   sequence and "4 0 1" means 4th student is sitting on 1st chair 2nd chair is empty and 1st student is sitting on 3rd chair.
	    
	4. Now if you see 2.png you will notice that if chairs outside TA office are full student will return back to programming
	   and will come later. 

