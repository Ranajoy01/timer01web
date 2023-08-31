int ldr=A0;
int ldr1=A1;
int ldr2=A2;
int ldr3=A3;
int prev=0,curr=0,c=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   int datau=analogRead(ldr);
   int datar=analogRead(ldr2);
   int datal=analogRead(ldr1);
  int datad=analogRead(ldr3);
 //  datau<400&&datar<400&&datal<400&&datad<400)||
//||(datau>=400&&datad>=400
   if((datau<400&&datar<400&&datal<400&&datad<400)||(datau>=400&&datad>=400)){
     prev=0;
     curr=0;
   
    
   }
    else if(datal>=400){
    curr=3;
    if(curr==prev){
      curr=0;
    
    
    }
  
   }
    else if(datar>=400){
    curr=4;
    if(curr==prev){
      curr=0;
    
    
    }
   
   }
  else if(datau>=400&&datad<400){

    curr=1;
    if(curr==prev||prev==3||prev==4){
      curr=0;
    
    
    }
     
   }
   else if(datad>=400&&datau<400){
    curr=2;
    if(curr==prev||prev==3||prev==4){
      curr=0;
       
    }
   }
  
   if(curr!=0) 
   prev=curr;
   

   Serial.println(curr);

   
   Serial.write(curr);
   Serial.flush();
   delay(1000);
}
