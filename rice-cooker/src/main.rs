use std::io::{self, Write};

struct Content {
    name: String,
    quantity: f64,
}

struct RiceCooker {
    capacity: f64,
    content: Content,
    timer: i32,
    temperature: String,
    cooking_duration: i32,
}

fn get_name(c: &Content) -> &str {
    &c.name
}

fn get_quantity(c: &Content) -> f64 {
    c.quantity
}

fn set_name(c: &mut Content, new_name: &str) {
    c.name = String::from(new_name);
}

fn set_quantity(c: &mut Content, new_quantity: f64) {
    c.quantity = new_quantity;
}

fn get_capacity(rc: &RiceCooker) -> f64 {
    rc.capacity
}

fn set_capacity(rc: &mut RiceCooker, new_capacity: f64) {
    rc.capacity = new_capacity;
}

fn get_content(rc: &RiceCooker) -> &Content {
    &rc.content
}

fn set_content(rc: &mut RiceCooker, mut new_content: Content) {
    while new_content.quantity > get_capacity(rc) {
        eprintln!("Out of capacity. Please enter a quantity within capacity: ");
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        let new_quantity: f64 = input.trim().parse().expect("Invalid input");
        new_content.quantity = new_quantity;
    }

    rc.content = new_content;
}

fn get_content_details(rc: &RiceCooker) {
    println!(
        "This rice-cooker contains {:.2} kg of {}",
        get_quantity(&rc.content),
        get_name(&rc.content)
    );
}

fn get_timer(rc: &RiceCooker) -> i32 {
    rc.timer
}

fn set_timer(rc: &mut RiceCooker, minute: i32) {
    rc.timer = minute;
    println!("Timer is set to {} minutes", minute);
}

fn get_temperature(rc: &RiceCooker) -> &str {
    &rc.temperature
}

fn set_temperature(rc: &mut RiceCooker, setup_temperature: &str) {
    rc.temperature = String::from(setup_temperature);
    println!("Temperature set to {}", setup_temperature);
}

fn get_cooking_duration(rc: &RiceCooker) -> i32 {
    rc.cooking_duration
}

fn set_cooking_duration(rc: &mut RiceCooker, minute: i32) {
    rc.cooking_duration = minute;
}

fn automatic_cook(rc: &RiceCooker) {
    println!("Starting automatic cooking...");
    println!("Cooking duration: {} minutes", get_cooking_duration(rc));
    println!("Temperature: {}", get_temperature(rc));
    println!("Automatic cooking completed!");
}

fn manual_cook(rc: &RiceCooker) {
    println!("Starting manual cooking...");
    println!("Temperature: {}", get_temperature(rc));
    println!("Manual cooking completed!");
}

fn main() {
    let mut input = String::new();

    print!("Welcome to rice-cooker\nCapacity: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let capacity: f64 = input.trim().parse().expect("Invalid input");
    input.clear();

    print!("What are you going to cook?\nIngredient: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let ingredient = input.trim().to_string();
    input.clear();

    print!("Quantity: ");
    io::stdout().flush().unwrap();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let quantity: f64 = input.trim().parse().expect("Invalid input");

    let mut rice_cooker = RiceCooker {
        capacity,
        content: Content {
            name: ingredient,
            quantity,
        },
        timer: 0,
        temperature: String::new(),
        cooking_duration: 0,
    };

    let choice: i32;
    print!(
        "1) Cook now \n2) Cook later\nEnter your choice: "
    );
    io::stdout().flush().unwrap();
    input.clear();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    choice = input.trim().parse().expect("Invalid input");

    match choice {
        1 => {
            let choice_cook: i32;
            print!(
                "1) Automatic cook \n2) Cook manually \nEnter your choice: "
            );
            io::stdout().flush().unwrap();
            input.clear();
            io::stdin().read_line(&mut input).expect("Failed to read input");
            choice_cook = input.trim().parse().expect("Invalid input");

            match choice_cook {
                1 => {
                    print!("Enter cooking duration (minutes): ");
                    io::stdout().flush().unwrap();
                    input.clear();
                    io::stdin().read_line(&mut input).expect("Failed to read input");
                    let cooking_duration: i32 = input.trim().parse().expect("Invalid input");
                    set_cooking_duration(&mut rice_cooker, cooking_duration);

                    print!("Set temperature: ");
                    io::stdout().flush().unwrap();
                    input.clear();
                    io::stdin().read_line(&mut input).expect("Failed to read input");
                    let temperature = input.trim().to_string();
                    set_temperature(&mut rice_cooker, &temperature);

                    automatic_cook(&rice_cooker);
                }
                2 => {
                    print!("Set temperature: ");
                    io::stdout().flush().unwrap();
                    input.clear();
                    io::stdin().read_line(&mut input).expect("Failed to read input");
                    let temperature_manual = input.trim().to_string();
                    set_temperature(&mut rice_cooker, &temperature_manual);

                    manual_cook(&rice_cooker);
                }
                _ => println!("Invalid choice"),
            }
        }
        2 => {
            let minutes: i32;
            print!("How many minutes does it take to start cooking?\nminutes: ");
            io::stdout().flush().unwrap();
            input.clear();
            io::stdin().read_line(&mut input).expect("Failed to read input");
            minutes = input.trim().parse().expect("Invalid input");
            set_timer(&mut rice_cooker, minutes);

            let choice_cook: i32;
            print!(
                "1) Automatic cook \n2) Cook manually \nEnter your choice: "
            );
            io::stdout().flush().unwrap();
            input.clear();
            io::stdin().read_line(&mut input).expect("Failed to read input");
            choice_cook = input.trim().parse().expect("Invalid input");

            match choice_cook {
                1 => {
                    print!("Enter cooking duration (minutes): ");
                    io::stdout().flush().unwrap();
                    input.clear();
                    io::stdin().read_line(&mut input).expect("Failed to read input");
                    let cooking_duration: i32 = input.trim().parse().expect("Invalid input");
                    set_cooking_duration(&mut rice_cooker, cooking_duration);

                    print!("Set temperature: ");
                    io::stdout().flush().unwrap();
                    input.clear();
                    io::stdin().read_line(&mut input).expect("Failed to read input");
                    let temperature = input.trim().to_string();
                    println!("Cooking starts at {} minutes later", minutes);
                    set_temperature(&mut rice_cooker, &temperature);

                    automatic_cook(&rice_cooker);
                }
                2 => {
                    print!("Set temperature: ");
                    io::stdout().flush().unwrap();
                    input.clear();
                    io::stdin().read_line(&mut input).expect("Failed to read input");
                    let temperature_manual = input.trim().to_string();
                    println!("Cooking starts at {} minutes later", minutes);
                    set_temperature(&mut rice_cooker, &temperature_manual);

                    manual_cook(&rice_cooker);
                }
                _ => println!("Invalid choice"),
            }
        }
        _ => println!("Invalid choice"),
    }
}

