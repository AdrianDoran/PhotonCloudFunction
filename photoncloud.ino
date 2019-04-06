// Cloud signal with HTML Page

// Declare LEDs
int rLed = D5;
int gLed = D6;
int bLed = D3;

int read_page(String command);

void setup()
{
    // Initialise LEDs
    pinMode(rLed, OUTPUT);
    pinMode(gLed, OUTPUT);
    pinMode(bLed, OUTPUT);
    
    // Initialise Cloud Function
    Particle.function("led", read_page);
}

void loop()
{
    // Infinity Loop while device is on.
}

// this function automagically gets called upon a matching POST request
int read_page(String command)
{
    if(command == "red" || command == "green" || command == "blue")
    {
        if (command == "red")
        {
            digitalWrite(rLed, HIGH);
        }
        else
        {
            digitalWrite(rLed, LOW);
        }
        if (command == "green")
        {
            digitalWrite(gLed, HIGH);
        }
        else
        {
            digitalWrite(gLed, LOW);
        }
        if (command == "blue")
        {
            digitalWrite(bLed, HIGH);
        }
        else
        {
            digitalWrite(bLed, LOW);
        }
        
        return 1;
    }
    else if (command == "")
    {
        digitalWrite(rLed, LOW);
        digitalWrite(gLed, LOW);
        digitalWrite(bLed, LOW);
    }
    else return -1;
}