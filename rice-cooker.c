#include <stdio.h>
#include <string.h>

struct Content
{
    char name[50];
    double quantity;
};

struct RiceCooker
{
    double capacity;
    struct Content content;
    int timer;
    char temperature[50];
    int cookingDuration;
};

char* getName(struct Content* c)
{
    return c->name;
}

double getQuantity(struct Content* c)
{
    return c->quantity;
}

void setName(struct Content* c, const char* newName)
{
    strncpy(c->name, newName, sizeof(c->name));
}

void setQuantity(struct Content* c, double newQuantity)
{
    c->quantity = newQuantity;
}

double getCapacity(struct RiceCooker* rc)
{
    return rc->capacity;
}

void setCapacity(struct RiceCooker* rc, double newCapacity)
{
    rc->capacity = newCapacity;
}

struct Content getContent(struct RiceCooker* rc)
{
    return rc->content;
}

void setContent(struct RiceCooker* rc, struct Content newContent)
{
    while (getQuantity(&newContent) > getCapacity(rc))
    {
        fprintf(stderr, "Out of capacity. Please enter a quantity within capacity: ");
        scanf("%lf", &newContent.quantity);
    }

    rc->content = newContent;
}

void getContentDetails(struct RiceCooker* rc)
{
    printf("This rice-cooker contains %.2f kg of %s\n", getQuantity(&rc->content), getName(&rc->content));
}

int getTimer(struct RiceCooker* rc)
{
    return rc->timer;
}

void setTimer(struct RiceCooker* rc, int minute)
{
    rc->timer = minute;
    printf("Timer is set to %d minutes\n", minute);
}

char* getTemperature(struct RiceCooker* rc)
{
    return rc->temperature;
}

void setTemperature(struct RiceCooker* rc, const char* setupTemperature)
{
    strncpy(rc->temperature, setupTemperature, sizeof(rc->temperature));
    printf("Temperature set to %s\n", setupTemperature);
}

int getCookingDuration(struct RiceCooker* rc)
{
    return rc->cookingDuration;
}

void setCookingDuration(struct RiceCooker* rc, int minute)
{
    rc->cookingDuration = minute;
}

void automaticCook(struct RiceCooker* rc)
{
    printf("Starting automatic cooking...\n");
    printf("Cooking duration: %d minutes\n", getCookingDuration(rc));
    printf("Temperature: %s\n", getTemperature(rc));
    printf("Automatic cooking completed!\n");
}

void manualCook(struct RiceCooker* rc)
{
    printf("Starting manual cooking...\n");
    printf("Temperature: %s\n", getTemperature(rc));
    printf("Manual cooking completed!\n");
}

int main()
{
    char ingredient[50];
    double quantity;
    double capacity;

    printf("Welcome to rice-cooker\n");
    printf("Capacity: ");
    scanf("%lf", &capacity);
    printf("What are you going to cook?\n");
    printf("Ingredient: ");
    scanf("%s", ingredient);
    printf("Quantity: ");
    scanf("%lf", &quantity);

    struct RiceCooker riceCooker;
    struct Content contents;
    setCapacity(&riceCooker, capacity);
    setName(&contents, ingredient);
    setQuantity(&contents, quantity);
    setContent(&riceCooker, contents);

    int choice;
    printf("1) Cook now \n"
           "2) Cook later\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        int choiceCook;
    case 1:
        printf("1) Automatic cook \n"
               "2) Cook manually \n"
               "Enter your choice: ");
        scanf("%d", &choiceCook);

        switch (choiceCook)
        {
            case 1:
            {
                printf("Enter cooking duration (minutes): ");
                int cookingDuration;
                scanf("%d", &cookingDuration);
                setCookingDuration(&riceCooker, cookingDuration);

                printf("Set temperature: ");
                char temperature[50];
                scanf("%s", temperature);
                automaticCook(&riceCooker);
                break;
            }

            case 2:
            {
                printf("Set temperature: ");
                char temperatureManual[50];
                scanf("%s", temperatureManual);
                manualCook(&riceCooker);
                break;
            }

            default:
                printf("Invalid choice\n");
        }
        break;

    case 2:
    {
        int minutes;
        printf("How many minutes does it take to start cooking?\n");
        printf("minutes: ");
        scanf("%d", &minutes);
        setTimer(&riceCooker, minutes);

        printf("1) Automatic cook \n"
               "2) Cook manually \n"
               "Enter your choice: ");
        scanf("%d", &choiceCook);

        switch (choiceCook)
        {
            case 1:
            {
                printf("Enter cooking duration (minutes): ");
                int cookingDuration;
                scanf("%d", &cookingDuration);
                setCookingDuration(&riceCooker, cookingDuration);

                printf("Set temperature: ");
                char temperature[50];
                scanf("%s", temperature);
                printf("Cooking starts at %d minutes later\n", minutes);
                automaticCook(&riceCooker);
                break;
            }

            case 2:
            {
                printf("Set temperature: ");
                char temperatureManual[50];
                scanf("%s", temperatureManual);
                printf("Cooking starts at %d minutes later\n", minutes);
                manualCook(&riceCooker);
                break;
            }

            default:
                printf("Invalid choice\n");
        }
        break;
    }

    default:
        printf("Invalid choice\n");
    }

    return 0;
}
