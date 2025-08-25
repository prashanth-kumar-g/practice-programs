import React from "react"; 
function VehicleCard({ model, manufacturer, year, fuelType }) { 
const cardStyle = { 
width: "200px", 
padding: "20px", 
border: "1px solid #ccc", 
borderRadius: "10px", 
backgroundColor: "#f9f9f9", 
boxShadow: "0 4px 8px rgba(0, 0, 0, 0.1)", 
textAlign: "center", 
fontFamily: "'Arial', sans-serif", 
margin: "10px", 
};  
const infoStyle = { 
fontSize: "14px", 
color: "#555", 
marginBottom: "10px", 
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