import React, { Component } from "react"; 
class RestaurantList extends Component { 
  render() { 
    const restaurants = [ 
      { 
        id: 1, name: "Pizza Place", 
        menu: [{ id: 1, item: "Margherita" },{ id: 2, item: "Pepperoni" }, 
          { id: 3, item: "BBQ Chicken" },{ id: 4, item: "Vegetarian" }, ], 
      }, 
      { 
        id: 2, name: "Sushi Bar", 
        menu: [{ id: 1, item: "California Roll" },{ id: 2, item: "Tuna Sashimi" }, 
          { id: 3, item: "Tempura" },{ id: 4, item: "Miso Soup" },], 
      }, 
      { 
        id: 3, name: "Burger Joint", 
        menu: [{ id: 1, item: "Cheeseburger" },{ id: 2, item: "Bacon Burger" }, 
          { id: 3, item: "Veggie Burger" },{ id: 4, item: "Fries" },], 
      }, 
    ]; 
    return ( 
      <div className="restaurant-list"> 
        <h2>Restaurant Menu List</h2> 
        <ul> 
          {restaurants.map((restaurant) => ( 
            <li key={restaurant.id}> 
              <h3>{restaurant.name}</h3> 
              <ul> 
                {restaurant.menu.map((menuItem) => ( 
                  <li key={menuItem.id}>{menuItem.item}</li> 
                ))} 
              </ul> 
            </li> 
          ))} 
        </ul> 
      </div> 
    ); } 
} 
export default RestaurantList;