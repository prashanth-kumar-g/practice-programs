import React, { useState } from 'react'; 
import './NewsletterSignup.css'; 
const NewsletterSignup = () => { 
const [fullName, setFullName] = useState(''); 
const [email, setEmail] = useState(''); 
const [submitted, setSubmitted] = useState(false); 
const handleSubmit = (e) => { 
e.preventDefault(); 
setSubmitted(true); 
}; 
if (submitted) { 
return <p className="thank-you">Thank you for signing up, {fullName}!</p>; 
} 
return ( 
<form className="newsletter-form" onSubmit={handleSubmit}> 
<h2>Sign Up for Our Newsletter</h2> 
<label> 
Full Name: 
<input 
type="text" value={fullName} required 
onChange={(e) => setFullName(e.target.value)}  
/> 
</label> 
<label> 
Email Address: 
<input 
type="email" value={email} required 
onChange={(e) => setEmail(e.target.value)}     
/> 
</label> 
<button type="submit">Subscribe</button> 
</form> 
); 
}; 
export default NewsletterSignup; 