import React from 'react';

function VehicleCard({model, manufacturer, year, fuelType}) {
    const cardStyle = {
        width: "100%", 
padding: "20px", 
border: "1px solid #ccc", 
borderRadius: "10px", 
backgroundColor: "cyan",
textAlign: "center",
margin: "10px", 
    };

    const infoStyle = {
        fontStyle: "Arial, Sans-Serif",
        fontSize: "18px",
        color: "black"
    };

    return (
       <div style={cardStyle}> 
<p style={infoStyle}><strong>Model:</strong> {model}</p> 
<p style={infoStyle}><strong>Manufacturer:</strong> {manufacturer}</p> 
<p style={infoStyle}><strong>Year:</strong> {year}</p> 
<p style={infoStyle}><strong>Fuel Type:</strong> {fuelType}</p> 
</div> 
    );
} 
export default VehicleCard;