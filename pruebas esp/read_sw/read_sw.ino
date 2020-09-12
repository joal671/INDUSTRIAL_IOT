#define SW  D8
#define LED D0

///////////////////////
 
#define D0   16 //GPIO16 - WAKE UP
#define D1   5  //GPIO5
#define D2   4  //GPIO4
#define D3   0  //GPIO0
#define D4   2  //GPIO2 - TXD1

#define D5   14 //GPIO14 - HSCLK
#define D6   12 //GPIO12 - HMISO
#define D7   13 //GPIO13 - HMOSI - RXD2
#define D8   15 //GPIO15 - HCS   - TXD2
#define RX   3  //GPIO3 - RXD0 
#define TX   1  //GPIO1 - TXD0
///////////////////////////
int read_sw(void);

void setup(){
    Serial.begin(9600);
    pinMode(SW,INPUT);
    //pinMode(LED,OUTPUT);
    
}
void loop(){
    int a;
    a = read_sw();
    Serial.println(a);
}

int read_sw(void){
    int time=0;
    while(digitalRead(SW) == 0){}

    delayMicroseconds(3);
    if(digitalRead(SW) == 1){
        while(digitalRead(SW) == 1){
            time ++;
            delayMicroseconds(1);
        }
        return time/1000;
    }
    else
       return 0;
}
