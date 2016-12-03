#Adventure Time
A text-based adventure game!

Delegation Idea:

Main function {
-includes the actual storyline and calls the functions from the header file(s)
-Jake Moody
-Sarah Lumley
}

Character class {
-Caleb Robey
-Michael Samper
}

Inventory, Item, and Store Classes {
-Annie Gormaley
-Tyler Tucker
}

Wildcard {
-Andrew Etter (because we haven't been able to contact him yet)
}

Item Class {
-Parent class "Item" extended by classes "Weapon" and "Potion"

-Item has member variables: type, cost, worth, name
  -Type (string): either "Weapon" or "Potion"
  -Cost (int): How much currency it takes to purchase the item from the store
  -Worth (int): How much money the store will give the player for an item (set to 60% of the original price)
  -Name (string): The name of the actual item
-Item has member functions: setName, setCost, getName, getType, getCost, getWorth
  -setName (void): accepts a string to set the name of an item
  -setCost (void): accepts an int to set the cost of an item
  -getName (string): returns the name of an item
  -getType (string): returns the type of an item
  -getCost (int): returns the cost of an item
  -getWorth (int): returns the worth of an item

-Weapon has exclusive member variable: damage
  -Damage (int): how much damage a weapon does
-Weapon has member functions: setDamage, getDamage
  -setDamage (void): accepts an int to set the damage of a Weapon
  -getDamage (int): returns the damage of a Weapon

-Potion has exclusive member variable: healing
  -Healing (int): how much healing a potion does
-Potion has member functions: setHealing, getHealing
  -setHealing (void): accepts an int to set the healing of a Potion
  -getHealing (int): returns the healing capacity of a Potion
  }
