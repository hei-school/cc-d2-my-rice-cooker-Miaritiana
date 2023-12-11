import std.stdio;
import std.string;
import std.conv;

struct Content
{
    string name;
    double quantity;
}

struct RiceCooker
{
    double capacity;
    Content content;
    int timer;
    string temperature;
    int cookingDuration;
}

string getName(Content c)
{
    return c.name;
}

double getQuantity(Content c)
{
    return c.quantity;
}

void setName(ref Content c, string newName)
{
    c.name = newName;
}

void setQuantity(ref Content c, double newQuantity)
{
    c.quantity = newQuantity;
}

double getCapacity(RiceCooker rc)
{
    return rc.capacity;
}

void setCapacity(ref RiceCooker rc, double newCapacity)
{
    rc.capacity = newCapacity;
}

Content getContent(RiceCooker rc)
{
    return rc.content;
}

void setContent(ref RiceCooker rc, Content newContent)
{
    while (getQuantity(newContent) > getCapacity(rc))
    {
        stderr.writeln("Out of capacity. Please enter a quantity within capacity: ");
        scanf("%lf", &newContent.quantity);
    }

    rc.content = newContent;
}

void getContentDetails(RiceCooker rc)
{
    writefln("This rice-cooker contains %.2f kg of %s", getQuantity(rc.content), getName(rc.content));
}

int getTimer(RiceCooker rc)
{
    return rc.timer;
}

void setTimer(ref RiceCooker rc, int minute)
{
    rc.timer = minute;
    writeln("Timer is set to ", minute, " minutes");
}

string getTemperature(RiceCooker rc)
{
    return rc.temperature;
}

void setTemperature(ref RiceCooker rc, string setupTemperature)
{
    rc.temperature = setupTemperature;
    writeln("Temperature set to ", setupTemperature);
}

int getCookingDuration(RiceCooker rc)
{
    return rc.cookingDuration;
}

void setCookingDuration(ref RiceCooker rc, int minute)
{
    rc.cookingDuration = minute;
}

void automaticCook(RiceCooker rc)
{
    writeln("Starting automatic cooking...");
    writefln("Cooking duration: %d minutes", getCookingDuration(rc));
    writefln("Temperature: %s", getTemperature(rc));
    writeln("Automatic cooking completed!");
}

void manualCook(RiceCooker rc)
{
    writeln("Starting manual cooking...");
    writefln("Temperature: %s", getTemperature(rc));
    writeln("Manual cooking completed!");
}

int main()
{
    string ingredient;
    double quantity;
    double capacity;

    writeln("Welcome to rice-cooker");
    write("Capacity: ");
    auto capacityInput = readln().strip;
    capacity = to!double(capacityInput);
    writeln("What are you going to cook?");
    write("Ingredient: ");
    ingredient = readln();
    write("Quantity: ");
    auto quantityInput = readln().strip;
    quantity = to!double(quantityInput);

    RiceCooker riceCooker;
    Content contents;
    setCapacity(riceCooker, capacity);
    setName(contents, ingredient);
    setQuantity(contents, quantity);
    setContent(riceCooker, contents);

    int choice;
    writeln("1) Cook now\n2) Cook later");
    write("Enter your choice: ");
    choice = to!int(readln().strip);

    int choiceCook;

    switch (choice)
    {
        case 1:
        {
            writeln("1) Automatic cook\n2) Cook manually");
            write("Enter your choice: ");
            choiceCook = to!int(readln().strip);

            switch (choiceCook)
            {
                case 1:
                {
                    write("Enter cooking duration (minutes): ");
                    int cookingDuration;
                    readf("%d", &cookingDuration);
                    setCookingDuration(riceCooker, cookingDuration);

                    write("Set temperature: ");
                    string temperature;
                    temperature = readln();
                    automaticCook(riceCooker);
                    break;
                }

                case 2:
                {
                    write("Set temperature: ");
                    string temperatureManual;
                    temperatureManual = readln();
                    manualCook(riceCooker);
                    break;
                }

                default:
                    writeln("Invalid choice");
            }
            break;
        }

        case 2:
        {
            int minutes;
            write("How many minutes does it take to start cooking?\nminutes: ");
            readf("%d", &minutes);
            setTimer(riceCooker, minutes);

            writeln("1) Automatic cook\n2) Cook manually");
            write("Enter your choice: ");
            readf("%d", &choiceCook);

            switch (choiceCook)
            {
                case 1:
                {
                    write("Enter cooking duration (minutes): ");
                    int cookingDuration;
                    readf("%d", &cookingDuration);
                    setCookingDuration(riceCooker, cookingDuration);

                    write("Set temperature: ");
                    string temperature;
                    temperature = readln();
                    writeln("Cooking starts at ", minutes, " minutes later");
                    automaticCook(riceCooker);
                    break;
                }

                case 2:
                {
                    write("Set temperature: ");
                    string temperatureManual;
                    temperatureManual = readln();
                    writeln("Cooking starts at ", minutes, " minutes later");
                    manualCook(riceCooker);
                    break;
                }

                default:
                    writeln("Invalid choice");
            }
            break;
        }

        default:
            writeln("Invalid choice");
    }

    return 0;
}
