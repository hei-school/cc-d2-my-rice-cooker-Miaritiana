#include <iostream>
#include <string>

using namespace std;

class Content
{
private:
    string name;
    double quantity;

public:
    string getName(void)
    {
        return name;
    }

    double getQuantity(void)
    {
        return quantity;
    }

    void setName(string newName)
    {
        name = newName;
    }

    void setQuantity(double newQuantity)
    {
        quantity = newQuantity;
    }
};

class RiceCooker
{
private:
    double capacity;
    Content content;
    int timer;
    char* temperature;
    int cookingDuration;

public:
    double getCapacity(void)
    {
        return capacity;
    }

    void setCapacity(double newCapacity)
    {
        capacity = newCapacity;
    }

    Content getContent(void)
    {
        return content;
    }

    void setContent(Content newContent)
    {
        try
        {
            if (newContent.getQuantity() > getCapacity())
            {
                cerr << "Out of capacity" << endl;
            }
            else
            {
                content = newContent;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void getContentDetails()
    {
        cout << "This rice-cooker contains " << content.getQuantity() << " kg of " << content.getName() << endl;
    }

    int getTimer(void)
    {
        return timer;
    }

    void setTimer(int minute)
    {
        timer = minute;
        cout << "Timer is set to " << minute << " minutes" << endl;
    }

    char* getTemperature(void)
    {
        return temperature;
    }

    void setTemperature(char* setupTemperature)
    {
        temperature = setupTemperature;
        cout << "Temperature set to " << setupTemperature << endl;
    }

    int getCookingDuration(void)
    {
        return cookingDuration;
    }

    void setCookingDuration(int minute)
    {
        cookingDuration = minute;
    }

    void automaticCook()
    {
        cout << "Starting automatic cooking..." << endl;
        cout << "Cooking duration: " << getCookingDuration() << " minutes" << endl;
        cout << "Temperature: " << getTemperature() << endl;
        cout << "Automatic cooking completed!" << endl;
    }

    void manualCook()
    {
        cout << "Starting manual cooking..." << endl;
        cout << "Temperature: " << getTemperature() << endl;
        cout << "Manual cooking completed!" << endl;
    }
};

int main()
{
    string ingredient;
    double quantity;

    cout << "Welcome to rice-cooker" << endl;
    cout << "What are you going to cook ?" << endl;
    cout << "Ingredient: ";
    cin >> ingredient;
    cout << "Quantity: ";
    cin >> quantity;

    RiceCooker riceCooker;
    Content contents;
    contents.setName(ingredient);
    contents.setQuantity(quantity);
    riceCooker.setContent(contents);

    int choice;
    cout << "1) Cook now \n"
            "2) Cook later"
        << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    int choiceCook;
    case 1:
        cout << "1) Automatic cook \n"
             "2) Cook manually \n"
             "Enter your choice: ";
        cin >> choiceCook;

        switch (choiceCook)
        {
        case 1:
            cout << "Enter cooking duration (minutes): ";
            int cookingDuration;
            cin >> cookingDuration;
            riceCooker.setCookingDuration(cookingDuration);

            cout << "Set temperature: ";
            char temperature[50];
            cin >> temperature;
            riceCooker.setTemperature(temperature);

            riceCooker.automaticCook();
            break;

        case 2:
            cout << "Set temperature: ";
            char temperatureManual[50];
            cin >> temperatureManual;
            riceCooker.setTemperature(temperatureManual);

            riceCooker.manualCook();
            break;

        default:
            cout << "Invalid choice" << endl;
        }
        break;

    case 2:
        int minutes;
        cout << "How minutes does it take to start cooking ?" << endl;
        cout << "minutes: " ;
        cin >> minutes;
        riceCooker.setTimer(minutes);

        cout << "1) Automatic cook \n"
             "2) Cook manually \n"
             "Enter your choice: ";
        cin >> choiceCook;

        switch (choiceCook)
        {
        case 1:
            cout << "Enter cooking duration (minutes): ";
            int cookingDuration;
            cin >> cookingDuration;
            riceCooker.setCookingDuration(cookingDuration);

            cout << "Set temperature: ";
            char temperature[50];
            cin >> temperature;
            riceCooker.setTemperature(temperature);
            cout << "Cooking start at " << minutes << " later" << endl;
            riceCooker.automaticCook();
            break;

        case 2:
            cout << "Set temperature: ";
            char temperatureManual[50];
            cin >> temperatureManual;
            riceCooker.setTemperature(temperatureManual);
            cout << "Cooking start at " << minutes << " later" << endl;
            riceCooker.manualCook();
            break;

        default:
            cout << "Invalid choice" << endl;
        }
        break;

        break;

    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}
