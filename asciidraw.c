#include <stdio.h>
#include <string.h>
#include <math.h>

//Aiden Sanghyeop Hyun
//260974945






int main(){

	
int xMax;
int yMax;
char command[50];
char newCHAR[5] = "*";
int commandGRID;
int commandCHAR;
int commandEND;


while(commandGRID=!0){	

	scanf("%s",command);




	/*BEGIN*/

	/*set GRID */


	int result;

	char const GRID[10]="GRID";

	char const CHAR[10]="CHAR";

	char const END[10]="END";

	/*list of command (only til grid is set)*/

	commandGRID =  strcmp(command,GRID);

	commandCHAR = strcmp(command,CHAR);

	commandEND = strcmp(command, END);





	/*Invalid command, not CHAR or GRID*/


	char comment[101];
	
	if(commandEND!=0 && commandGRID!=0 && commandCHAR!=0){scanf("%99[^\n]",comment);
		printf("Only CHAR command is allowed before the grid size is set.\n");}

	else if (commandCHAR==0) { 

		scanf("%s",newCHAR);

	} 

	else if (commandGRID==0){ 


		scanf( "%d %d", &xMax, &yMax);

		

		//if(xMax>1000||yMax>1000||yMax<0||xMax<0){
		//printf("Invalid Grid size \n");continue;
		//}else
		break;

	}else if (commandEND == 0){return 0;}	
}

	/*GRID set to x,y*/








/*BODY*/
/*Impliment CIRCLE, RECTANGLE, CHAR, DISPLAY*/
char canvas[yMax+1][xMax+1];
char secondCommand[20];
int oFirst;
int oSecond;
int oThird;
int oFourth;
char comma[2];
char commacopy[2];
char z[2];
char circle[] = "CIRCLE", rectangle[] = "RECTANGLE", line[] = "LINE",changeChar[]= "CHAR", display[]= "DISPLAY";
char grid[]="GRID";
char end[]="END";
int circleCommand,rectangleCommand,lineCommand,gridCommand,charCommand,displayCommand,endCommand;
char newCharacter[3];






//Create canvas
char firstY[10];
char firstC[10];
char firstX[10];
int count;
int x,y;

               

for(int y=0;y<yMax+1;y++){
                
	//printf("after for loop y is %d",y);
	
        for(int x=0;x<xMax+1;x++){

		//printf("%d",x);
		
		sprintf(firstY,"%d",((yMax-y-1)%10));
	
	if (x == 0){
	
		canvas[y][0]= firstY[0];
	}
        else{
		
		canvas[y][x] = ' ';
	}
	
	
	}}	

for(int x =0;x<xMax+2;x++){

	sprintf(firstX,"%d", x%10);
	
	canvas[yMax][x+1] = firstX[0];
}


canvas[yMax][0]=' ';



int yValue;
int xValue;
int radius;
float xpos,ypos,radsqr,xsqr;






while (1==1){

	
	scanf("%s",secondCommand);


	
//list of commands	
circleCommand = strcmp(circle,secondCommand);
rectangleCommand = strcmp(rectangle,secondCommand);
lineCommand = strcmp(line,secondCommand);
displayCommand = strcmp(display,secondCommand);
charCommand = strcmp(changeChar,secondCommand);
gridCommand = strcmp(grid, secondCommand);





//End command; program ends
endCommand = strcmp(end,secondCommand);
if (endCommand == 0){return 0;}








//Circle command
if (circleCommand == 0){


	scanf(" %d,%d %d",&oFirst,&oSecond,&radius);




	float b;

	float a;

	int xPosition;

	int yPosition;

	int nyPosition;

	int xCentre=oFirst;

	int yCentre=oSecond;

	float aPow2;

	float bSqrt;

	float rPow2;




	//method


	//using the Pythagorean theorem

	//r = radius, a = base, b = altitude

	//r^2 = a^2+b^2 <-> b^2= r^2-a^2

	//Loop a from Centre-radius to Centre + radius

	//horizonatally

	//calculate b with constant r, and plot a,b and a,-b 


	for (a=radius;a>0-radius;a-=0.001){
   

	     	aPow2= pow(a,2);
   

	     	rPow2= pow(radius,2);
 

	     	b=sqrt(rPow2-aPow2);


	     	xPosition = xCentre+rintf(a);


	     	yPosition= yCentre+rintf(b);	


	     	nyPosition= yCentre-rintf(b);


	
   //check (x,y) values are within the grid
   if(xPosition<xMax-2 && yPosition < yMax+1 && xPosition>-1 && yPosition>-1){
		
		//plot
		canvas[yMax-yPosition-1][xPosition+1] = newCHAR[0];
    
	

	}

   if(xPosition<xMax-2 && xPosition>-1 && nyPosition < yMax+1 && nyPosition >-1){


	   canvas[yMax-nyPosition-1][xPosition+1] = newCHAR[0];}
	

        }



//Rectangle command
}else if(rectangleCommand == 0){

	scanf(" %d,%d %d,%d",&oFirst,&oSecond,&oThird,&oFourth);


	int xPosition;

	int yPosition;

	int leftMax= oFirst;

	int topMax= oSecond;

	int rightMax = oThird;

	int bottomMax = oFourth;

	int width = leftMax-rightMax;

	int height = topMax- bottomMax;



	//topleft, bottomright value invalid

	if(topMax<=bottomMax || leftMax>=rightMax ){

		continue;

	}


	//width

	for(int i=leftMax; i<rightMax+1; i++){


		xPosition= i;

		yPosition= topMax;


		if(xPosition<xMax-2 && yPosition < yMax+1 && xPosition>-1 && yPosition>-1){

			canvas[yMax-yPosition-1][xPosition+1] = newCHAR[0];

		}


		yPosition = bottomMax;


		if(xPosition<xMax-2 && yPosition < yMax+1 && xPosition>-1 && yPosition>-1){

			canvas[yMax-yPosition-1][xPosition+1] = newCHAR[0];}

	        }



	//height

	for(int i=bottomMax;i<topMax+1;i++){

		yPosition = i;

		xPosition = leftMax;


		if(xPosition<xMax-2 && yPosition < yMax+1 && xPosition>-1 && yPosition>-1){

			canvas[yMax-yPosition-1][xPosition+1] = newCHAR[0];}


		xPosition = rightMax;


		if(xPosition<xMax-2 && yPosition < yMax+1 && xPosition>-1 && yPosition>-1){

			canvas[yMax-yPosition-1][xPosition+1] = newCHAR[0];}

	
	         }






//Line command
}else if(lineCommand == 0){
	

	scanf(" %d,%d %d,%d",&oFirst,&oSecond,&oThird,&oFourth);




	int y2a,x2a;

	int xPosition;

	int yPosition;

	int x1 = oFirst;

	int x2 = oThird;

	int y1 = oSecond;

	int y2 = oFourth;



	float m;
	
	float y;


//plot two locations	
xPosition =x1; 
yPosition =y1;

 if(xPosition<xMax-2 && yPosition < yMax+1 && xPosition>-1 && yPosition>-1){

                        canvas[yMax-yPosition-1][xPosition+1] = newCHAR[0];}

xPosition =x2;
yPosition =y2;

 if(xPosition<xMax-2 && yPosition < yMax+1 && xPosition>-1 && yPosition>-1){

                        canvas[yMax-yPosition-1][xPosition+1] = newCHAR[0];}


//connect  
if(x1>x2){
                x2a = x1;

                x1=x2;

                x2=x2a;

                y2a=y1;

                y1=y2;

                y2=y2a;


        }
 
        int cos = x2-x1;

        int sin = y2-y1;


	if(cos!=0){
        m= (float)sin/(float)cos;}

	for (float i=0;i<cos;i+=0.005){
	
		yPosition = rint(y1+(m*i));
		xPosition = rint(x1+i);

		
/*printf("\n");
printf("sin is %d",sin);
printf("cos is %d", cos);
printf("m is %.3f\n",m);
printf("y1: %d\n",y1);
printf("y2: %d\n",y2);
printf("x1: %d\n",x1);
printf("x2: %d\n",x2);
printf("i is equal to %.3f\n",i);
printf("yPosition is %d\n",yPosition);
printf("xPosition is %d\n\n",xPosition);		
*/
	    if(xPosition<xMax-2 && yPosition < yMax+1 && xPosition>-1 && yPosition>-1){

                        canvas[yMax-yPosition-1][xPosition+1] = newCHAR[0];}
	}


//horizontal line
	if(cos == 0){
	for (int i=0; i<sin; i+=1){
	xPosition = x1;

	if(y1>y2){

		yPosition =y2+i;

	}else if (y2>y1){
	
		yPosition =y1+i;
	}else{
	
		continue;}	
  
	if(xPosition<xMax-2 && yPosition < yMax+1 && xPosition>-1 && yPosition>-1){

                        canvas[yMax-yPosition-1][xPosition+1] = newCHAR[0];}
	
	}}


	




//Display command
}else if (displayCommand == 0){
 
	for(y=0;y<yMax+1;y++)
		{ 
		for(x=0;x<xMax+1;x++)
			putchar(canvas[y][x]);

                        putchar('\n');}
	


 
 
 
 
//Char command
}else if (charCommand == 0){

	scanf("%2s", newCHAR );
	


	
	
	
	
//invalid Grid command	
}else if (gridCommand ==0){


	printf("GRID was already set to %d %d\n",xMax,yMax);}

else{

	char error[101];

	scanf("%99[^\n]",error);

	printf("Error did not understand %s %s\n",secondCommand,error);}
	}
return 0;}
