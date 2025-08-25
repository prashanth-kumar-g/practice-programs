import React from 'react';
import './Country.css';

function CountryList() {
    const countries = [
        {name: "India", capital: "New Delhi"},
        {name: "America", capital: "Washington D.C"},
        {name: "Russia", capital: "Moscow"},
        {name: "China", capital: "Beijing"},
        {name: "Britain", capital: "London"}
    ];

    return (
        <div className="country-list-container">
            <h3>Countries and their capitals</h3>
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