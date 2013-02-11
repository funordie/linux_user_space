#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <asm/delay.h>

/* Note scope of variable and mutex are the same */
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter=0;

void *print_message_function1( void *ptr );
void *print_message_function2( void *ptr );


main()
{
     pthread_t thread1, thread2;
     char *message1 = "Thread 1";
     char *message2 = "Thread 2";
     int  iret1, iret2;

    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, print_message_function1, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function2, (void*) message2);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Thread 1 returns: %d\n",iret1);
     printf("Thread 2 returns: %d\n",iret2);
     exit(0);
}

void *print_message_function1( void *ptr )
{
     char *message;
     int i;
     message = (char *) ptr;
     
     for (i = 0 ; i < 655350; i++)
		mdelay(40000);
     
     pthread_mutex_lock( &mutex1 );
     counter++;
     printf("%s count++:%d\n", message, counter);   
     pthread_mutex_unlock( &mutex1 );
}

void *print_message_function2( void *ptr )
{
     char *message;
     message = (char *) ptr; 
     
     pthread_mutex_lock( &mutex1 );
     counter++;
     printf("%s count++:%d\n", message, counter);   
     pthread_mutex_unlock( &mutex1 );
}



/* Function C */
void functionC()
{
  

}
