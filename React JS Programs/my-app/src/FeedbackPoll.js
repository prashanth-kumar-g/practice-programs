import React, { useState } from 'react'; 
import './FeedbackPoll.css'; 

const FeedbackPoll = () => { 
const [feedback, setFeedback] = useState(''); 
const handleClick = (choice) => { 
setFeedback(choice); 
}; 
if (feedback) { 
return ( 
<div className="poll-container"> 
<p className="thank-you"> 
Thank you for your feedback! You rated us: <strong>{feedback}</strong> 
</p> 
</div> 
); 
} 
return ( 
<div className="poll-container"> 
<h2>How would you rate our tech support?</h2> 
<div className="button-group"> 
<button onClick={() => handleClick('Good')}>Good</button> 
<button onClick={() => handleClick('Neutral')}>Neutral</button> 
<button onClick={() => handleClick('Poor')}>Poor</button> 
</div> 
</div> 
); 
}; 
export default FeedbackPoll; 