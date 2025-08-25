//import './App.css';
//import CountryList from './Country';
//import RestaurantList from './Restaurant';
//import Welcome from "./example1";
//import Counter from "./Counter";
import VehicleCard from "./VehicleCard";

function App() {
 
const vehicles = [ 
{ model: "Tesla Model S", manufacturer: "Tesla", year: 2022, fuelType: "Electric" }, 
{ model: "Ford Mustang", manufacturer: "Ford", year: 2021, fuelType: "Gasoline" }, 
{ model: "Chevrolet Bolt", manufacturer: "Chevrolet", year: 2022, fuelType: "Electric" }, 
{ model: "BMW 3 Series", manufacturer: "BMW", year: 2021, fuelType: "Diesel" }, 
{ model: "Audi A6", manufacturer: "Audi", year: 2023, fuelType: "Hybrid" } 
];

const headerStyle = {
    textAlign: "center",
    padding: "20px",
    fontFamily: "'Arial', sans-serif",
    fontSize: "24px",
    color: "#333"
};

const containerStyle = { 
display: "flex", 
flexWrap: "wrap", 
justifyContent: "space-around", 
padding: "20px"
}; 

return ( 
<div>
      <h3 style={headerStyle}>Vehicle Information</h3>
      <div style={containerStyle}>
        {vehicles.map((vehicle, index) => (
          <VehicleCard
            key={index}
            model={vehicle.model}
            manufacturer={vehicle.manufacturer}
            year={vehicle.year}
            fuelType={vehicle.fuelType}
          />
        ))}
      </div>
    </div> 
); 
}

export default App;
