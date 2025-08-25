import React from 'react'; 
import './LandmarkGrid.css'; 
const landmarks = [ 
{ name: 'Eiffel Tower', location: 'Paris', country: 'France' }, 
{ name: 'Statue of Liberty', location: 'New York City', country: 'USA' }, 
{ name: 'Great Wall', location: 'Beijing', country: 'China' }, 
{ name: 'Taj Mahal', location: 'Agra', country: 'India' }, 
{ name: 'Colosseum', location: 'Rome', country: 'Italy' }, 
{ name: 'Christ the Redeemer', location: 'Rio de Janeiro', country: 'Brazil' } 
]; 
const LandmarkGrid = () => { 
return ( 
<div className="grid-container"> 
{landmarks.map((landmark, index) => ( 
<div className="grid-item" key={index}> 
<h3>{landmark.name}</h3> <br/>
<p>{landmark.location}</p> <br/>
<p>{landmark.country}</p> 
</div> 
))} 
</div> 
); 
}; 
export default LandmarkGrid;