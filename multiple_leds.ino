void setup ()  
{  
pinMode ( 11, OUTPUT);  //set the OUTPUT mode of pin to number 13.  
pinMode ( 5, OUTPUT);  // set the OUTPUT mode of pin to number 7.  
}  
void loop ()  
{  
digitalWrite (11, HIGH);  
delay(1000);// blinks for 1 second
digitalWrite (5, LOW);   
delay(1000);  
digitalWrite (11, LOW); // turns led off 
delay(1000); 
digitalWrite (5, HIGH);  
delay(1000);   
}  
