#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define FNAME_SIZE 100
#define LINE_SIZE 101
#define INDEX_SIZE 40
#define WORD_SIZE 20000

int main()
{

        FILE *inFile;
        FILE *outFile;

        char line[LINE_SIZE];
        char inFileName[FNAME_SIZE];      // fine name to read
        char outFileName[FNAME_SIZE];     // file name to write

        char badWord[WORD_SIZE];
 
        char *token;			//a pointer variable for strtok()
	char *tokenIndex[INDEX_SIZE];   //a pointer variable holds token address
	char del[]=" ";			//delimiter 
	
	int index;
        int i;
	int count;


        printf("Enter a File Name to Read  :->   ");
        scanf("%s",inFileName);         // read infile name from console

        printf("Enter a File Name to Write :->   ");
        scanf("%s",outFileName);        // read out file name from console

         inFile = fopen(inFileName, "r");  // open a file  in read mode
         
	if (inFile == NULL)   // check the given infile name if it is open properly/exist
         {

                 printf("Error opening file\n");    // if not give error message and exit
                exit(1);
         }

        outFile = fopen(outFileName, "w");  // Open a file  for writing
        
	if (outFile == NULL)     // Check the given outfile name if it  open correctly/existed
         {
       	 printf("Error opening file\n");    // if not give error message and exit
	 exit(1);
         }

        while(fgets(line,LINE_SIZE,inFile)!=NULL)
        {
	     fputs(line,stdout);   // write line of sentence on consule
           
	     printf("Enter position of word to delete\n (Start counting at 0). Enter -1 to skip deletion :->");
             scanf("%d",&index);  	// user enter word position to delete 
	
             i=0;		//
	     count=0;		// 
            
	     if(index==-1)	// if index -1 write the line on file and continue to the next line
	     {
                    fputs(line,outFile);
		     continue;
             }
	     else                // if index > -1 start tokenizer
	     {
	      token=strtok(line,del);          //
	      while(token != NULL)            // break the given line using the given delimiter(" ")
               {
                      tokenIndex[i]=token;      // tokenIndex saves the tokens address 
                      i++;			
                      token = strtok(NULL,del);

               }
	    
	       while(i>count)		// loop for concatination and delete a word from the line
	       {
            	        char goodLine[WORD_SIZE]=" ";     
	
				  if(index!=count)
                		  {
               			      strcat(goodLine,tokenIndex[count]);  // concatnate words exept the word to be delete 
           			      strcat(goodLine," ");                  
		   		      fputs(goodLine,outFile);		    //write the concatneted word on file
                		  }
             			 else  		// else statement save the deleted word in the array list
                    	         {
                                     strcat(badWord,tokenIndex[count]);
                                     strcat(badWord," -> ");
                        	 }
			  count++;
	       }
                                    
      	  }
	}
  
     printf("\nThe Deleted Words :->   %s\n",badWord);		//print the deleted words at the end 
     fclose(inFile);		
     fclose(outFile);
     return 0;
 }
