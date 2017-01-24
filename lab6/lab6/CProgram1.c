/*
C Program for AVR Microcontroller Based Electronic Voting Machine

#include <avr/io.h> //header to enable data flow control over pins
#define F_CPU 1000000 //telling controller crystal frequency attached
#include <util/delay.h> //header to enable delay function in program
#define    E   5 //giving name “enable”  to 5th pin of PORTD, since it Is connected to LCD enable pin
#define RS  6 //giving name “registerselection” to 6th pin of PORTD, since is connected to LCD RS pin
 
void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
int main(void)
{
    DDRA = 0xFF; //putting porta and port d as output pins
    DDRD = 0xFF;
    _delay_ms(50); //giving delay of 50ms
    DDRB = 0; //Taking portB as input.
                            
    int16_t COUNTA = 0; // person1 votes storing memory
    char SHOWA [16]; // person1 votes displaying character on LCD
    int16_t COUNTB = 0;  // person2 votes storing memory
    char SHOWB [16]; // person2 votes displaying character on LCD
    int16_t COUNTC = 0; // person3 votes storing memory
    char SHOWC [16]; // person3 votes displaying character on LCD
    int16_t COUNTD = 0; // person4 votes storing memory
    char SHOWD [16]; //person4 votes displaying character on LCD
 
    send_a_command(0x01);  //Clear Screen 0x01 = 00000001
    _delay_ms(50);
    send_a_command(0x38); //telling lcd we are using 8bit command /data mode
    _delay_ms(50);
    send_a_command(0b00001111); //LCD SCREEN ON and courser blinking
               
    while(1)
    {
        send_a_string ("A="); // displaying person1 name
        send_a_command(0x80 + 2); // shifting cursor  to 3rd shell
        itoa(COUNTA,SHOWA,10); // command for putting variable number in LCD(variable number, in which character to replace, which base is variable(ten here as we are counting number in base10))
        send_a_string(SHOWA); //telling the display to show character(replaced by variable number) of first person after positioning the courser on LCD.
        send_a_command(0x80 + 8); // shifting cursor  to 9th shell
        send_a_string ("B="); // displaying person2name
        send_a_command(0x80 + 10); //shifting cursor  to 11th shell
        itoa(COUNTB,SHOWB,10); //command for putting variable number in LCD(variable number, in which character to replace, which base is variable(ten here as we are counting number in base10))
        send_a_string(SHOWB);  //telling the display to show character(replaced by variable number) of second person after positioning the courser on LCD.
        send_a_command(0x80 + 0x40 + 0); // shifting cursor  to 1st  shell  of second line
        send_a_string ("C="); // displaying person3 name
        send_a_command(0x80 + 0x40 + 2); //shifting cursor  to 3rd  shell  of second line
        itoa(COUNTC,SHOWC,10);
        send_a_string(SHOWC);
        send_a_command(0x80 + 0x40 + 8); // shifting cursor  to 9th   shell  of second line
        send_a_string ("D="); //displaying person4name
        send_a_command(0x80 + 0x40 + 10); //shifting cursor  to 11th   shell  of second line
        itoa(COUNTD,SHOWD,10);
        send_a_string(SHOWD);
        send_a_command(0x80 + 0); // shifting cursor  to 0th position
        if (bit_is_clear(PINB,0))//when button one  is pressed
        {
            COUNTA++; // increment the vote memory of first person by one
        }
        if (bit_is_clear(PINB,1)) // when button 2  is pressed
        {
            COUNTB++; // increment the vote memory of second person by one
        }
        if (bit_is_clear(PINB,2)) // when button 3  is pressed
        {
            COUNTC++; // increment the vote memory of third person by one
        }
        if (bit_is_clear(PINB,3)) // when button 4  is pressed
        {
            COUNTD++; // increment the vote memory of fourth person by one
        }
        if (bit_is_clear(PINB,4)) // when button 5  is pressed
        {
            COUNTA=COUNTB=COUNTC=COUNTD=0; //clearing vote memory of all persons.
        }
    }               
}    
 
    void send_a_command(unsigned char command)
    {
        PORTA = command;
        PORTD &= ~ (1<<RS); //putting 0 in RS to tell lcd we are sending command
        PORTD |= 1<<E; //telling lcd to receive command /data at the port
        _delay_ms(50);
        PORTD &= ~1<<E; //telling lcd we completed sending data
        PORTA= 0;
    }
 
    void send_a_character(unsigned char character)
    {
        PORTA= character;
        PORTD |= 1<<RS; //telling LCD we are sending data not commands
        PORTD |= 1<<E; //telling LCD to start receiving command/data
        _delay_ms(50);
        PORTD &= ~1<<E; //telling lcd we completed sending data/command
        PORTA = 0;
    }   
*/