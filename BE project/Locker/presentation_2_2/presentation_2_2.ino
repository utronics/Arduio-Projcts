#include <GSM.h>

#define PINNUMBER ""  // initialize the library instance

GSM gsmAccess; // include a 'true' parameter for debug enabled
GSM_SMS sms;

// char array of the telephone number to send SMS

char remoteNumber[20]= "+919714548574";  
char txtMsg[200]="Test";

void setup()
{
  Serial.begin(9600);
  Serial.println("SMS Messages Sender");

  boolean notConnected = true;

  // Start GSM shield If your SIM has PIN, pass it as a parameter of begin() in quotes
  while(notConnected)
  {
    if(gsmAccess.begin(PINNUMBER)==GSM_READY)
      notConnected = false;
    else
      {
       Serial.println("Not connected");
       delay(1000);
      }
  }
    Serial.println("GSM initialized");
     sendSMS();
}

void loop()
{
// nothing to see here
}

void sendSMS()
  {
    Serial.print("Message to mobile number: ");
    Serial.println(remoteNumber);

     // sms text
    Serial.println("SENDING");
    Serial.println();
    Serial.println("Message:");
    Serial.println(txtMsg);

      // send the message
    sms.beginSMS(remoteNumber);
    sms.print(txtMsg);
    sms.endSMS(); 
    Serial.println("\nCOMPLETE!\n");  
  }
