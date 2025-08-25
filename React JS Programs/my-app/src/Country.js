import React from "react"; 
import './Country.css';  
function CountryList() { 
  const countries = [ 
    { name: "India", capital: "New Delhi" }, { name: "United States", capital: "Washington, D.C." }, { name: "Canada", capital: "Ottawa" }, { name: "Germany", capital: "Berlin" }, 
    { name: "Australia", capital: "Canberra" }, { name: "Japan", capital: "Tokyo" }, 
  ]; 
  return ( 
    <div className="country-list-container"> 
      <h2>Countries and Their Capitals</h2> 
      <ul className="country-list"> 
        {countries.map((country, index) => ( 
          <li key={index} className="country-item"> 
            <strong>{country.name}</strong>: {country.capital} 
          </li> 
        ))} 
      </ul> 
    </div> 
  ); 
} 
export default CountryList; 