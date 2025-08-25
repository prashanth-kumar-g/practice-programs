import React, {Component} from 'react';

class RestaurantList extends Component {
    render() {
        const restaurants = [
            {id: 1, name: "Fruits", menu: [{id: 1, item: "Apple"}, {id: 2, item: "Orange"}, {id: 3, item: "Banana"}]},
            {id: 2, name: "Vegetables", menu: [{id: 1, item: "Potato"}, {id: 2, item: "Tomato"}, {id: 3, item: "Carrot"}]},
            {id: 3, name: "Fast Food", menu: [{id: 1, item: "Samosa"}, {id: 2, item: "Vada"}, {id: 3, item: "Pani Puri"}]}
        ];

        return (
            <div className="container">
                <h3>Restaurant Menu List</h3>
                <ul>
                    {restaurants.map((restaurant) => (
                        <li key={restaurant.id}>
                            <h3>{restaurant.name}</h3>
                            <ul>
                                {restaurant.menu.map((menuItem) => (
                                    <li key={menuItem.id}>
                                        {menuItem.item}
                                    </li>
                                ))}
                            </ul>
                        </li>
                    ))}
                </ul>
            </div>
        );
    }
}

export default RestaurantList;